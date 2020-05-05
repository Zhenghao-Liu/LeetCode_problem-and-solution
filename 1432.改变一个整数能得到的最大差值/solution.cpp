class Solution {
public:
    int maxDiff(int num) {
        int ans=INT_MIN;
        vector<int> helper;
        for (int i=0;i<=9;++i)
            for (int j=0;j<=9;++j)
            {
                string a=to_string(num);
                for (char &k:a)
                    if (k==i+'0')
                        k=j+'0';
                if (a.at(0)!='0')
                    helper.push_back(stoi(a));
            }
        int helper_size=helper.size();
        for (int i=0;i<helper_size;++i)
            for (int j=i+1;j<helper_size;++j)
            {
                int temp=abs(helper.at(i)-helper.at(j));
                if (temp>ans)
                    ans=temp;
            }
        return ans;
    }
};
