//先预处理每个节点左右两端比它小的节点个数，即假设每个点都是山顶，枚举所有山顶情况
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int size=A.size();
        vector<int> left_2_right(size,0);
        for (int i=1;i<size;++i)
            if (A.at(i)>A.at(i-1))
                left_2_right.at(i)=left_2_right.at(i-1)+1;
        vector<int> right_2_left(size,0);
        for (int i=size-2;i>=0;--i)
            if (A.at(i)>A.at(i+1))
                right_2_left.at(i)=right_2_left.at(i+1)+1;
        int ans=0;
        for (int i=1;i<size-1;++i)
        {
            int a=left_2_right.at(i);
            int b=right_2_left.at(i);
            if (a!=0 && b!=0)
                ans=max(ans,a+b+1);
        }
        return ans;
    }
};
