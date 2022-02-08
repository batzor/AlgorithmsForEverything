class Solution {
public:
    bool isNumber(string s) {
        int idx = 0;
        while(s[idx] == ' '){
            idx++;
        }
        if(s[idx] == '+' || s[idx] == '-')
            idx += 1;
        
        bool dot_allowed = true;
        bool exp_allowed = true;
        bool sign_allowed = false;
        bool digit_allowed = true;
        bool digit_required = true;
        while(idx < s.length()){
            if(s[idx] == '.' && dot_allowed){
                dot_allowed = false;
                idx += 1;
            }else if(s[idx] == 'e' && exp_allowed && !digit_required){
                digit_required = true;
                dot_allowed = false;
                exp_allowed = false;
                sign_allowed = true;
                idx += 1;
            }else if(isdigit(s[idx]) && digit_allowed){
                digit_required = false;
                sign_allowed = false;
                idx += 1;
            }else if((s[idx] == '-' || s[idx] == '+') && sign_allowed){
                sign_allowed = false;
                idx += 1;
            }else if(s[idx] == ' ' && !digit_required){
                digit_allowed = false;
                exp_allowed = false;
                sign_allowed = false;
                dot_allowed = false;
                idx += 1;
            }else{
                return false;
            }
        }
        return !digit_required;
    }
};