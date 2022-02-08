class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        pair<int, char> ret = {releaseTimes[0], keysPressed[0]};
        for(int i = 0;i < releaseTimes.size() - 1;++i){
            int len =  releaseTimes[i + 1] - releaseTimes[i];
            if(ret.first < len)
                ret = {len, keysPressed[i + 1]};
            if(ret.first == len && ret.second < keysPressed[i + 1])
                ret.second = keysPressed[i + 1];
            
        }
        return ret.second;
    }
};