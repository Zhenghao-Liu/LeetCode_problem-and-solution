class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int m=arr.at((n-1)/2);
        sort(arr.begin(),arr.end(),[&](const int &a,const int &b)->bool{
            int aa=abs(a-m);
            int bb=abs(b-m);
            return aa==bb ? a>b : aa>bb;
        });
        return vector<int>(arr.begin(),arr.begin()+k);
    }
};
