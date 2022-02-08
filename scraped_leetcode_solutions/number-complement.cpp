class Solution {
public:
    int findComplement(int num) {
        long long int cur = 1;
        int ret = 0;
        while(num > 0){
            if(num % 2 == 0)
                ret += cur;
            num /= 2;
            cur *= 2;
        }
        return ret;
    }
};