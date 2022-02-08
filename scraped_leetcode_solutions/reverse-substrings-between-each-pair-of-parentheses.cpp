class Solution {
public:
    string reverseParentheses(string s) {
        string result = "";
        for(int i = 0; i < s.length();i++){
            cout << i << endl;
            if(s[i] != '('){
                result += s[i];
            }else{
                int closure = 1;
                string substr = "";
                for(int j = i + 1;j < s.length();j++){
                    if(s[j] == '(')
                        closure++;
                    if(s[j] == ')')
                        closure--;
                    
                    if(closure > 0)
                        substr += s[j];
                    else{
                        i = j;
                        reverse(substr.begin(), substr.end());
                        for(int k = 0;k < substr.length();k++){
                            if(substr[k] == '('){
                                substr[k] = ')';
                            }else if(substr[k] == ')'){
                                substr[k] = '(';
                            }
                        }
                        result += reverseParentheses(substr);
                        break;
                    }
                }
            }
        }
        return result;
    }
};