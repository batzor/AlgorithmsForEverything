#include<iostream>
#include<map>

int main(){
    int T, N;
    std::cin >> T;
    
    for(int t = 0;t < T;t++){
        std::cin >> N;
        int ans = 0, a;
        std::map<int, bool> intmap;
        for(int n = 0;n < N;n++){
            std::cin >> a;
            if(a == 0)
                continue;
            if(intmap.find(a) == intmap.end()){
                intmap[a] = true;
                ans++;
            }
        }
        std::cout << ans << std::endl;
    }
}
