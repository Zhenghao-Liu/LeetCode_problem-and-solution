//贪心的把出现次数做多的字符先放
//其次可以用出现最多的字符的次数a,总长b，若a>(b+1)/2则一定不行
class Solution {
public:
    string reorganizeString(string S) {
        int cnt[26]={0};
        for (char c:S)
        {
            int idx=c-'a';
            ++cnt[idx];
        }
        auto func=[&cnt](const int &A,const int &B){
            return cnt[A]<cnt[B];
        };
        priority_queue<int,vector<int>,decltype(func)> pq(func);
        for (int i=0;i<26;++i)
            if (cnt[i]!=0)
                pq.push(i);
        int prev=-1;
        string ans;
        while (!pq.empty())
        {
            int cur1=pq.top();
            pq.pop();
            if (cur1!=prev)
            {
                ans+=char('a'+cur1);
                prev=cur1;
                --cnt[cur1];
                if (cnt[cur1]!=0)
                    pq.push(cur1);
                continue;
            }
            if (pq.empty())
                return "";
            int cur2=pq.top();
            pq.pop();
            if (cur2!=prev)
            {
                pq.push(cur1);
                ans+=char('a'+cur2);
                prev=cur2;
                --cnt[cur2];
                if (cnt[cur2]!=0)
                    pq.push(cur2);
                continue;
            }
            return "";
        }
        return ans;
    }
};
