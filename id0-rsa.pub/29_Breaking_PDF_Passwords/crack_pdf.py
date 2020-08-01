#!/usr/bin/env python3

from hashlib import md5
from binascii import hexlify
from codecs import decode, encode
from Crypto.Cipher import ARC4

metadata = {
    "user_hash":    b"fe97c8762da0f0201eb463df6e181288",
    "key_length":   128,
    "revision":     3,
    "permissions":  b"fcffffff",
    "owner_hash":   b"79e64c5fd1d84a4ae2bc07e82636b34b5969c4fe6bcce36886db40dece66f0e2",
    "document_id":  b"bfb6e1530b109ae5d10cf52562e8bd3a",
}

pad_string = b"28BF4E5E4E758A4164004E56FFFA01082E2E00B6D0683E802F0CA9FE6453697A"
owner_hash =  metadata["owner_hash"]
permissions = metadata["permissions"]
document_id = metadata["document_id"]
def get_sym_key(pw):
    padded = hexlify(pw.encode()) + pad_string.lower()
    padded = padded[:64]
    concatted = padded + owner_hash + permissions + document_id
    sym_key = md5(decode(concatted, "hex")).digest()
    for i in range(50):
        sym_key = md5(sym_key).digest()

    return sym_key

print("Confirm the symmetric key derivation is working on test vector.")
print("Symmetric key of the test vector 'password' is ", encode(get_sym_key("password"), "hex"))

def get_user_hash(pw):
    sym_key = get_sym_key(pw)

    hash_val = md5(decode(pad_string + document_id, "hex")).digest()
    c = ARC4.new(sym_key)
    key = c.encrypt(hash_val)

    for i in range(1, 20):
        xord = b''
        for ch in sym_key:
            xord += bytes([ch ^ i])
        c = ARC4.new(xord)
        key = c.encrypt(key)

    return key

print("\nConfirm the symmetric key derivation is working on test vector.")
print("User hash of the test vector 'password' is ", encode(get_user_hash("password"), "hex"))

print("\nNow we can brute force the password using the given user hash")
user_hash = metadata["user_hash"]
with open("../rockyou.txt", encoding="ISO-8859-1") as pass_dict:
    decoded_user_hash = decode(user_hash, "hex")
    while True:
        # having this try/except is faster and idk why
        try:
            password = pass_dict.readline()
        except:
            print("not printed!")
            continue

        if not password:
            break

        password = password.strip("\n")
        if(decoded_user_hash == get_user_hash(password)):
            print("And the first match we found is", password)
            break

