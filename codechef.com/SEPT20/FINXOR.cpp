#include<iostream>
#include<stdio.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    int T, N;
    std::cin >> T;
    int twos[21];
    twos[0] = 1;
    for(int i = 0;i < 20;i++){
        twos[i + 1] = twos[i] * 2; 
    }
    
    for(int t = 0;t < T;t++){
        int ans = 0;
        std::cin >> N;
        int response[21];
        int count[20];

        std::cout << 1 << " " << twos[20] << std::endl;
        fflush(stdout);
        std::cin >> response[20];
        for(int i = 1;i < 20;i++){
            std::cout << 1 << " " << twos[20] + twos[20 - i] << std::endl;
            fflush(stdout);
            std::cin >> response[20 - i];
        }

        for(int i = 19;i > 0;i--){
            count[i] = (response[20] - response[i]) / twos[i];
            count[i] = (N + count[i]) / 2;
        }

        count[0] = response[20] - N * twos[20];
        for(int i = 19;i > 0;i--){
            count[0] -= count[i] * twos[i];
        }

        for(int i = 0;i < 20;i++){
            ans += (count[i] % 2) * twos[i];
        }

        std::cout << 2 << " " << ans << std::endl; 
        fflush(stdout);
        std::cin >> ans;
        if(ans == -1)
            break;
    }
}
