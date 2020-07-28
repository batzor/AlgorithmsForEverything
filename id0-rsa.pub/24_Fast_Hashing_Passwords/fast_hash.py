#!/usr/bin/env python3

from hashlib import sha256

with open("../rockyou.txt", encoding="ISO-8859-1") as pass_dict:
    password = pass_dict.readline().strip("\n")
    h = sha256(password.encode()).hexdigest()
    min_hash = h
    max_hash = h
    min_word = password
    max_word = password
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
        h = sha256(password.encode()).hexdigest()
        if(h < min_hash):
            min_word = password
            min_hash = h
        if(h > max_hash):
            max_hash = h
            max_word = password

    print("{}{}".format(max_word, min_word))




