class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int vectorSum = 0;
        int maxLeft = 0, maxRight = 0;
        int l = -1, r = arr.size();
        for(int i = 0;i < arr.size();i++){
            vectorSum += arr[i];
            if(maxLeft < vectorSum){
                maxLeft = vectorSum;
                l = i;
            }
        }
        int tmpSum = 0;
        for(int i = arr.size() - 1;i >= 0;i--){
            tmpSum += arr[i];
            if(tmpSum > maxRight){
                maxRight = tmpSum; 
                r = i;
            }
        }
        
        int maxVector = 0;
        tmpSum = 0;
        int start = 0;
        for(int i = 0;i < arr.size();i++){
            tmpSum += arr[i];
            while(tmpSum < 0){
                tmpSum -= arr[start];
                start++;
            }
            if(tmpSum > maxVector){
                cout << start << " " << i << endl;
                maxVector = tmpSum;
            }
        }
        cout << maxVector << "\n";
        cout << maxLeft << "\n";
        cout << maxRight << endl;
        if(k == 1)
            return maxVector;
        else{
            int ret = 0;
            if(maxLeft > 0){
                ret += maxLeft;
                ret %= ((int) pow(10, 9) + 7);
            }
            if(maxRight > 0){
                ret += maxRight;
                ret %= ((int) pow(10, 9) + 7);
            }
            if(vectorSum > 0)
                for(int i = 0; i < k - 2;i++){
                    ret += vectorSum;
                    ret %= ((int) pow(10, 9) + 7);
                }
            if(ret < maxVector)
                ret = maxVector;
            return ret;
        }
    }
};