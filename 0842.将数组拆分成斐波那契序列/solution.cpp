typedef long long ll;
class Solution {
    vector<int> ans;
    string key;
public:
    vector<int> splitIntoFibonacci(string S) {
        ans.clear();
        ll a=0,b=0;
        ll sum=0;
        int size=S.size();
        for (int i=0;i<size;++i)
        {
            a=a*10+(S.at(i)-'0');
            if (a>INT_MAX)
                return {};
            b=0;
            for (int j=i+1;j<size;++j)
            {
                b=b*10+(S.at(j)-'0');
                if (b>INT_MAX)
                    break;
                ans.push_back(a);
                ans.push_back(b);
                if (check(S,a,b,j+1))
                    return ans;
                ans.pop_back();
                ans.pop_back();
                if (b==0)
                    break;
            }
            if (a==0)
                break;
        }
        return {};
    }
    bool check(string &S,ll a,ll b,int st)
    {
        int S_size=S.size();
        if (st==S_size)
            return ans.size()>=3;
        ll sum=a+b;
        if (sum>INT_MAX)
            return false;
        key=to_string(sum);
        int key_size=key.size();
        int i=0;
        for (i=0;st+i<S_size && i<key_size;++i)
            if (key.at(i)!=S.at(st+i))
                break;
        if (i==key_size)
        {
            ans.push_back(sum);
            if (check(S,b,sum,st+key_size))
                return true;
            ans.pop_back();
        }
        return false;
    }
};
