#include<iostream>
#include<map>
#include<cmath>

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    long long N;
    std::cin >> T;
    
    for(int t = 0;t < T;t++){
        std::cin >> N;
        if(N * (N + 1) % 4 != 0){
            std::cout << 0 << std::endl;
            continue;
        }
        long long ans = 0;
        long long max_m = (long long) (-1 + sqrt(2 * N * N + 2 * N + 1)) / 2;
        long long m = max_m;
        long long first_sum = m * (m + 1) / 2;
        long long last_sum = (N - m) * (N + m + 1) / 2;
        if(first_sum == last_sum){
            ans += m * (m - 1) / 2;
            ans += (N - m) * (N - m - 1) / 2;
            first_sum -= m;
            last_sum += m;
            m--;
        }

        for(;m > 0;m--){
            long long diff = last_sum - first_sum;

            if(diff % 2 != 0){
                first_sum -= m;
                last_sum += m;
                continue;
            }


            if(diff / 2 >= N){
                break;
            }

            long long swap_diff = diff / 2;
            ans += std::min(N - swap_diff, m) - std::max((long long)1, m + 1 - swap_diff) + 1;
            first_sum -= m;
            last_sum += m;
        }
        std::cout << ans << std::endl;
    }
}
