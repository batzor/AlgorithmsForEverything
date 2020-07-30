#!/usr/bin/env python3

import base64
import magic

def inverse_mod(k, p):
    """Returns the inverse of k modulo p.
    This function returns the only integer x such that (x * k) % p == 1.
    k must be non-zero and p must be a prime.
    """
    if k == 0:
        raise ZeroDivisionError('division by zero')

    if k < 0:
        # k ** -1 = p - (-k) ** -1  (mod p)
        return p - inverse_mod(-k, p)

    # Extended Euclidean algorithm.
    s, old_s = 0, 1
    t, old_t = 1, 0
    r, old_r = p, k

    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r
        old_s, s = s, old_s - quotient * s
        old_t, t = t, old_t - quotient * t

    gcd, x, y = old_r, old_s, old_t

    assert gcd == 1
    assert (k * x) % p == 1

    return x % p

with open("secret.txt") as f, open("encrypted.txt") as enc:
    secret = f.read()

    # from the looks of it, the text is b64 encoded
    b64decoded = base64.b64decode(secret)

    # now lets determine the what kind of file it is
    m = magic.Magic()
    print("B64Decoded string represents {}".format(m.from_buffer(b64decoded)))

    # since the string is gzip compressed we have to decompress
    import gzip
    decompressed = gzip.decompress(b64decoded)
    print('================================\nDecompressed:\n', decompressed)
    b64decoded = base64.b64decode(decompressed)
    print('================================\nBase64 Decoded:\n', base64.b64decode(decompressed))

    print("\nWe can see it's a message appended with public key")
    msg1, msg2, pubkey = b64decoded.split(b"\n\n")

    # the output looks like a RSA key

    from Crypto.PublicKey import RSA

    key = RSA.import_key(pubkey)
    print("Public key is", key.n)
    print("\nThe hint was to not brute force and it is not a short RSA key so maybe we can lookup its factorization somewhere")
    print("\nGoogling gives out factordb as a first result and they have a python module, GREAT!")

    from factordb.factordb import FactorDB
    f = FactorDB(key.n)
    f.connect()
    factor_list = f.get_factor_list()
    print("\nFactor list from FactorDB:", factor_list)
    print("\nSo we found p and q")
    p, q = factor_list

    d = inverse_mod(key.e, (p - 1)*(q - 1))
    print("\nAnd private key is:", d)

    c = enc.read().strip('\n')
    m = pow(int(c, 0), d, key.n)

    print("\nSo the answer is {}".format(m))






