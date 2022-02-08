class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_set<string> st;
        istringstream is(s);
        string word;
        for(int i = 0;i < pattern.length();++i){
            if(!getline(is, word, ' '))
                return false;
            if(m.find(pattern[i]) == m.end()){
                m[pattern[i]] = word;
                if(st.find(word) != st.end())
                    return false;
                else
                    st.insert(word);
            }else if(m[pattern[i]] != word)
                return false;
        }
        if(getline(is, word, ' '))
            return false;
        
        return true;
    }
};