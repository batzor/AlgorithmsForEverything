class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
            return true;
        
        stack<char> par;
        for(size_t i = 0; i < s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                par.push(s[i]);
            else{
                if(par.empty())
                    return false;
                if(s[i] == ')')
                    if(par.top() == '(')
                        par.pop();
                    else
                        return false;
                if(s[i] == ']')
                    if(par.top() == '[')
                        par.pop();
                    else
                        return false;
                if(s[i] == '}')
                    if(par.top() == '{')
                        par.pop();
                    else
                        return false;
            }
        }
        return par.empty();
    }
};