class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // b, a, l, o, n
        int cnt[5] = {0};
        for(char c: text){
            switch(c){
                case 'b' :
                    ++cnt[0];
                    break;
                case 'a' :
                    ++cnt[1];
                    break;
                case 'l' :
                    ++cnt[2];
                    break;
                case 'o' :
                    ++cnt[3];
                    break;
                case 'n' :
                    ++cnt[4];
                    break;
                default:
                    break;
            }
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        cnt[0] = min(cnt[0], cnt[1]);
        cnt[0] = min(cnt[0], cnt[2]);
        cnt[0] = min(cnt[0], cnt[3]);
        cnt[0] = min(cnt[0], cnt[4]);
        return cnt[0];
        
    }
};