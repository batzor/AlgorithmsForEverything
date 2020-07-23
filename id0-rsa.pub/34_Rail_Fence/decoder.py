#!/usr/bin/env python3

from itertools import chain

def fence(lst, numrails):
    fence = [[None] * len(lst) for n in range(numrails)]
    rails = list(range(numrails - 1)) + list(range(numrails - 1, 0, -1))
    for n, x in enumerate(lst):
        fence[rails[n % len(rails)]][n] = x

    return [c for rail in fence for c in rail if c is not None]

def decode(text, n):
    text = text.replace(" ", "")
    rng = range(len(text))
    pos = fence(rng, n)
    return ''.join(text[pos.index(n)] for n in rng)

def encode(text, n):
    return ''.join(fence(text, n))

# Test vector
print(decode("WECRL TEERD SOEEF EAOCA IVDEN", 3))

with open("ciphertext.txt", 'r') as f:
    txt = f.read()

    # You can brute force the keys and find out that 17 is the key.
    print(decode(txt, 17))


