class Solution {
public:
    int clumsy(int N) {
        vector<int> ans{N};
        ans.reserve(N);
        N--;
        int idx=-1;
        while (N!=0) {
            idx=(idx+1)%4;
            switch (idx) {
                case 0:
                    ans.back()*=N;
                    break;
                case 1:
                    ans.back()/=N;
                    break;
                case 2:
                    ans.push_back(N);
                    break;
                case 3:
                    ans.push_back(-N);
                    break;                
            }
            N--;
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};