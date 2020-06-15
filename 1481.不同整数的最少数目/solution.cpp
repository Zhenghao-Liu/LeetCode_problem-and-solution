class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> helper;
        for (int &i:arr)
            ++helper[i];
        vector<int> ans;
        for (auto &i:helper)
            ans.push_back(i.second);
        sort(ans.begin(),ans.end());
        int ans_size=ans.size();
        for (int i=0;i<arr.size();++i)
        {
            if (ans.at(i)<=k)
            {
                k-=ans.at(i);
                --ans_size;
            }
            else
                return ans_size;
            if (k==0)
            {
                return ans_size;
            }
        }
        return ans_size;
    }
};
