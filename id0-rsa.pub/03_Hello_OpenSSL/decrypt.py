#!/usr/bin/env python3
from Crypto.PublicKey import RSA

with open('privkey.pem', 'r') as f:
    key = RSA.import_key(f.read())
    d = key.d
    n = key.n
    ans = pow(0x6794893f3c47247262e95fbed846e1a623fc67b1dd96e13c7f9fc3b880642e42, d, n)
    print("answer is {:x}".format(ans))
