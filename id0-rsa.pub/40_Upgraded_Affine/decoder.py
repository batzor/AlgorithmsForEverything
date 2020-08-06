#!/usr/bin/env python3

# you can check solution of 08_Ps_and_Qs for an algorithm of modular inverse

alphabet = "abcdefghijklmnopqrstuvwxyz ,."

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

def decode(txt, a, b, iv):
    result = []
    for letter in txt:
        index = alphabet.find(letter)
        offset = alphabet.find(iv)

        # ignore other characters
        if(index == -1):
            continue
        new_index = (inverse_mod(a, 29) * (index - b) - offset) % 29

        result.append(alphabet[new_index])
        iv = letter

    return "".join(result)

#brute force
count_max = 0
best_guess = (0, 0)
best_result = ""
with open("ciphertext.txt", 'r') as f:
    txt = f.read()
    for a in range(1, 29):
        for b in range(29):
            decoded_txt = decode(txt, a, b, 'e')
            # THE is the most common trigram in English text
            if count_max < decoded_txt.count("the"):
                count_max = decoded_txt.count("the")
                best_guess = (a, b)
                best_result = decoded_txt
                print(best_result)


    print("\nOur best guess of key is a={} b={}".format(best_guess[0], best_guess[1]))
    print(best_result)



