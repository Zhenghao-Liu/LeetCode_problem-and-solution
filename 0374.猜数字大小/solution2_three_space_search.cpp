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
        int left=1,right=n;
        while (left<=right)
        {
            int m1=left+(right-left)/3;
            int m2=right-(right-left)/3;
            int result1=guess(m1);
            int result2=guess(m2);
            if (result1==0)
                return m1;
            else if (result2==0)
                return m2;
            else if (result1<0)
                right=m1-1;
            else if (result2>0)
                left=m2+1;
            else
            {
                left=m1+1;
                right=m2-1;
            }
        }
        return left;
    }
};
