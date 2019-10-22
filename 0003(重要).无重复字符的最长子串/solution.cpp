static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=s.size();
        if (0==length || 1==length)
            return length;
        string ans;
        ans.assign(s,0,1);
        int answer=1;
        for (int i=1;i<length;++i)
        {
            for (int j=i;j<length;++j)
                if (ans.find(s.at(j))==-1)
                    ans.append(s,j,1);
                else
                    break;
            answer=(ans.size()>answer?ans.size():answer);
            ans.assign(s,i,1);
        }
        return answer;
    }
};
