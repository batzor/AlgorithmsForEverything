/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int beg = 1, end = n;
        while(beg < end){
            int mid = ((long long) beg + end) / 2;
            int ret = guess(mid);
            switch(guess(mid)){
                case -1:
                    end = mid - 1;
                    break;
                case 1:
                    beg = mid + 1;
                    break;
                case 0:
                    beg = mid;
                    end = mid;
                    break;
            }
        }
        return beg;
    }
};