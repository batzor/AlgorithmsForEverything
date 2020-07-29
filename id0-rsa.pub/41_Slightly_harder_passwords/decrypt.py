#!/usr/bin/env python3

import crypt
import os

print("Example hashes:")
print("SHA256 :", crypt.crypt("hi", crypt.mksalt(crypt.METHOD_SHA256)))
print("CRYPT  :", crypt.crypt("hi", crypt.mksalt(crypt.METHOD_CRYPT)))
print("MD5    :", crypt.crypt("hi", crypt.mksalt(crypt.METHOD_MD5)))
print("\n From here we can see that the given hash have the same length as CRYPT")

# Since the salt of crypt algorithm has only 2 bytes, we can brute force by
# applying the L33t rules to the dictionary in a reasonable time. But I will
# just follow the hint and use John The Ripper to decrypt.
# NOTE: I installed using apt install john and added to rules to /etc/john/john.conf

os.system("john --format=crypt hashed.txt")
os.system("john --show hashed.txt")

# the result is u$e Th3 l4$t lett3r 0f 3@ch w0rd
# so the answer is e3trfhd
