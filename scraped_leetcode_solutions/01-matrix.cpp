class Solution {
public:
    
    inline bool check(vector<vector<int>> &ret, int i, int j){
        bool ans = true;
        if(i > 0)
            ans &= ret[i - 1][j] >= ret[i][j];
        if(j > 0)
            ans &= ret[i][j - 1] >= ret[i][j];
        if(i < ret.size() - 1)
            ans &= ret[i + 1][j] >= ret[i][j];
        if(j < ret[0].size() - 1)
            ans &= ret[i][j + 1] >= ret[i][j];
        return ans;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ret = mat;
        queue<pair<int, int>> q;
        for(int i = 0;i < ret.size();i++){
            for(int j = 0;j < ret[0].size();j++){
                if(ret[i][j] == 1)
                    q.push(pair{i, j});                   
            }
        }
        
        while(!q.empty()){
            int n = q.size();
            for(int x = 0;x < n;x++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(check(ret, i, j)){
                    ret[i][j] += 1;
                    q.push({i, j});
                }
            }
        }
        return ret;
    }
};