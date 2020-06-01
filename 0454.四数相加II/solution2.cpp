//优化
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> a_sum_b;
        for (int &i:A)
            for (int &j:B)
                ++a_sum_b[i+j];
        int ans=0;
        for (int &i:C)
            for (int &j:D)
                if (a_sum_b.find(-i-j)!=a_sum_b.end())
                    ans+=a_sum_b.at(-i-j);
        return ans;
    }
};
