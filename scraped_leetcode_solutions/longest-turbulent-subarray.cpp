class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n < 2)
            return n;
        
        bool isless = arr[0] > arr[1];
        bool iseq = arr[1] == arr[0];
        int tur = iseq ? 1: 2;
        int maxtur = 0;
        for(int i = 2; i < n;++i){
            if(arr[i - 1] < arr[i] && isless && !iseq) {
                isless = !isless;
                ++tur;
            }else if(arr[i - 1] > arr[i] && !isless && !iseq) {
                isless = !isless;
                ++tur;
            }else{
                isless = arr[i - 1] > arr[i];
                iseq = arr[i - 1] == arr[i];
                maxtur = max(tur, maxtur);
                tur = iseq ? 1: 2;
            }
        }
        maxtur = max(tur, maxtur);
        return maxtur;
    }
};