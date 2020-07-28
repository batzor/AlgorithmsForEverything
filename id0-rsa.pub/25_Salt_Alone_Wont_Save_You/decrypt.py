#!/usr/bin/env python3

from hashlib import sha256
from base64 import b64decode, b64encode

def get_hash(salt, passwd):
    concated_str = passwd + salt
    hash_val = sha256(concated_str.encode()).digest()

    return '${}${}'.format(salt, b64encode(hash_val).decode('utf-8'))

with open("hashed.txt") as f,  open("../rockyou.txt", encoding="ISO-8859-1") as pass_dict:
    saltlist = []
    hashlist = []
    for line in f:
        line = line.strip('\n')
        l = line.split('$')
        saltlist.append(l[1])
        hashlist.append(line)

    passlist = []
    while True:
        # having this try/except is faster and idk why
        try:
            password = pass_dict.readline()
        except:
            print("not printed!")
            continue

        if not password:
            break

        password = password.strip('\n')
        is_found = 0
        for (salt, h) in zip(saltlist, hashlist):
            if(h == get_hash(salt, password)):
                is_found += 1
                passlist.append(password)
                print(passlist)
                if(is_found == len(passlist)):
                    break

    passlist.sort()
    print("Answer  is", "".join(passlist))
