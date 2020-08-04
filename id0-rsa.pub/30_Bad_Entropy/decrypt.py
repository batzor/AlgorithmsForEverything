#!/usr/bin/env python3

from Crypto.Cipher import AES
from codecs import decode, encode
from datetime import datetime
from hashlib import md5
from time import time

def genkey(t):
    return md5(str(t).encode()).digest()

min_possible_time = int(datetime(2016,1,25,0,0).timestamp())
max_possible_time = int(datetime(2016,2, 1,0, 0).timestamp())

t = min_possible_time
ciphertext = b'a99210d796a1e37503febf65c329c1b2'
ciphertext = decode(ciphertext, "hex")
while t < max_possible_time:
    key = genkey(t)
    cipher = AES.new(key, AES.MODE_ECB)
    plaintext = cipher.decrypt(ciphertext)
    try:
        txt = plaintext.decode("ascii")
        print(txt)
    except:
        pass

    t += 1

print("From here, the answer is clear:", "use /dev/urandom")


