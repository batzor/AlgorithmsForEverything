#!/usr/bin/env python3
import codecs

hexstr = b'72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf'
bytestr = codecs.decode(hexstr, "hex")
print(codecs.encode(bytestr, "base64"))

