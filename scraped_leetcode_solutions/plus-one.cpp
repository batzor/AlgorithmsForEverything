class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        if(digits[i] != 9){
            ++digits[i];
            return digits;
        }
        
        while(i >= 0 && digits[i] == 9){
            digits[i] = 0;
            --i;
        }
        if(i == -1)
            digits.insert(digits.begin(), 1);
        else
            digits[i] += 1;
        return digits;
    }
};