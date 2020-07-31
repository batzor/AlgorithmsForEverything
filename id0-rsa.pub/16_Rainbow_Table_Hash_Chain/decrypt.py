#!/usr/bin/env python3

from hashlib import sha256

line_count = 0
rockyou_list = []
with open('../rockyou.txt', encoding="ISO-8859-1") as f:
    for i, l in enumerate(f):
        rockyou_list.append(l.strip('\n'))
    line_count = i + 1
    assert(len(rockyou_list) == line_count)

def password_hash(pw):
    val = b''

    for i in range(49999):
        concatted = val + pw.encode('utf-8')
        val = sha256(concatted).digest()

    concatted = val + pw.encode('utf-8')
    val = sha256(concatted).hexdigest()
    return val

hash_val = password_hash('loveu2')
print("\nConfirm that our hash function is working as expected.")
print("Hash of loveu2 is", hash_val)

def reverse(pw_hash, column_number):
    num_val = int(pw_hash, 16)
    line_number = (num_val + column_number) % line_count
    return rockyou_list[line_number]

reverse_val = reverse(hash_val, 0)
print("\nConfirm that our reverse function is working as expected.")
print("Reverse of the hash value is", reverse_val)

print("\nCalculate the hash chain.")
pw = "bambino"
the_chain = []
for i in range(200):
    print("\rCalculating {}/200 hash".format(i + 1), end="")
    hash_val = password_hash(pw)
    the_chain.append([pw, hash_val])
    pw = reverse(hash_val, i)

assert(pw == 'hunter42')
print("\nOur end of the hash chain is indeed hunter42")
print("So now we can just search the target hash from our hash chain")

target_hash = '27ce84a6075b583086d9fc0c856f1da5d9a853507faffd7d70833c1b7accb156'
for key, h in the_chain:
    if(h == target_hash):
        print("The password is the {}th element in the chain: {}".format(i, key))
