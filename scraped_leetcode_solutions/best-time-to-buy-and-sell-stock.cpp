class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int min_price = prices[0];
        int max_price = INT_MIN;
        for(int i = 1;i < prices.size();++i){
            if(max_price < prices[i]){
                max_price = prices[i];
                max_prof = max(max_prof, max_price - min_price);
            }
            if(min_price > prices[i]){
                min_price = prices[i];
                max_price = 0;
            }
        }
        return max_prof;
    }
};