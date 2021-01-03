class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)>B.at(1);
        });
        int ans=0;
        for (vector<int> &i:b) {
            int cnt=i.at(0);
            int val=i.at(1);
            int get=min(t,cnt);
            t-=get;
            ans+=get*val;
        }
        return ans;
    }
};
