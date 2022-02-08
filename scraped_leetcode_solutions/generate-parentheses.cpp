class Solution {
public:
    void recurse(vector<string> &v, string &s, int left, int right){
        if(left == 0 && right == 0){
            v.push_back(s);
            return;
        }
        
        if(left > 0){
            s.push_back('(');
            recurse(v, s, left - 1, right + 1);
            s.pop_back();
        }
        if(right > 0){
            s.push_back(')');
            recurse(v, s, left, right - 1);
            s.pop_back();
        }
            
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s = "";
        recurse(ret, s, n, 0);
        return ret;
    }
};