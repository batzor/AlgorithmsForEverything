#!/usr/bin/env sage

from Crypto.PublicKey import RSA

with open("pub_key.pem") as f:
    key = RSA.importKey(f.read())
    factors = list(factor(key.n))
    assert(len(factors) == 2)
    p = factors[0][0]
    q = factors[1][0]
    print("p =", p)
    print("q =", q)

    d = inverse_mod(key.e, (p - 1) * (q - 1))
    print("{:x}".format(d))

