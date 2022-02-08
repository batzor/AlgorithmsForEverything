class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = min(height[left], height[right]) * (right - left);
        while(left != right){
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
            ans = max(ans, min(height[left], height[right]) * (right - left));
        }
        return ans;
    }
};