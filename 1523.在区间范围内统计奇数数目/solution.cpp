/*
* 考虑四种情况
* 1. 1 2 3
* 2. 2 3 4
* 3. 1 2 3 4
* 4. 2 3 4 5
* 即总数是奇数还是偶数+第一个数是奇数还是偶数
*/
class Solution {
public:
    int countOdds(int low, int high) {
        int i=high-low+1;
        if (i%2==0)
        {
            return i/2;
        }
        else
        {
            if (low%2==0)
                return i/2;
            else
                return i/2+1;
        }    
        return 0;  
    }
};
