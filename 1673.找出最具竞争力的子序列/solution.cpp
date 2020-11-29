class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;
        int size=nums.size();
        int del=size-k;
        for (int i=0;i<size;++i)
        {
            int cur=nums.at(i);
            while (del>0 && !s.empty() && cur<s.top())
            {
                --del;
                s.pop();
            }
            s.push(cur);
        }
        while (s.size()>k)
            s.pop();
        vector<int> ans(k);
        for (int i=k-1;i>=0;--i)
        {
            ans.at(i)=s.top();
            s.pop();
        }
        return ans;
    }
};
