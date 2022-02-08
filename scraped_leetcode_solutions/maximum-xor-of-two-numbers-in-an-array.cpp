class TrieNode {
public:
    TrieNode* children[2];
    
public:
    TrieNode(){
        children[0] = NULL;
        children[1] = NULL;
    }
    
    int insert(int &n){
        
        bitset<32> bs(n);
        bitset<32> res(0);
        TrieNode *curr = this;
        TrieNode *max_curr = this;
        
		// start with the msb
        for (int i = 31; i >= 0; i--){
			// insert the current element
            if (!curr->children[bs[i]]){
                curr->children[bs[i]] = new TrieNode();
            }
            curr = curr->children[bs[i]];
           
            // while inserting, calculate the max xor with the other elements
            if(max_curr->children[!bs[i]]) {
				// in this case, res[i] = 1 because 0^1=1 and 1^0 = 1
                max_curr = max_curr->children[!bs[i]];
                res[i] = 1;
            }
            else{
                max_curr = max_curr->children[bs[i]];
            }
        }
        
        return static_cast<int>(res.to_ulong());
    }
    
};

class Solution {
private:
    TrieNode *root;
public:
    int findMaximumXOR(vector<int>& nums) {
        
        root = new TrieNode();
        
        int res = 0;
        for(auto i : nums) {
            res = max(res, root->insert(i));
        }
        
        return res;
    }
    
};