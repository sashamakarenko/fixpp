# XML to CPP converter

Given [Quickfix](https://github.com/quickfix/quickfix) XML files available it generates `Fields.def`, `Groups.def` and `Messages.def`.

## Build it

```shell
$> mvn install
```

## Generate FIX 4.* definitions

```shell
$> java -cp target/xml2cpp-1.0.jar phix.xml2cpp.Main /path/toFIX44.xml /path/to/dir/with/defs
```

Example:
```shell
$> java -cp target/xml2cpp-1.0.jar phix.xml2cpp.Main ../spec/FIX44.xml ../examples/spec/fix44
```

## Generate FIX 5.* definitions

```shell
$> java -cp target/xml2cpp-1.0.jar phix.xml2cpp.Main /path/toFIX50SP2.xml /path/to/FIXT11.xml /path/to/dir/with/defs
```

```shell
$> java -cp target/xml2cpp-1.0.jar phix.xml2cpp.Main ../spec/FIX50SP2.xml ../spec/FIXT11.xml ../examples/spec/fix50
```
