#!/usr/bin/env python3

# The first 3 letter, UHV, in the ciphertext is repeated 10 times and it is very likely that it is THE.
# This gives us a decent guess of the first 3 letter of the key, BAR. By the offset between them, we can
# also guess that the key is of length 3 or 6. Occurrence of XPJAERY and MOTYP also solidifies our guess.
# Given that we try decrypting the ciphertext with just BAR and we can see that it doesn't decipher
# the text. So if we think that the key is of length 6 and decipher half the text, we get THE***ENE*** at
# the start. Since they hinted VIGENERE is in the text, it is reasonable to think that it might start with
# THEVIGENERE. With that, we get the key BARLEY and fully decipher the text

with open("ciphertext.txt", 'r') as f:
    txt = f.read()

    key_start = "BAR"
    print("deciphering with key BAR")
    result = ""
    for i in range(len(txt)):
        result += chr(ord('A') + (ord(txt[i]) - ord(key_start[i % 3])) % 26)
    print(result)
    print("It doesnt make sense so lets decipher with key BAR***")
    result = ""
    for i in range(len(txt)):
        if(i % 6 <  3):
            result += chr(ord('A') + (ord(txt[i]) - ord(key_start[i % 3])) % 26)
        else:
            result += "*"
    print(result)
    print("Likely that the actual text started with THEVIGENERE which gives the key BARLEY")
    print("deciphering with BARLEY")
    key = "BARLEY"
    result = ""
    for i in range(len(txt)):
        result += chr(ord('A') + (ord(txt[i]) - ord(key[i % 6])) % 26)
    print(result)
    print("so the answer is BARLEY")




