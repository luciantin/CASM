

### Type section
- a vector of : functype i.e. a function signature
- currently, only holds functype but in future could hold more types 

#### Function type
- are encoded by the byte 0x60 followed by the respective vector of parameters and result types

#### Result type
- a vector of valtype

#### Valtype
- numtype or reftype


```
// read # as "number" or "length"
0061 736d 0100 0000 // wasm special bytes
//after this must come a section id followed by the length of that section
0x01 // start of section "type"
0x06 // length of current section
0x01 // # of types
0x60 // func type byte
0x01 // # of input type vector
0x7f // input type
0x01 // # of output type vector
0x7f // output type
// if we have reached the end of the current section then a new section should/will start
0x03 // start of next section ("Function" section)
0x03 // next section length
```