#!/usr/bin/env python3

with open("ciphertext.txt", 'r') as f:
    txt = f.read()

    # You can see that GFANOYDJINTNOE gets repeated 5 times in the ciphertext
    # and it has the same length as the word monoalpha

    upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    lower = "abcdefghijklmnopqrstuvwxyz"

    for letter in upper:
        print("{} {}".format(letter, txt.count(letter)))

    bigram_max_cnt = 0
    bigram = ""
    for i in range(len(txt)):
        cnt = txt.count(txt[i:i + 2])
        if(txt[i:i+2] == "NO"):
            continue
        if(bigram_max_cnt < cnt):
            bigram_max_cnt = cnt
            bigram = txt[i:i + 2]

    print("{} {}".format(bigram, bigram_max_cnt))

    trigram_max_cnt = 0
    trigram = ""
    for i in range(len(txt)):
        cnt = txt.count(txt[i:i + 3])
        if(trigram_max_cnt < cnt):
            trigram_max_cnt = cnt
            trigram = txt[i:i + 3]

    print("{} {}".format(trigram, trigram_max_cnt))

    # from the frequency analysis we could easily find that EZN => THE. The next most
    # frequent letter was "f" which is more likely to be "A" and replacing it we can
    # see a lot of THAT forming, solidifying our guess. The first word can be very few
    # words (TREAT, TWENTY etc). After replacing TWENTY the text starts to make a lot
    # of sense and from here on its very simple.
    replaced = txt.lower().replace("n", "E").replace("e", "T").replace("z","H").replace("f", "A").replace("k", "V").replace("a","W").replace("o", "N").replace("h","Y")


    print(replaced)
    replaced = list(replaced)
    for i in range(len(replaced)):
        if(replaced[i].islower()):
            replaced[i] = "_"

    replaced = "".join(replaced)

    print(replaced)

    # Now we can easily fill the key and find they key by filling the blanks
    #      ABCDEFGHIJKLMNOPQRSTUVWXYZ
    key = "WZUOTALYCRVSPENXQKIMDJBGFH"
    txt = list(txt.strip())

    for i in range(len(txt)):
        txt[i] = key[ord(txt[i]) - 65]

    print("".join(txt))

    from hashlib import md5
    print(md5("".join(txt).encode()).hexdigest())


