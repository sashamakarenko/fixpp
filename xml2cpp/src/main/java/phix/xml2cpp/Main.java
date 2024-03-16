package phix.xml2cpp;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.Unmarshaller;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.sax.SAXSource;
import org.xml.sax.InputSource;
import org.xml.sax.XMLReader;
import phix.xml2cpp.model.Component;
import phix.xml2cpp.model.Components;
import phix.xml2cpp.model.Field;
import phix.xml2cpp.model.Fields;
import phix.xml2cpp.model.Fix;
import phix.xml2cpp.model.Group;
import phix.xml2cpp.model.Header;
import phix.xml2cpp.model.Message;
import phix.xml2cpp.model.Messages;
import phix.xml2cpp.model.Value;

public class Main
{
    static List<Field>                         fields        = null;
    static List<Component>                     comps         = null;
    static List<Message>                       messages      = null;

    static HashMap<String,Field>               fieldByName   = new HashMap<>();
    static HashMap<String,Component>           compByName    = new HashMap<>();
    static HashMap<String,Group>               groupByName   = new HashMap<>();
    static HashMap<String,String>              msgTypeById   = new HashMap<>();

    static LinkedHashMap<String,List<Object>>  expComps      = new LinkedHashMap<>();
    static LinkedHashMap<String,List<Object>>  expMessages   = new LinkedHashMap<>();
    static LinkedHashMap<String,List<Object>>  expGroups     = new LinkedHashMap<>();
    static HashSet<String>                     writtenGroups = new HashSet<>();

