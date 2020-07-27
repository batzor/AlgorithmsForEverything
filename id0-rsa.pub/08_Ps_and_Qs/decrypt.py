#!/usr/bin/env python3

def ext_euclidean_algorithm(a, b):
    """
    Returns a three-tuple (gcd, x, y) such that
    a * x + b * y == gcd, where gcd is the greatest
    common divisor of a and b.

    This function implements the extended Euclidean
    algorithm and runs in O(log b) in the worst case.
    """
    s, old_s = 0, 1
    t, old_t = 1, 0
    r, old_r = b, a

    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r
        old_s, s = s, old_s - quotient * s
        old_t, t = t, old_t - quotient * t

    return old_r, old_s, old_t


def modular_inverse(n, p):
    """
    Returns the multiplicative inverse of
    n modulo p.

    This function returns an integer m such that
    (n * m) % p == 1.
    """
    gcd, x, y = ext_euclidean_algorithm(n, p)
    assert (n * x + p * y) % p == gcd

    if gcd != 1:
        # Either n is 0, or p is not a prime number.
        raise ValueError(
            '{} has no multiplicative inverse '
            'modulo {}'.format(n, p))
    else:
        return x % p

from Crypto.PublicKey import RSA

with open("publickey1.pem") as f1, open("publickey2.pem") as f2:
    key1 = RSA.import_key(f1.read())
    key2 = RSA.import_key(f2.read())

    p, _, _ = ext_euclidean_algorithm(key1.n, key2.n)
    q = key1.n // p

    N = (p - 1) * (q - 1)
    d = modular_inverse(key1.e, N)

    with open("encrypted_msg.txt") as msg:
        m = msg.read().strip('\n')
        m = pow(int(m, 0), d, key1.n)

        print("Answer is {:x}".format(m))

