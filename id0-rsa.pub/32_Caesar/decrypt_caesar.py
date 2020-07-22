#!/usr/bin/env python3

def decrypt(text,key):
    result = ""
    for i in range(len(text)):
        char = text[i]

        if (char.isupper()):
            result += chr((ord(char) - (key - 65)) % 26 + 65)
        else:
            result += chr((ord(char) - (key - 97)) % 26 + 97)

    return result


encrypted_text = "ZNKIGKYGXIOVNKXOYGXKGRREURJIOVNKXCNOINOYXKGRRECKGQOSTUZYAXKNUCURJHKIGAYKOSZUURGFEZURUUQGZZNKCOQOVGMKGZZNKSUSKTZHAZOLOMAXKOZYMUZZUHKGZRKGYZROQKLOLZEEKGXYURJUXCNGZKBKXBGPJADLIVBAYKZNUYKRGYZZKTINGXGIZKXYGYZNKYURAZOUT"
for i in range(26):
    print("{} {}".format(i, decrypt(encrypted_text,i)))
