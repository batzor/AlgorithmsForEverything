class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        num = num % 9;        
        return num ? num : 9;
    }
};