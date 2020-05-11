//前缀和然后暴力
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> helper{0};
        for (int i=0;i<arr.size();++i)
            helper.push_back(helper.back()^arr.at(i));
        int ans=0;
        for (int i=0;i<arr.size();++i)
            for (int j=i+1;j<arr.size();++j)
                for (int k=j;k<arr.size();++k)
                    if ((helper.at(j)^helper.at(i)) == (helper.at(j)^helper.at(k+1)))
                        ++ans;
        return ans;
    }
};
