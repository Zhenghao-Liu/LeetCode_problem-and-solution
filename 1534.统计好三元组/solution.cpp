class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int size=arr.size();
        int ans=0;
        for (int i=0;i<size;++i)
            for (int j=i+1;j<size;++j)
                for (int k=j+1;k<size;++k)
                    if (abs(arr[i]-arr[j])<=a && abs(arr[k]-arr[j])<=b && abs(arr[k]-arr[i])<=c)
                        ++ans;
        return ans;
    }
};
