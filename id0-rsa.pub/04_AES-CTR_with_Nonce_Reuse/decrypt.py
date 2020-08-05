#!/usr/bin/env python3

from Crypto.Cipher import AES
from codecs import decode, encode
from binascii import hexlify

ciphertext1 = b"369f9e696bffa098d2bb383fb148bd90"
ciphertext2 = b"23d7847f28e4b6cc86be386cb64ca281"
ciphertext1 = b"369f9e696bffa098d2bb383fb148bd90"
ciphertext2 = b"23d7847f28e4b6cc86be386cb64ca281"

c1 = decode(ciphertext1, "hex")
c2 = decode(ciphertext2, "hex")

def byte_xor(b1, b2):
    return bytes(i ^ j for i, j in zip(b1, b2))

xored = byte_xor(c1, c2)

print("Lets check the occurence of most common word: the")
for i in range(14):
    x = xored[i:i+3]
    print(i, byte_xor(x, b"the").decode("ascii"))

print("\nFrom the result, our best guess is 'the' is located at index 8 and")
print("in the other plaintext index 8, it has ' me'. So we can deduce that it")
print("has whitespaces in it. So 'the' in middle of the plaintext contains")
print("whitespaces. So our partial best guess can be ' the '. Lets check.")

for i in range(12):
    x = xored[i:i+5]
    print(i, byte_xor(x, b" the ").decode("ascii"))

print("\nThe result looks really promising. Now we can guess that 't mes' will")
print("complete into 't message'. Lets check if it makes sense")

for i in range(8):
    x = xored[i:i+9]
    print(i, byte_xor(x, b"t message").decode("ascii"))

print("\nWe are definitely in the correct path. The word ending with t can be")
print("'text' or 'secret' so lets check if it makes sense")

for i in range(5):
    x = xored[i:i+12]
    print(i, byte_xor(x, b"text message").decode("ascii"))
    print(i, byte_xor(x, b"cret message").decode("ascii"))

print("\nSo the word we were looking for is 'secret', and we can guess one of the")
print("plaintext is 'a secret message'")
print("So the other text will be:", byte_xor(xored, b'a secret message').decode("ascii"))
print("And answer = a secret messagethis is the text")

