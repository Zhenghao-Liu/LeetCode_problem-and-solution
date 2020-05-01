//当数据量过大时，可存下每个字母出现的位置
//已经匹配一个字符后，即可在下一个要匹配字母所出现的位置中，找到下一个位置
//因为位置是放进去时候就是从左往右，所以是有序的，采用二分优化
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> hash(26);
        int t_size=t.size();
        for (int i=0;i<t_size;++i)
            hash.at(t.at(i)-'a').push_back(i);
        int index=-1;
        for (char &i:s)
        {
            vector<int>::iterator p=upper_bound(hash.at(i-'a').begin(),hash.at(i-'a').end(),index);
            if (p==hash.at(i-'a').end())
                return false;
            index=*p;
        }
        return true;
    }
};
