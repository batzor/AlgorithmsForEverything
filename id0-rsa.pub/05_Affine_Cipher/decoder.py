#!/usr/bin/env python3

# you can check solution of 08_Ps_and_Qs for an algorithm of modular inverse

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ,."

# modular inverse of multiplicative group of integers modulo 29
inverse = [1, 15, 10, 22, 6, 5, 25, 11, 13, 3, 8, 17, 9, 27, 2, 20, 12, 21, 26, 16, 18, 4, 24, 23, 7, 19, 14, 28, 0]

def decode(txt, a, b):
    result = []
    for letter in txt:
        index = alphabet.find(letter)

        # ignore other characters
        if(index == -1):
            continue
        new_index = (inverse[a] * index - b) % 29
        result.append(alphabet[new_index])

    return "".join(result)

#brute force
count_max = 0
best_guess = (0, 0)
with open("ciphertext.txt", 'r') as f:
    txt = f.read()
    for a in range(1, 29):
        for b in range(29):
            decoded_txt = decode(txt, a, b)
            # THE is the most common trigram in English text
            if count_max < decoded_txt.count("THE"):
                count_max = decoded_txt.count("THE")
                best_guess = (a, b)

    best_result = decode(txt, best_guess[0], best_guess[1])

    print("Our best guess of key is a={} b={}".format(best_guess[0], best_guess[1]))
    print(best_result)
    import hashlib
    import codecs
    print("Answer is", hashlib.md5(best_result.strip('\n').encode('utf-8')).hexdigest())



