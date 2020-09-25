//模拟即可
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i=left;i<=right;++i)
            if (helper(i))
                ans.push_back(i);
        return ans;
    }
    bool helper(int num)
    {
        int n=num;
        while (n!=0)
        {
            int c=n%10;
            n/=10;
            if (c==0 || num%c!=0)
                return false;
        }
        return true;
    }
};
