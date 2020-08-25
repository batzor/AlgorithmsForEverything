#!/usr/bin/env python3
from pwn import xor
from codecs import decode

KEY1 = b'a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313'
KEY2xKEY1 = b'37dcb292030faa90d07eec17e3b1c6d8daf94c35d4c9191a5e1e'
KEY2xKEY3 = b'c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1'
FLAGxKEY1xKEY2xKEY3 = b'04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf'

FLAGxKEY1 = xor(FLAGxKEY1xKEY2xKEY3, KEY2xKEY3)
FLAG = xor(FLAGxKEY1, KEY1)

print(FLAG)
