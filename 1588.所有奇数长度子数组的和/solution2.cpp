class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size=arr.size();
        int ans=0;
        for (int i=0;i<size;++i)
        {
            int sum=arr.at(i);
            ans+=sum;
            for (int j=i+2;j<size;j+=2)
            {
                sum+=arr.at(j)+arr.at(j-1);
                ans+=sum;
            }
        }  
        return ans;
    }
};
