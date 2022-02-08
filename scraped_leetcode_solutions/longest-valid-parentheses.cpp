class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> idx;
        int ans = 0;
        for(int i = 0;i < s.length();i++){
            if(idx.empty())
                idx.push(i);
            else if(s[idx.top()] == '(' && s[i] == ')'){
                idx.pop();
                if(idx.empty())
                     ans = max(ans, i + 1);
                else
                    ans = max(ans, i - idx.top());
            }else{
                idx.push(i);
            }
        }
        return ans;
    }
};