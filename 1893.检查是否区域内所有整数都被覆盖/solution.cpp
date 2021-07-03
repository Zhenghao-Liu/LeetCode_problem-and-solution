class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> vec(200);
        for (vector<int> &i:ranges) {
            for (int a=i.at(0);a<=i.at(1);a++) {
                vec.at(a)=1;
            }
        }
        for (int i=left;i<=right;i++) {
            if (vec.at(i)==0) {
                return false;
            }
        }
        return true;
    }
};