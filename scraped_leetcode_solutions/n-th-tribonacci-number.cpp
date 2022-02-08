class Solution {
public:
    int nacci[38] = {-1};
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n < 3)
            return 1;
        if(nacci[n] > 0)
            return nacci[n];
        else
            nacci[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        return nacci[n];
    }
};