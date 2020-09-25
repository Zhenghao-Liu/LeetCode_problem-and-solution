class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size=arr.size();
        vector<int> prefix(size+1);
        for (int i=0;i<size;++i)
            prefix.at(i+1)=prefix.at(i)+arr.at(i);
        //[i,j]=prefix[j+1]-prefix[i]
        int ans=0;
        for (int i=0;i<size;++i)
            for (int j=i;j<size;j+=2)
                ans+=prefix.at(j+1)-prefix.at(i);
        return ans;
    }
};
