#!/usr/bin/env python3

import codecs
import secp256k1
import hashlib

secret = 94176137926187438630526725483965175646602324181311814940191841477114099191175

# Generate public key
Qp = secp256k1.scalar_mult(secret, secp256k1.curve.g)
pubkey = Qp[0]
print("Public Key                            : {:x}".format(pubkey))

# perform SHA256 on 04{publickey}{privatekey}
temp = "04{:x}{:x}".format(Qp[0], Qp[1])
temp = hashlib.sha256(codecs.decode(temp, "hex")).hexdigest()
print("SHA256 of 04publicprivate             :", temp)
ripemd160 = hashlib.new("ripemd160")
ripemd160.update(codecs.decode(temp, "hex"))
ext_riphash = "00" + ripemd160.hexdigest()
print("Extended RIPEMD-160 hash              :", ext_riphash)

temp = hashlib.sha256(codecs.decode(ext_riphash, "hex")).hexdigest()
temp = hashlib.sha256(codecs.decode(temp, "hex")).hexdigest()
print("Double SHA256 of Ext. RIPEMD-160 hash :", temp)
cksum = temp[:8]
addr = ext_riphash + cksum
print("25-byte binary Bitcoin address        :", addr)

# Base58Check Encoding
x = int.from_bytes(codecs.decode(addr, "hex"), byteorder="big")
code_string = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"

base58_addr = []
while x > 0:
    x, r = divmod(x, 58)
    base58_addr.append(code_string[r])

base58_addr.append("1")

base58_addr.reverse()
base58_addr = "".join(base58_addr)
print("Base58Check encoded address is        :", base58_addr)
