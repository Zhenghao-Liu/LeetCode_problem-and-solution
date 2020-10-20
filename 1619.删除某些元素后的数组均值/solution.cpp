class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int size=arr.size();
        int del=(int)(size*0.05);
        double sum=0;
        for (int i=del;i<size-del;++i)
            sum+=arr.at(i);
        return sum/(size-del-del);
    }
};
