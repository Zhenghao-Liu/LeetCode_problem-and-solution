//是最后一次出现长度为m，那么不否反过来模拟从全1变回全0，key存左边界，value存右边界
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        if (m==n)
            return n;
        map<int,int> pos;
        pos.insert({1,n});
        for (int i=n-1;i>=0;--i)
        {
            int ii=arr.at(i);
            auto p=prev(pos.upper_bound(ii),1);
            int left=p->first;
            int right=p->second;
            pos.erase(p);
            if (ii-left==m || right-ii==m)
                return i;
            if (ii-left>0)
                pos.insert({left,ii-1});
            if (right-ii>0)
                pos.insert({ii+1,right});
        }
        return -1;
    }
};
