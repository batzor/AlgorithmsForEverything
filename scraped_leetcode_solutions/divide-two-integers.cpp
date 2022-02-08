class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int ret = (long long int) dividend / divisor;
        if(ret > INT_MAX)
            ret = INT_MAX;
        if(ret < INT_MIN)
            ret = INT_MIN;
        return ret;
    }
};