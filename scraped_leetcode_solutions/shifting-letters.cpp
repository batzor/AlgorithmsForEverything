class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long shift = 0;
        for(int i = s.length() - 1;i >= 0;--i){
            shift += shifts[i];
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }
        return s;
    }
};