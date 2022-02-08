class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        int max3pow = pow(3, 19);
        if(max3pow % n == 0)
            return true;
        else
            return false;
    }
};