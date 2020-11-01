//枚举山脚
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans=0;
        int size=A.size();
        int l=0,r;
        while (l+2<size)
        {
            r=l;
            while (r+1<size && A.at(r)<A.at(r+1))
                ++r;
            if (r!=l && r+1<size && A.at(r)>A.at(r+1))
            {
                while(r+1<size && A.at(r)>A.at(r+1))
                    ++r;
                ans=max(ans,r-l+1);
            }
            else
                ++r;
            l=r;
        }
        return ans;
    }
};
