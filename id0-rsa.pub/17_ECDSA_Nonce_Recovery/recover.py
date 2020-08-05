#!/usr/bin/env python3

z1 = 78963682628359021178354263774457319969002651313568557216154777320971976772376
s1 = 5416854926380100427833180746305766840425542218870878667299
r1 = 5568285309948811794296918647045908208072077338037998537885

z2 = 62159883521253885305257821420764054581335542629545274203255594975380151338879
s2 = 1063435989394679868923901244364688588218477569545628548100
r2 = 5568285309948811794296918647045908208072077338037998537885

n = 6277101735386680763835789423176059013767194773182842284081

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

inv_s = inverse_mod(s1 - s2, n)
k = (z1 - z2) * inv_s % n
print("Following the reference paper, we get:", hex(k))

