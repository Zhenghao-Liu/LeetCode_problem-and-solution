class Solution {
public:
    int numSplits(string s) {
        int size=s.size();
        int ans=0;
        vector<int> left(26);
        vector<int> right(26);
        for (char i:s)
            ++right.at(i-'a');
        for (int i=0;i<size-1;++i)
        {
            ++left.at(s.at(i)-'a');
            --right.at(s.at(i)-'a');
            int l=0,r=0;
            for (int j=0;j<26;++j)
                if (left.at(j)==0 && right.at(j)!=0)
                    ++l;
                else if (right.at(j)==0 && left.at(j)!=0)
                    ++r;
            if (l==r)
                ++ans;
        }
        return ans;
    }
};
