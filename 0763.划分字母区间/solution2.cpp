class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        memset(last,0x3f,sizeof(last));
        int size=S.size();
        for (int i=0;i<size;++i)
        {
            int idx=S.at(i)-'a';
            last[idx]=i;
        }
        vector<int> ans;
        int start=-1;
        int end=-1;
        for (int i=0;i<size;++i)
        {
            int idx=S.at(i)-'a';
            end=max(end,last[idx]);
            if (i==end)
            {
                ans.push_back(end-start);
                start=i;
            }
        }
        return ans;
    }
};
