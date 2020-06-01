//A+B+C+D=0变成A+B=-(C+D)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> a_sum_b;
        for (int &i:A)
            for (int &j:B)
                ++a_sum_b[i+j];
        unordered_map<int,int> c_sum_d;
        for (int &i:C)
            for (int &j:D)
                ++c_sum_d[i+j];
        int ans=0;
        for (auto &i:a_sum_b)
        {
            if (c_sum_d.find(-(i.first))!=c_sum_d.end())
                ans+=c_sum_d.at(-(i.first))*i.second;
        }
        return ans;
    }
};
