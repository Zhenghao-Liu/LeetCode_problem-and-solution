//既然是连续出现的，那就确定好前两个数，然后一直去试
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int A_size=A.size();
        int ans=0;
        for (int i=0;i<A_size-2;++i)
        {
            int diff=A.at(i+1)-A.at(i);
            int k=i+2;
            for (;k<A_size;++k)
                if (A.at(k)-A.at(k-1)!=diff)
                    break;
            ans+=k-(i+2);
        }
        return ans;
    }
};
