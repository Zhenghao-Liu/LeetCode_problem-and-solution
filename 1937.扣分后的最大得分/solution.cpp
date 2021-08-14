typedef long long ll;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points.at(0).size();
        vector<ll> cur(n);
        for (int i=0;i<m;i++) {
            for (int j=1;j<n;j++) {
                cur.at(j)=max(cur.at(j),cur.at(j-1)-1);
            }
            for (int j=n-2;j>=0;j--) {
                cur.at(j)=max(cur.at(j),cur.at(j+1)-1);
            }
            for (int j=0;j<n;j++) {
                cur.at(j)+=points.at(i).at(j);
            }
        }
        return *max_element(cur.begin(),cur.end());
    }
};