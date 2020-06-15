//答案必然是花开放天数中的一个，那就通过二分去枚举满足制作花束的最小天数即可
class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        int bd_size=bd.size();
        if (m*k>bd_size)
            return -1;
        set<int> temp;
        for (int &i:bd)
            temp.insert(i);
        vector<int> v(temp.begin(),temp.end());
        int v_size=v.size();
        int left=0,right=v_size-1;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            int line=v.at(mid);
            int cur_m=0;
            for (int i=0;i<bd_size;++i)
            {
                if (bd[i]<=line)
                {
                    int start=i;
                    while (i<bd_size && bd[i]<=line)
                        ++i;
                    cur_m+=(i-start)/k;
                }
            }
            if (cur_m>=m)
                right=mid;
            else
                left=mid+1;
        }
        return v.at(left);
    }
};
