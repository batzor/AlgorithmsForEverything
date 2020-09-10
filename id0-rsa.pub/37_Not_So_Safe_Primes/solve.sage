#!/usr/bin/env sage

p = 0x0a38522d6c0b9a056801aa0cbe0329ce8457e9724acd1323f19ea310700d6e38e0252e2eb5b2ba4846259c99e0006441199cf10053471486058a4caa04156a504b
g = 0x2

R = IntegerModRing(p)

# https://en.wikipedia.org/wiki/Pohlig-Hellman_algorithm
def pohlig_hellman(n, g, h):
    g = R(g)
    h = R(h)
    factors = factor(n)

    crt_rem = []
    crt_mod = []
    for f in factors:
        p_i, e_i = f[0], f[1]
        g_i = g ** ((p - 1) / (p_i ** e_i))
        h_i = h ** ((p - 1) / (p_i ** e_i))
        x_i = log(h_i, g_i)
        assert(x_i < p_i ** e_i)
        crt_rem.append(x_i)
        crt_mod.append(p_i ** e_i)

    return crt(crt_rem, crt_mod)

import requests
# just use a = 1
message = "{:x}".format(int(g))
r = requests.get("https://id0-rsa.pub/problem/dh-oracle/" + message)
assert(r.status_code == 200)
shared_secret = int(r.text, 16)

b = pohlig_hellman(p - 1, Integer(g), Integer(shared_secret))

# Print last 50 digits
print(str(b)[-50:])

