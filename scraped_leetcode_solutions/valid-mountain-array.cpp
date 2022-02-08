class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3)
            return false;
        int prev = arr[0];
        int i = 1;
        while(i < arr.size() && arr[i] > prev){
            prev = arr[i];
            ++i;
        }
        if(i == 1 || i == arr.size())
            return false;
        
        while(i < arr.size() && arr[i] < prev){
            prev = arr[i];
            ++i;
        }
        return i == arr.size();
    }
};