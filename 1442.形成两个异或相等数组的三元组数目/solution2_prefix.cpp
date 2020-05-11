//注意helper.at(j)^helper.at(i)) == (helper.at(j)^helper.at(k+1)
//等号两边同时都有helper[j]那就意味着j这一层循环可以省去，只做i和k循环就好了
//缩减成helper[i]==helper[k+1]
//然后要找这中间符合的j有多少个
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> helper{0};
        for (int i=0;i<arr.size();++i)
            helper.push_back(helper.back()^arr.at(i));
        int ans=0;
        for (int i=0;i<arr.size();++i)
            for (int k=i+1;k<arr.size();++k)
                if (helper.at(i) == helper.at(k+1))
                    ans+=k-i;
        return ans;
    }
};
