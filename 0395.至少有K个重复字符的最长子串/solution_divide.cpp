class Solution {
public:
    int longestSubstring(string s, int k) {
        int s_size=s.size();
        if (s_size==0)
            return 0;
        vector<int> occurrences(26,0);
        //统计下每个字母出现的次数
        for (char &i:s)
            ++occurrences.at(i-'a');
        vector<int> split;
        //若字母出现的次数小于k，则最后答案的子字符串必然不包含该字母
        //可以将该字母设为字符串s的分割点，即end，然后分治一个一个子部分
        for (int i=0;i<s_size;++i)
            if (occurrences.at(s.at(i)-'a')<k)
                split.push_back(i);
        //倘若所有字符都满足出现次数>=k则答案即s_size
        if (split.empty())
            return s_size;
        //因为split存的都是子串的end，所以最后一个子串也要加上
        split.push_back(s_size);
        int start=0;
        int ans=0;
        for (int &i:split)
        {
            int length=i-start;
            //小剪枝
            if (length>ans)
                ans=max(ans,longestSubstring(s.substr(start,length),k));
            start=i+1;
        }
        return ans;
    }
};
