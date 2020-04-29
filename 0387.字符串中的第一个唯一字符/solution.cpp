class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> times(26,0);
        for (char &i:s)
            ++times.at(i-'a');
        int s_size=s.size();
        for (int i=0;i<s_size;++i)
            if (times.at(s.at(i)-'a')==1)
                return i;
        return -1;
    }
};
