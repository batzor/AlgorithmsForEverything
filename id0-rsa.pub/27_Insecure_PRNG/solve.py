#!/usr/bin/env python3

import codecs
import secp256k1
import hashlib

a = 1103515245
c = 12345
m = 2**31
target_wif = "5KQFVHAxyMMVsDz75bDp7S4NpwoQz2FgR8b7DjyEhUo6saJfS73"
# Decoded using http://lenschulwitz.com/base58
# NOTE: remove the leading 80 and trailing checksum
target_rand = 0xD0D0B841BAFCCA097CF744ED94B90DACED8CE586085A2E86F0EECC521F9AEA9D

test_rand = 0x3a71c3dc3b5dad959973a074cff234bf09735ed305dfc6247357142a962bd3fa
test_wif = "5JG2Tvy2sgek4MkDHrNbRp6HcVya6rHELaNPxX4eKJ8z6jmDLWA"

def lcg(seed=None):
    global rand
    if(seed):
        rand = seed
    else:
        rand = (a * rand + c) % m
    return (rand >> 29) & 1

rng = lcg(0x123)
result = 0
for i in range(256):
    result = (result << 1) + lcg()

base58_string = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"
def to_wif(secret):
    padded = "80{:x}".format(secret)
    temp = hashlib.sha256(codecs.decode(padded, "hex")).hexdigest()
    cksum = hashlib.sha256(codecs.decode(temp, "hex")).hexdigest()[:8]
    temp = padded + cksum

    x = int.from_bytes(codecs.decode(temp, "hex"), byteorder="big")

    base58_addr = []
    while x > 0:
        x, r = divmod(x, 58)
        base58_addr.append(base58_string[r])

    base58_addr.reverse()
    base58_addr = "".join(base58_addr)
    return base58_addr

assert(to_wif(result) == test_wif)

# Brute LCG seed
matching_seq = "{:b}".format(target_rand).zfill(256)
for i in range(2**31):
    rng = lcg(i)
    result = 0
    for _ in range(24):
        result = (result << 1) + lcg()

    result = "{:b}".format(result).zfill(24)
    if(result in matching_seq):
        idx = matching_seq.index(result)
        result = 0
        rng = lcg(i)
        for _ in range(256 - idx):
            result = (result << 1) + lcg()
        if("{:b}".format(result).zfill(256 - idx) == matching_seq[idx:]):
            result = 0
            for _ in range(256):
                result = (result << 1) + lcg()

            print("Candidate ans:", to_wif(result))
