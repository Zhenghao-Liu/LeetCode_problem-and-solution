class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int sz=triplets.size();
        vector<int> idx(sz);
        for (int i=0;i<sz;i++) {
            idx.at(i)=i;
        }
        for (int num=0;num<3;num++) {
            int up=target.at(num);
            sort(idx.begin(),idx.end(),[&triplets,num](const int &A,const int &B){
                return triplets.at(A).at(num)<triplets.at(B).at(num);
            });
            int csz=idx.size();
            for (int i=csz-1;i>=0;i--) {
                int ii=idx.at(i);
                if (triplets.at(ii).at(num)>up) {
                    idx.pop_back();
                } else {
                    break;
                }
            }
        }
        int a=0,b=0,c=0;
        for (int i:idx) {
            a=max(a,triplets.at(i).at(0));
            b=max(b,triplets.at(i).at(1));
            c=max(c,triplets.at(i).at(2));
        }
        return target==vector<int>{a,b,c};
    }
};