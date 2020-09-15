#include<iostream>
#include<vector>
#include<bits/stdc++.h>

#define MOD 1000000007

long long powmod(long long num, long long raise, long long modulo) {
    long long result = 1;
    while(raise > 0) {
        if(raise & 1) result = (result * num)%modulo;
        num = (num * num) %modulo;
        raise = (raise >> 1);
    }
    return result;
}

long long C(int n, int r, int mod) {
    std::vector<long long> fac(n + 1,1);
    for (int i = 2;i <= n;i++)
        fac[i] = (fac[i - 1] * i) % mod;
    return (fac[n]*((powmod(fac[r], mod - 2,mod) * powmod(fac[n - r], mod - 2,mod)) % mod)) % mod;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int T, N;
    std::cin >> T;
    
    for(int t = 0;t < T;t++){
        std::cin >> N;
        int c;
        int max_int = 0;
        int max_count;
        for(int i = 0; i < N;i++){
            std::cin >> c;
            if(max_int < c){
                max_int = c;
                max_count = 1;
            }else if(max_int == c){
                max_count++;
            }
        }

        long long ans = 0;
        if(max_count % 2 == 1){
            ans = powmod(2, N, MOD);
        }else{
            ans = powmod(2, N - max_count, MOD) * (powmod(2, max_count, MOD) - C(max_count, max_count / 2, MOD)) % MOD;
            ans = (ans + MOD) % MOD;
        }
            
        std::cout << ans << std::endl;
    }
}
