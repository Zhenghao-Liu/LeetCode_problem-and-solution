class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sz=arr.size();
        arr.at(0)=1;
        for (int i=1;i<sz;i++) {
            arr.at(i)=min(arr.at(i),arr.at(i-1)+1);
        }
        return arr.back();
    }
};