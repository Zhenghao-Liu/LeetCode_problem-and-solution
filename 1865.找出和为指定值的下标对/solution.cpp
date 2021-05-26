class FindSumPairs {
    unordered_map<int,int> ump,ump2;
    vector<int> nums;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ump.clear();
        for (int i:nums1) {
            ump[i]++;
        }
        ump2.clear();
        for (int i:nums2) {
            ump2[i]++;
        }
        nums=nums2;
    }
    
    void add(int index, int val) {
        ump2[nums.at(index)]--;
        ump2[nums.at(index)+val]++;
        nums.at(index)+=val;
    }
    
    int count(int tot) {
        int ans=0;
        for (auto &i:ump) {
            auto [v,c]=i;
            auto p=ump2.find(tot-v);
            if (p!=ump2.end()) {
                ans+=c*(p->second);
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */