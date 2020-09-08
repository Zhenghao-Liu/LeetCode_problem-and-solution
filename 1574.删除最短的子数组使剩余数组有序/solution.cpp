class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (is_sorted(arr.begin(),arr.end()))
            return 0;
        int size=arr.size();
        int l=0;
        while (arr.at(l)<=arr.at(l+1))
            ++l;
        int r=size-1;
        while (arr.at(r)>=arr.at(r-1))
            --r;
        int ans=min(size-l-1,r);
        for (int i=0,j=r;i<=l && j<size;++i)
        {
            while (j<size && arr.at(i)>arr.at(j))
                ++j;
            if (j<size)
                ans=min(ans,j-i-1);
        }
        return ans;
    }
};
