class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> a(arr.begin(),arr.end());
        int index=0;
        for (int i=1;index!=k;++i)
            if (a.find(i)==a.end())
            {
                ++index;
                if (index==k)
                    return i;
            }
        return -1;
    }
};
