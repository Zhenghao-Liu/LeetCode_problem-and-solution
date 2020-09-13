//双指针，先排序两个数组，让a+b<=x，a是s中元素，a逐渐变大，要想维护不等式，只能b逐渐变小
class Solution {
    int mod=1e9+7;
public:
    int breakfastNumber(vector<int>& s, vector<int>& d, int x) {
        sort(s.begin(),s.end());
        sort(d.begin(),d.end());
        int ans=0;
        int r=d.size()-1;
        for (int i:s)
        {
            while (r>=0 && i+d.at(r)>x)
                --r;
            ans+=r+1;
            ans%=mod;
        }
        return ans;
    }
};
