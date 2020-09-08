typedef long long ll;
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<ll,int> a;
        for (int i:nums1)
        {
            long long ii=(long long)i*i;
            ++a[ii];
        }
        int size=nums2.size();
        int ans=0;
        for (int i=0;i<size;++i)
            for (int j=i+1;j<size;++j)
            {
                long long ii=nums2.at(i);
                long long jj=nums2.at(j);
                long long p=ii*jj;
                if (a.find(p)!=a.end())
                    ans+=a.at(p);
            }
        return ans+help(nums2,nums1);
    }
    int help(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<ll,int> a;
        for (int i:nums1)
        {
            long long ii=(long long)i*i;
            ++a[ii];
        }
        int size=nums2.size();
        int ans=0;
        for (int i=0;i<size;++i)
            for (int j=i+1;j<size;++j)
            {
                long long ii=nums2.at(i);
                long long jj=nums2.at(j);
                long long p=ii*jj;
                if (a.find(p)!=a.end())
                    ans+=a.at(p);
            }
        return ans;
    }
};
