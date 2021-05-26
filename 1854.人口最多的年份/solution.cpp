class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> vec(2050);
        for (vector<int> &i:logs) {
            int a=i.at(0),b=i.at(1);
            for (int j=a;j<b;j++) {
                vec.at(j)++;
            }
        }
        int ans=0,mx=0;
        for (int i=1950;i<2050;i++) {
            if (vec.at(i)>mx) {
                mx=vec.at(i);
                ans=i;
            }
        }
        return ans;
    }
};