class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length() == 0)
            return s.length() == 0;
        
        bool first_match = (!s.length() == 0) && (p[0] == '.' || p[0] == s[0]);
        if(p.length() > 1 && p[1] == '*'){
            return isMatch(s, p.substr(2,p.length() - 2)) || 
                (first_match && isMatch(s.substr(1, s.length() - 1), p));
        }else{
            return (first_match && isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1)));
        }    
    }
};