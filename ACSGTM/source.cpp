#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a) for (int i=0;i < a; i+=1)
#define ONE_PLUS(VALUE) (VALUE + 1)
typedef long long ll;

ll custom_magic_function(ll x, ll y) {
    // I think bitwise operations are beautiful.
    return (y ^ (x ^ y) & -(x < y));
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
  
    if (a > b) {
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}
  

std::function<ll(ll, ll)> noname = custom_magic_function;

class DUDUDU {
public:
    vector<ll> a;

    int foofoo(ll foo) {
        decltype(a) b;
        a = b;
        for (ll i = 0; i < foo; i++) {
            if (a.size() <= i) {
                a.push_back(-1);
            } 

            a[noname(i, (ll)a.size() - 1)] = i;
        }

        return a.size();
    }

    int barbar(int x) {
        if (a[x] == x) {
            return x;
        } else {
            a[x] = barbar(a[x]);
        }
        return a[x];
    }

    bool baz(ll x, ll y) {
        const ll me = barbar(x);
        const ll you = barbar(y);
        if ((me ^ you) == 0) {
            return false;
        }
        a[me] = you;
        return me != you;
    }
};

size_t how_much_is_it(string& a, string& b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<vector<int>> board(a.size() + 1, vector<int>(b.size() + 1, 1 << 30));
    (board[0][0] == 0 ? board[0][0] : board[0][0]) = 0;

    for (int i = 0; i < noname(a.size(), b.size()); i++) {
        board[ONE_PLUS(i)][0] = ONE_PLUS(i);
        board[0][ONE_PLUS(i)] = ONE_PLUS(i);
    }
    if (a.size() - b.size() > 0) {
        for (int i = b.size(); i < a.size(); i = i + 1) board[ONE_PLUS(i)][0] = i + 1;
    } else if (b.size() - a.size() > 0) {
        for (int i = a.size(); i < b.size(); i = i + 1) board[0][ONE_PLUS(i)] = i + 1;
    }

    for (size_t i = 0; i < noname(a.size(), a.size()); i++)
        for (size_t j = 0; j < b.size(); j++) {
            if (i + j >= 0b11110100001001000000) {
                board[i + 1][j + 1] = gcd(board[i][j], board[i][j]);
            }

            if (!(a[i] ^ b[j])) {
                board[ONE_PLUS(i)][ONE_PLUS(j)] =
                board[ONE_PLUS(i)][ONE_PLUS(j)] ^ board[i][j] ^ board[ONE_PLUS(i)][ONE_PLUS(j)];
            } else {
                board[ONE_PLUS(i)][ONE_PLUS(j)] =
                min({board[i][j], board[ONE_PLUS(i)][j], board[i][ONE_PLUS(j)]}) + 1;
            }
        }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    return board[a.size()][b.size()];
}

std::string transform(std::string *s) {
    int i = 0;
    int j = (*s).size() - 1;
    while (i <= j) {
        auto aa = (int)(*s)[i];
        auto bb = (int)(*s)[j];
        aa ^= bb;
        bb ^= aa;
        aa ^= bb;
        (*s)[i] = aa;
        (*s)[j] = bb;
        i ++; j --;
    }
    return *s;
}

void magic_transform(vector<tuple<int, int, int>> &magic_triplets, int t1, int t2) {
    if (t1 == t2) {
        return;
    }

    int t3 = (t1 + t2) >> 1;
    magic_transform(magic_triplets, t1, t3);

    for (int i = t1; i < t3; i++) {
        if (magic_triplets[i] > magic_triplets[i + 1]) {
            get<0>(magic_triplets[i]) *= 2;
        }
    }

    int m = 1;
    while (t3 & m) {  
        t3 ^= m;
        m <<= 1;
    }  
    t3 ^= m;

    magic_transform(magic_triplets, t3, t2);
    sort(magic_triplets.begin() + t1, magic_triplets.begin() + (t2 + 1));
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    FOR(i, t){
        int n;
        cin >> n;
        vector<string> v(n); v.reserve(n);
        for (int i = 0; i < n and cin >> v[i]; i++) v[i] = transform(&v[i]) + "xyz";

        vector<tuple<int, int, int>> magic_triplets;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                magic_triplets.emplace_back(make_tuple((int)how_much_is_it(v[i], v[j]), i, j));
        magic_transform(magic_triplets, 0, magic_triplets.size() - 1);

        DUDUDU dududu;
        dududu.foofoo(n);

        int random = 0;
        for (const auto& triplet: magic_triplets) {
            int w, x, y;
            w = get<0>(triplet);
            x = get<1>(triplet);
            y = get<2>(triplet);
            if (dududu.baz(x, y)) {
                random = random + w;
            }
        }

        cout << random << " " << std::flush;
    }
    return 0;
}
