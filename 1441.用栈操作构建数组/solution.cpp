class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int index=0;
        vector<int> mask;
        for (int i=1;i<=n;++i)
            mask.push_back(i);
        for (int i=0;i<target.size();++i)
        {
            if (target.at(i)!=mask.at(index))
            {
                while (target.at(i)!=mask.at(index))
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    ++index;
                }
            }
            ans.push_back("Push");
            ++index;
        }
        return ans; 
    }
};
