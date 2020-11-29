/*
 * 既然奇数可以*2，偶数可以/2
 * 双向的的不好处理，所以都变成最大的偶数：奇数*2，偶数不变；
   就只剩单向处理即/2
 * 将所有元素加入到set中，头尾迭代器指向的就是最大值和最小值
   不断让最大值/2即单向变化
 * 枚举所有答案
 */
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        for (int i:nums)
        {
            int cur= i%2==0 ? i : i*2;
            st.insert(cur);
        }
        int mi=*st.begin();
        auto ed=prev(st.end(),1);
        int mx=*ed;
        int ans=mx-mi;
        while ((*ed)%2==0)
        {
            int t=*ed;
            st.erase(ed);
            st.insert(t/2);
            mi=*st.begin();
            ed=prev(st.end(),1);
            mx=*ed;
            ans=min(ans,mx-mi);
        }
        return ans;
    }
};
