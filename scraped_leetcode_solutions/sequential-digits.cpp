class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        const std::string s = "123456789";
        set<int> ans;
        for(int i = 0;i < 9;++i){
            for(int j = i + 1;j <= 9;++j){
                int tmp = stoi(s.substr(i, j - i));
                if(tmp >= low && tmp <= high){
                    ans.insert(tmp);
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};