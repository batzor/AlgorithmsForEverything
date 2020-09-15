#include<iostream>
#include<map>

int main(){
    int T, N;
    std::cin >> T;
    
    for(int t = 0;t < T;t++){
        std::cin >> N;
        bool arr[N];
        int tmp1, tmp2;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                int entry;
                std::cin >> entry;
                if(i == j - 1){
                    tmp1 = entry;
                }
                if(i == j + 1){
                    tmp2 = entry;
                    arr[j] = tmp1 > tmp2;
                }
            }
        }
        arr[N - 1] = 0;
        int ans = 0;
        for(int i = 0;i < N - 1;i++){
            if(arr[i] != arr[i + 1]){
                ans += 1;
            }
        }

        std::cout << ans << std::endl;
    }
}
