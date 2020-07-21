/*
* 因为arr[i]<=1e6，而最多2^20>1e6，而且与运算1能变成1、0，但是0只能变成0，
  因此实际下来与运算的结果的可能性是在常数范围内的
* 那么直接通过集合去重，即可做到大量的优化
*/
class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int arr_size=arr.size();
        int ans=INT_MAX;
        unordered_set<int> prev;
        unordered_set<int> cur;
        for (int i=0;i<arr_size;++i)
        {
            cur.clear();
            ans=min(ans,abs(target-arr.at(i)));
            cur.insert(arr.at(i));
            for (int j:prev)
            {
                int t=j&arr.at(i);
                cur.insert(t);
                ans=min(ans,abs(target-t));
            }
            prev=cur;
        }
        return ans;
    }
};
