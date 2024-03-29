class Solution {
public:
    long long int reverse(long long int x) {
        long long ret = 0;
    	do{
    		ret = ret * 10 + x % 10;
    	}while (x /= 10);
        return (ret > INT_MAX || ret < INT_MIN) ? 0: (int) ret;    
    }
};