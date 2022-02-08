class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); i++){
            triangle[i][0] += triangle[i - 1][0];
            triangle[i].back() += triangle[i - 1].back();
            for(int j = 1; j < triangle[i].size() - 1; j++){
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }  
        }
        int ans = INT_MAX;
        for(int num: triangle.back()){
            if(ans > num)
                ans = num;
        }
        return ans;
    }
};