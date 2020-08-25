#!/usr/bin/env python3

s = "label"
flag = "".join(chr(13 ^ ord(o)) for o in s)

print("crypto{" + flag + "}")
