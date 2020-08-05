#!/usr/bin/env python3

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ,."

def inverse_mod(k, p):
    """Returns the inverse of k modulo p.
    This function returns the only integer x such that (x * k) % p == 1.
    k must be non-zero and p must be a prime.
    """
    if k == 0:
        raise ZeroDivisionError('division by zero')

    if k < 0:
        # k ** -1 = p - (-k) ** -1  (mod p)
        return p - inverse_mod(-k, p)

    # Extended Euclidean algorithm.
    s, old_s = 0, 1
    t, old_t = 1, 0
    r, old_r = p, k

    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r
        old_s, s = s, old_s - quotient * s
        old_t, t = t, old_t - quotient * t

    gcd, x, y = old_r, old_s, old_t

    assert gcd == 1
    assert (k * x) % p == 1

    return x % p

def decode(txt, a, b):
    result = []
    for i in range(0, len(txt), 2):
        index = alphabet.find(txt[i]) * 29 + alphabet.find(txt[i + 1])

        # ignore other characters
        if(index < 0):
            continue
        new_index = (inverse_mod(a, 841) * index - b) % 841
        result.append(alphabet[new_index // 29])
        result.append(alphabet[new_index % 29])

    return "".join(result)

count_max = 0
best_guess = (0, 0)
best_result = ""
with open("ciphertext.txt", 'r') as f:
    txt = f.read().strip()
    for a in range(1, 841):
        if(a % 29 == 0):
            continue
        for b in range(841):
            decoded_txt = decode(txt, a, b)
            # THE is the most common trigram in English text
            if 0 < decoded_txt.count("THE ") and 0 < decoded_txt.count(". ") and 0 < decoded_txt.count(" OR "):
                best_result = decoded_txt
                print(decoded_txt)
                a = 841

    from hashlib import md5
    print("Answer is", md5(best_result.encode()).hexdigest())