    public static void main( String args[] )
    {
        if( args.length < 2 || args.length > 3 )
        {
            System.err.println( "usage: " );
            System.err.println( "java -cp xml2cpp-1.0.jar phix.xml2cpp.Main /path/to/FIX44.xml /output/path/to/dir/with/defs" );
            System.err.println( "java -cp xml2cpp-1.0.jar phix.xml2cpp.Main /path/to/FIX50SP2.xml /path/to/FIXT11.xml /output/path/to/dir/with/defs" );
            System.exit(1);
        }
        try
        {
            JAXBContext jaxbContent = JAXBContext.newInstance( "phix.xml2cpp.model" );
            Unmarshaller unmarshaller = jaxbContent.createUnmarshaller();
            SAXParserFactory spf = SAXParserFactory.newInstance();
            spf.setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false );
            spf.setFeature("http://xml.org/sax/features/validation", false );
            XMLReader xmlReader = spf.newSAXParser().getXMLReader();
            SAXSource source = new SAXSource( xmlReader, new InputSource( new FileReader( args[0] ) ) );
            Fix root = (Fix)unmarshaller.unmarshal( source );
            for( Object child : root.getHeaderOrMessagesOrTrailerOrComponentsOrFields() )
            {
                if( child instanceof Fields )
                {
                    fields = ((Fields)child).getField();
                }
                if( child instanceof Components )
                {
                    comps = ((Components)child).getComponent();
                }
                if( child instanceof Messages )
                {
                    messages = ((Messages)child).getMessage();
                }
                if( child instanceof Header )
                {
                    expMessages.put( "Header", ((Header)child).getFieldOrGroup() );
                }
            }

            String destinantionDir = args[1];
            if( args.length == 3 ) // load FIXT11.xml
            {
                destinantionDir = args[2];
                source = new SAXSource( xmlReader, new InputSource( new FileReader( args[1] ) ) );
                root = (Fix)unmarshaller.unmarshal( source );
                for( Object child : root.getHeaderOrMessagesOrTrailerOrComponentsOrFields() )
                {
                    /* We add only messages from FIXT11.xml since all fields and components
                       are suposed to be in  FIX5*.xml.
                    if( child instanceof Fields )
                    {
                        extraFields = ((Fields)child).getField();
                    }
                    if( child instanceof Components )
                    {
                        extraComps = ((Components)child).getComponent();
                    }
                    */
                    int pos = 0;
                    if( child instanceof Messages )
                    {
                        for( Message mnew : ((Messages)child).getMessage() )
                        {
                            Message mToAdd = mnew;
                            for( Message mold : messages )
                            {
                                if( mold.getName().equals( mnew.getName() ) )
                                {
                                    mToAdd = null;
                                    break;
                                }
                            }
                            if( mToAdd != null )
                            {
                                System.out.println( "Adding message " + mToAdd.getName() );
                                messages.add( pos++, mToAdd );
                            }
                        }
                    }
                    if( child instanceof Header )
                    {
                        expMessages.put( "Header", ((Header)child).getFieldOrGroup() );
                    }
                }

            }

            File dir = new File( destinantionDir );
            dir.mkdirs();

            // ----------------------------------------------------------------- fields
            {
            System.out.println( "Writing fields" );

            PrintWriter fieldDef = new PrintWriter( new File( dir, "Fields.def" ) );

            fieldDef.printf( "FIX_FIELD_BEGIN_STRING( FIX.%s.%s )\n\n", root.getMajor(), root.getMinor() );

            for( Field f : fields )
            {
                fieldByName.put( f.getName(), f );
                fieldDef.printf( "FIX_FIELD_DECL( %-30s, %6d, %-14s )\n", f.getName(), Integer.parseInt( f.getNumber() ), f.getType() );
            }

            for( Field f : fields )
            {
                String fname = f.getName();
                for( Field other : fields )
                {
                    if( other != f && other.getName().equals( fname ) )
                    {
                        System.err.println( "Ignoring duplicated field " + fname );
                        continue;
                    }
                }
                List<Value> values = f.getValue();
                if( values == null || values.isEmpty() ) continue;

                fieldDef.printf( "\nFIX_ENUM_BEGIN( %s )\n", f.getName() );
                for( Value v : values )
                {
                    String value = v.getEnum();
                    if( fname.equals( "MsgType" ) )
                    {
                        msgTypeById.put( value, v.getDescription() );
                    }
                    fieldDef.printf( "FIX_ENUM_DECL( %s, %s, %s )\n", f.getName(),
                            ( Character.isDigit( v.getDescription().charAt(0) ) ? "_" : "" ) + v.getDescription(),
                            valueToString(value, f.getType() ) );
                }
                fieldDef.printf( "FIX_ENUM_END\n" );
            }

            fieldDef.close();
            }

            // ----------------------------------------------------------------- expand components
            for( Component c : comps )
            {
                compByName.put( c.getName(), c );
            }

            for( Component c : comps )
            {
                expandComponent( c.getName() );
            }

            // ----------------------------------------------------------------- messages
            {
            System.out.println( "Writing messages" );
            PrintWriter msgDef = new PrintWriter( new File( dir, "Messages.def" ) );
            writeMessage( msgDef, "Header", "_", expMessages.get( "Header" ) );

            for( Message m : messages )
            {
                LinkedList<Object> children = new LinkedList<>();
                for( Object child : m.getFieldOrComponentOrGroup() )
                {
                    if( child instanceof Field )
                    {
                        children.add(child);
                    }
                    else if( child instanceof Group )
                    {
                        children.add(child);
                    }
                    else if( child instanceof Component )
                    {
                        children.addAll( expComps.get( ((Component)child).getName() ) );
                    }
                }

                writeMessage( msgDef, m.getName(), msgTypeById.get( m.getMsgtype() ), children );
            }
            msgDef.close();
            }

            // ----------------------------------------------------------------- groups
            {
            System.out.println( "Writing groups" );
            PrintWriter groupDef = new PrintWriter( new File( dir, "Groups.def" ) );
            for( Group g : groupByName.values() )
            {
                writeGroup( groupDef, g.getName() );
            }
            groupDef.close();
            }
        }
        catch( Exception ex )
        {
            ex.printStackTrace();
        }
    }

    static void writeGroup( PrintWriter groupDef, String name )
    {
        if( writtenGroups.contains( name ) )
        {
            return;
        }
        writtenGroups.add( name );
        Object first = null;
        for( Object child : expandGroup( name ) )
        {
            if( child instanceof Group && ! writtenGroups.contains( ((Group)child).getName() ) )
            {
                writeGroup( groupDef, ((Group)child).getName() );
            }
        }

        for( Object child : expGroups.get( name ) )
        {
            if( first == null )
            {
                first = child;
                String firstName = null;
                if( child instanceof Field )
                {
                    firstName = ((Field)child).getName();
                }
                else if( child instanceof Group )
                {
                    firstName = ((Group)child).getName(); //.substring(2);
                }
                groupDef.printf( "\nFIX_MSG_GROUP_BEGIN( %s, %s )\n", name.substring(2), firstName );
            }
            else
            {
                if( child instanceof Field )
                {
                    groupDef.printf( "FIX_MSG_FIELD( %s )\n", ((Field)child).getName() );
                }
                else if( child instanceof Group )
                {
                    groupDef.printf( "FIX_MSG_GROUP( %s )\n", ((Group)child).getName().substring(2) );
                }
            }
        }
        groupDef.printf( "FIX_MSG_GROUP_END\n" );
    }

    static void writeMessage( PrintWriter msgDef, String name, String type, List<Object> children )
    {
        if( type == null )
        {
            throw new RuntimeException( "Unknown MsgType for " + name );
        }
        msgDef.printf( "\nFIX_MSG_BEGIN( %s, %s )\n", name, type );
        for( Object child : children )
        {
            if( child instanceof Field )
            {
                msgDef.printf( "FIX_MSG_FIELD( %s )\n", ((Field)child).getName() );
            }
            else if( child instanceof Group )
            {
                Group g = (Group)child;
                groupByName.putIfAbsent( g.getName(), g );
                msgDef.printf( "FIX_MSG_GROUP( %s )\n", g.getName().substring(2) );
            }
        }
        msgDef.printf( "FIX_MSG_END\n" );
    }

    static List<Object> expandComponent( String name )
    {
        List<Object> expanded = expComps.get( name );
        if( expanded != null ) return expanded;

        expanded = new LinkedList<>();
        expComps.put( name, expanded );
        Component comp = compByName.get(name);
        for( Object child : comp.getFieldOrComponentOrGroup() )
        {
            if( child instanceof Field )
            {
                expanded.add(child);
            }
            else if( child instanceof Group )
            {
                Group g = (Group)child;
                groupByName.putIfAbsent( g.getName(), g );
                expanded.add(child);
            }
            else if( child instanceof Component )
            {
                expanded.addAll( expandComponent( ((Component)child).getName() ) );
            }
        }
        return expanded;
    }

    static List<Object> expandGroup( String name )
    {
        List<Object> expanded = expGroups.get( name );
        if( expanded != null ) return expanded;

        expanded = new LinkedList<>();
        expGroups.put( name, expanded );
        Group group = groupByName.get(name);
        if( group == null )
        {
            System.out.println( "Unknown group " + name );
            System.exit(1);
        }
        for( Object child : group.getFieldOrComponent() )
        {
            if( child instanceof Field )
            {
                expanded.add(child);
            }
            else if( child instanceof Component )
            {
                expanded.addAll( expandComponent( ((Component)child).getName() ) );
            }
        }
        return expanded;
    }

    static String valueToString( String value, String type )
    {
        switch( type )
        {
            case "CHAR":
            case "BOOLEAN":
                return "'" + value + "'";

            case "INT":
            case "NUMINGROUP":
                return value;

            default:
                return "SOHSTR(" + value + ")";
        }
    }
}
