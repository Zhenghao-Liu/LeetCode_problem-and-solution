// dp记录当前元素结尾是上还是下的最长湍流子数组长度
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sz=arr.size();
        int ans=1;
        vector<int> up(sz,1);
        vector<int> down(sz,1);
        for (int i=1;i<sz;i++) {
            if (arr.at(i)>arr.at(i-1)) {
                up.at(i)=down.at(i-1)+1;
            }
            if (arr.at(i)<arr.at(i-1)) {
                down.at(i)=up.at(i-1)+1;
            }
            ans=max(ans,max(down.at(i),up.at(i)));
        }
        return ans;
    }
};
