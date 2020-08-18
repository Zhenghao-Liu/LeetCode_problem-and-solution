//直接按照差值排序，若差值相同则更小的在前面，最后截断之后再重新排序即可
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end(),[x](const int &A,const int &B)->bool{
            int A_diff=abs(A-x);
            int B_diff=abs(B-x);
            return A_diff==B_diff ? A<B : A_diff<B_diff;
        });
        vector<int> ans(arr.begin(),arr.begin()+k);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
