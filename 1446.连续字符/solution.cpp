class Solution {
public:
    int maxPower(string s) {
        int s_size=s.size();
        int ans=0;
        for (int i=0;i<s_size;)
        {
            char target=s.at(i);
            int count=0,j;
            for (j=i;j<s_size;++j)
                if (s.at(j)==target)
                    ++count;
                else
                    break;
            if (count>ans)
                ans=count;
            i=j;
        }
        return ans;
    }
};
