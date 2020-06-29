/*
* 对arr中每个元素%k后，要想和能被k整除，和只有-k、0、k三种可能
* 若(a+b)%k==0 (c+d)%k==0，现在(a+d)%k==0，则必然(c+b)%k==0
  因为d=nk+b，那么c+b=c+d-nk
  所以只要找到有匹配的就不用担心发生冲突的情况
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if (k==1)
            return true;
        for (int &i:arr)
            i%=k;
        multiset<int> num{arr.begin(),arr.end()};
        vector<int> target{-k,0,k};
        auto cur=num.begin();
        while (cur!=num.end())
        {
            int val=*cur;
            num.erase(cur);
            bool judge=false;
            for (int i:target)
            {
                auto p=num.lower_bound(i-val);
                if (p!=num.end() && *p==i-val)
                {
                    num.erase(p);
                    judge=true;
                    break;
                }
            }
            if (!judge)
                return false;
            cur=num.begin();
        }
        return true;
    }
};
