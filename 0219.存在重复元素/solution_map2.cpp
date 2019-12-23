class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int nums_size=nums.size();
        unordered_map<int,vector<int>> all_p;
        for (int i=0;i<nums_size;++i)
            all_p[nums.at(i)].push_back(i);
        for (auto& i:all_p)
        {
            int size=i.second.size();
            if (size==1)
                continue;
            sort(i.second.begin(),i.second.end());
            for (int j=1;j<size;++j)
                if (i.second.at(j)-i.second.at(j-1)<=k)
                    return true;
        }
        return false;
    }
};
