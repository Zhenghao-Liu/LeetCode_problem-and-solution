class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n>45 || k<=0)
            return {};
        vector<vector<int>> answer;
        find_substr(k,n,answer,{},1,0);
        return answer;
    }
    //和为n，k个数，组合中只允许1-9，且不重复
    void find_substr(const int &k,const int &n,vector<vector<int>>& answer,vector<int> ans,int begin,int sum)
    {
        for (int i=begin;i<10;++i)
        {
            if (i!=begin && !ans.empty() && i==ans.back() )
                continue;
            ans.push_back(i);
            sum=sum+i;
            if (sum==n && ans.size()==k)
            {
                answer.push_back(ans);
                return;
            }
            else if (sum<n && ans.size()<k)
                find_substr(k,n,answer,ans,i+1,sum);
            ans.pop_back();
            sum=sum-i;
        }
    }
};
