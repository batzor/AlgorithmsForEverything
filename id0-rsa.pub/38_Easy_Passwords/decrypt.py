#!/usr/bin/env python3

import crypt

print("Example salts:")
print("SHA256 :", crypt.mksalt(crypt.METHOD_SHA256))
print("CRYPT  :", crypt.mksalt(crypt.METHOD_CRYPT))
print("MD5    :", crypt.mksalt(crypt.METHOD_MD5))
print("\n From here we can see that the given hash is of type MD5")

def get_hash(salt, key_string, hashed):
    if(hash_result == hashed):
        return True
    return False

with open("/usr/share/dict/words") as password_dict, open("hashed.txt") as h:
    hashed = h.read()
    hashlist = hashed.strip('\n').split('\n')
    salt = hashlist[0][:11]

    result = [None] * len(hashlist)
    for word in password_dict:
        word = word.strip('\n')
        h = crypt.crypt(word, salt)
        is_found = 0
        for i in range(len(hashlist)):
            if(hashlist[i] == h):
                is_found += 1
                result[i] = word
                print(result)

            if(is_found == len(hashlist)):
                break

    # It gives us ['the', 'second', 'letter', 'of', 'each', 'word', 'in', 'this', 'list', 'in', 'order']
    answer = ""
    for word in result:
        answer += word[1]

    print("So the answer is", answer)
