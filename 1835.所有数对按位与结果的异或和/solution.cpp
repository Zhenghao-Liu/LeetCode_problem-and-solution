class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int b=0;
        for (int i:arr2) {
            b^=i;
        }
        int ans=0;
        for (int i:arr1) {
            ans^=i&b;
        }
        return ans;
    }
};