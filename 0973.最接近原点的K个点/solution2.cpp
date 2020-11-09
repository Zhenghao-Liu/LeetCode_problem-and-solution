class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(0)*A.at(0)+A.at(1)*A.at(1)<B.at(0)*B.at(0)+B.at(1)*B.at(1);
        });
        return vector<vector<int>>(points.begin(),points.begin()+K);
    }
};
