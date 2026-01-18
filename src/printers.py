__COPYRIGHT__

import gdb
import gdb.printing
import itertools
import re
import os

# in VSCODE terminal
# export FIXPP_GDB_VALUE_IN_NAME=true
VALUE_IN_NAME = os.getenv( "FIXPP_GDB_VALUE_IN_NAME", "false" ) == "true"

# constants
OFFSET = 'offset'
BUF = '_fixPtr'
BUFLEN = '_fixLength'

DATA_FIELDS = { __DATA_FIELDS__ }

if sys.version_info[0] > 2:
    Iterator = object
else:
    class Iterator:
        def next(self):
            return self.__next__()

def soh2str( soh ):
    s = ''
    i = 0
    while True:
        ch = soh[i]
        i = i + 1
        if ch == 1 or ch == 0:
            break
        s = s + chr(ch)
    return s

def getFieldTag( msg, fieldName ):
    buf = msg[BUF]
    offset = msg[fieldName][OFFSET]
    if buf == 0 or offset < 0:
        return ''
    offset = offset - 2
    res = ''
    while offset >= 0 and buf[offset] != 1:
        res = chr(buf[offset]) + res
        offset = offset - 1
    return res

def rawData(soh,sz):
    s = ''
    i = 0
    while i < sz:
        ch = soh[i]
        if ch < 32 or ch > 127:
            s = s + '\\' + oct(ch)
        else:
            s = s + chr(ch)
        i = i + 1
    return s

def getFieldValue( msg, fieldName ):
    buf = msg[BUF]
    offset = msg[fieldName][OFFSET]
    if buf == 0 or offset < 0:
        return ''
    if fieldName in DATA_FIELDS:
        sz = 0
        try:
            sz = int(getFieldValue(msg,fieldName+'Len'))
        except:
            try:
                sz = int(getFieldValue(msg,fieldName+'Length'))
            except:
                sz = 0
        return rawData(buf+offset,sz)
    return soh2str(buf+offset)

def getEnumName( msg, fieldName ):
    buf = msg[BUF]
    offset = msg[fieldName][OFFSET]
    if buf == 0 or offset < 0:
        return ''
    try:
        call = gdb.parse_and_eval( 'fixppGetEnumName' )
        if not call:
            return ''
        else:
            return ' ' + call(buf,offset).string()
    except gdb.error as err:
        return ''

class FloatPrinter:

    def __init__(self, val):
        self.val = val

    def to_string(self):
        res = f"(({self.val.type.name}*){self.val.address})->toString(true).c_str()"
        return gdb.parse_and_eval(res).string()

    def display_hint(self):
        return 'string'

class FieldPrinter:

    def __init__(self, val):
        self.val = val

    def to_string(self):
        return 'offset = ' + str(self.val[OFFSET])

    def display_hint(self):
        return 'string'

class GroupPrinter:

    class _iterator(Iterator):

        def __init__(self, start, finish):
            self.start = start
            self.finish = finish
            self.cur = start
            self.count = 0

        def __iter__(self):
            return self

        def __next__(self):
            if self.cur == self.finish or self.cur[BUF] == 0:
                raise StopIteration
            ret = self.cur.dereference()
            self.cur = self.cur + 1
            count = self.count
            self.count = self.count + 1
            offset = 0
            firstValue = ret[BUF]
            while chr(firstValue[offset]) != '=' and offset < 6:
                offset = offset + 1
            return ( '[%d] %s' % (count,soh2str(firstValue+offset+1)),  ret )

    def __init__(self, val):
        self.val = val

    def children(self):
        return self._iterator( self.val['_M_impl']['_M_start'], self.val['_M_impl']['_M_finish'] )

    def display_hint(self):
        return 'array'


class MessagePrinter:

    class _iterator(Iterator):

        def __init__(self, msg, fields):
            self.msg = msg
            self.fields = fields
            self.count = 0

        def __iter__(self):
            return self

        def __next__(self):
            if self.count == len( self.fields ):
                raise StopIteration
            self.count = self.count + 1
            f = self.fields[ self.count - 1 ]
            if isinstance(f,str) and f.startswith('_'):
                return ( f, self.msg[f] )
            if f.name.startswith('field'):         # f.name = fieldFixName 
                fn = f.name[ 5 : len(f.name) ]     # fn = FixName
                fname = fn + ' ' + getFieldTag( self.msg, f.name ) + ' @ ' + str(self.msg[f.name][OFFSET])
                if VALUE_IN_NAME:
                    return ( fname + ' = ' + getFieldValue( self.msg, f.name ) + getEnumName( self.msg, f.name ), '' )
                else:
                    return ( fname, getFieldValue( self.msg, f.name ) + getEnumName( self.msg, f.name ) )
            if f.name.startswith('groups'):        # f.name = groupsLegs
                fn = f.name[ 6 : len(f.name) ]     # fn = Legs
                no = self.fields[ self.count - 2 ] # no = fieldNoLegs
                noStr = getFieldValue( self.msg, no.name )
                return ( fn + ( '[%s]' % noStr ), self.msg[ f.name ] )
            return ( 'field.' + str(self.count), f ) # should never get here

    def __init__ (self,val):
        self.msg = val
        self.fields = []
        self.fields.append(BUF)
        self.fields.append(BUFLEN)
        if val[BUF] != 0:
            for f in self.msg.type.fields():
                if f.type and f.type.name:
                    if f.type.name.startswith( "DSTNAMESPACE::Field" ) and val[f.name][OFFSET] >= 0:
                        self.fields.append( f )
                    if f.type.name.startswith( "DSTNAMESPACE::Group" ) and val[prev.name][OFFSET] >= 0:
                        self.fields.append( f )
                    prev = f

    def children(self):
        return self._iterator( self.msg, self.fields )


def build_fix_printers():
    pp = gdb.printing.RegexpCollectionPrettyPrinter( "__PRJ_NAME__-__PRJ_BRANCH__" )
    __PRINTERS__
    pp.add_printer( 'DSTNAMESPACE::Field', '^DSTNAMESPACE::Field\<.*\>$', FieldPrinter )
    pp.add_printer( 'DSTNAMESPACE::Float', '^DSTNAMESPACE::Float$', FloatPrinter )
    return pp

gdb.printing.register_pretty_printer( gdb.current_objfile(), build_fix_printers() )
