#!/usr/bin/env python3

from itertools import chain

def fence(lst, numrails):
    fence = [[None] * len(lst) for n in range(numrails)]
    rails = list(range(numrails - 1)) + list(range(numrails - 1, 0, -1))
    for n, x in enumerate(lst):
        fence[rails[n % len(rails)]][n] = x

    return [c for rail in fence for c in rail if c is not None]

def decode_rfence(text, n):
    text = text.replace(" ", "")
    rng = range(len(text))
    pos = fence(rng, n)
    return ''.join(text[pos.index(n)] for n in rng)

def decode_vigenere(txt, key):
    result = ""
    for j in range(len(txt)):
        result += chr(ord('A') + (ord(txt[j]) - ord(key[j % len(key)])) % 26)
    return result

test_vector = "UJNBF UUFJU UQGZO NVUXE QVZJT FQFFS U"
txt = decode_rfence(test_vector, 3)
key = "BC"
result = ""
for i in range(len(txt)):
    result += chr(ord('A') + (ord(txt[i]) - ord(key[i % 2])) % 26)
print(result)

with open("ciphertext.txt", 'r') as f:
    ctext = f.read()

    # Just a guess of prefix
    prefix = "THISIS"
    for i in range(20):
        txt = decode_rfence(ctext, i + 3)
        key = ""
        for j in range(6):
            key += chr(ord('A') + (ord(txt[j]) - ord(prefix[j])) % 26)

        result = decode_vigenere(txt, key)
        print(result)
        print(key, result.count("TH"))
        print("=======================")

    txt = decode_rfence(ctext, 21)
    key = "TRADER"
    result = ""
    for j in range(len(txt)):
        result += chr(ord('A') + (ord(txt[j]) - ord(key[j % 6])) % 26)
    print(result)
