class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t minlen = INT_MAX;
        for(auto str: strs){
            minlen = std::min(str.length(), minlen);
        }
        int i;
        for(i = 0;i < minlen;i++){
            char c = strs[0][i];
            for(int j = 1; j < strs.size();j++){
                if(strs[j][i] != c)
                    return strs[j].substr(0, i);
            }
        }
        return strs[0].substr(0, i);
    }
};