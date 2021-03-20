class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n!=0) {
            int cur=n%3;
            if (!(cur==0 || cur==1)) {
                return false;
            }
            n/=3;
        }
        return true;
    }
};
