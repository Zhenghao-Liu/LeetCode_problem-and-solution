static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    string convert(string s, int numRows) {
        int length=s.size();
        if (0==length || 1==numRows)
            return s;
        string ans="";
        int increase_length=2*numRows-2;
        for (int i=0;i<length;i=i+increase_length)
            ans=ans+s.at(i);
        int judge=0,before=0;
        for (int i=1;i<numRows-1;++i)
        {
            for (int j=i;j<length;)
            {
                ans=ans+s.at(j);
                if (judge%2==0)
                {
                    before=j;
                    j=j+increase_length-i*2;
                }
                else
                    j=before+increase_length;    
                ++judge;
            }
            judge=0;
        }
        for (int i=numRows-1;i<length;i=i+increase_length)
            ans=ans+s.at(i);
        return ans;
    }
};
