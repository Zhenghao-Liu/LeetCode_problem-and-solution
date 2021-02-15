// X-a+b=Y-b+a 即 b=(Y-X+2a)/2
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumB=0;
        unordered_set<int> ust;
        for (int i:B) {
            ust.insert(i);
            sumB+=i;
        }
        int sumA=accumulate(A.begin(),A.end(),0);
        for (int i:A) {
            int tar=sumB-sumA+2*i;
            if (tar%2==0 && ust.find(tar/2)!=ust.end()) {
                return {i,tar/2};
            }
        }
        return {-1,-1};
    }
};
