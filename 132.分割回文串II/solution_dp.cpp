class Solution {
public:
    int minCut(string s) {
        int s_size=s.size();
        vector<int> dp(s_size);
        vector<vector<bool>> judge_palindrome(s_size,vector<bool>(s_size,false));
        dp.at(0)=0;
        for (int i=1;i<s_size;++i)
        {
            dp.at(i)=i;
            for (int j=0;j<=i;++j)
                if (s.at(i)==s.at(j) && (j+1>i-1 || judge_palindrome.at(j+1).at(i-1)))
                    if (j!=0)
                    {
                        dp.at(i)=min(dp.at(i),dp.at(j-1)+1);
                        judge_palindrome.at(j).at(i)=true;
                    }
                    else
                    {
                        dp.at(i)=0;
                        judge_palindrome.at(j).at(i)=true;
                    }      
        }
        return dp.at(s_size-1);
    }
};
