#!/usr/bin/env python3
from Crypto.PublicKey import RSA

def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

def my_gcd(a, b):
    r, old_r = b, a

    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r

    return old_r

def fermat_factor(n):
    a = isqrt(n) + 1
    b2 = pow(a, 2) - N
    while(pow(isqrt(b2), 2) != b2):
        a += 1
        b2 = pow(a, 2) - N
    return a - isqrt(b2)

def new_factor(n):
    a = isqrt(n) + 1
    while True:
        b = pow(a, 2) - 1
        d = my_gcd(n, b)
        if(d > 1):
            return d
        else:
            a += 1

def pr_factor(n):
    x = []
    x.append(2)
    new_x = (pow(x[-1], 2) + 1) % n
    while True:
        new_x = (pow(x[-1], 2) + 1) % n
        if new_x in x:
            break
        x.append(new_x)

    for i in x:
        for j in x:
            if(i - j) != 0:
                d = my_gcd(abs(i - j), n)
                if(d > 1):
                    return d

    return -1


with open("pub_key.pem") as f:
    key = RSA.import_key(f.read())
    N = key.n
    e = key.e
    p = pr_factor(N)
    q = N // p

    print(p, q)
