//找到负数与正数的分界线，双指针由内置外
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size=A.size();
        vector<int> ans;
        ans.reserve(size);
        int neg_idx=-1;
        for (int i=0;i<size;++i)
            if (A.at(i)<0)
                neg_idx=i;
            else
                break;
        int pos_zero_idx=neg_idx+1;
        while (neg_idx>=0 || pos_zero_idx<size)
        {
            if (neg_idx<0)
            {
                ans.push_back(A.at(pos_zero_idx)*A.at(pos_zero_idx));
                ++pos_zero_idx;
            }
            else if (pos_zero_idx==size)
            {
                ans.push_back(A.at(neg_idx)*A.at(neg_idx));
                --neg_idx;
            }
            else
            {
                int l=A.at(neg_idx)*A.at(neg_idx);
                int r=A.at(pos_zero_idx)*A.at(pos_zero_idx);
                if (l<r)
                {
                    ans.push_back(l);
                    --neg_idx;
                }
                else
                {
                    ans.push_back(r);
                    ++pos_zero_idx;
                }
            }
        }
        return ans;
    }
};
