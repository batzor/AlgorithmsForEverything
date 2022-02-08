class Node {
public:
    char c;
    unordered_map<char, Node*> children;
    Node(char ch){
        c = ch;
    }
};

class WordDictionary {
public: 
    unordered_map<char, Node*> root;
    WordDictionary() {
    }
    
    void addWord(string word) {
        word = word + "\n";
        int idx = 0;
        unordered_map<char, Node*> *cur = &root;
        while(idx < word.length()){
            if(cur->find(word[idx]) != cur->end()){
                cur = &(*cur)[word[idx]]->children;
                ++idx;
            }else{
                break;
            }
        }
        while(idx < word.length()){
            (*cur)[word[idx]] = new Node(word[idx]);
            cur = &(*cur)[word[idx]]->children;
            ++idx;
        }
    }
    
    bool search(string word) {
        word = word + '\n';
        return searchFromChildren(word, root);
    }
    
    bool searchFromChildren(string word, unordered_map<char, Node*> &children){
        if(word.length() == 0)
            return true;
        if(word[0] == '.'){
            bool ans = false;
            string new_str = word.substr(1, word.length() - 1);
            for(auto p: children){
                ans = ans || searchFromChildren(new_str, p.second->children);
            }
            return ans;
        }
        if(children.find(word[0]) == children.end())
            return false;
        else
            return searchFromChildren(word.substr(1, word.length() - 1), children[word[0]]->children);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */