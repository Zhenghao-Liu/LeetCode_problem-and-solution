/*
 * 线性筛：让每个数num都让 k*num的最小质因数 被筛
 * eg：12=6*2 6=3*2
 */
const int MAXN=5e6+1;
int flag[MAXN];
class Solution {
public:
    int countPrimes(int n) {
        vector<int> pri;
        memset(flag,0,sizeof(flag));
        for (int i=2;i<n;++i)
        {
            if (flag[i]==0)
                pri.push_back(i);
            for (int j=0;j<pri.size() && i*pri.at(j)<n;++j)
            {
                flag[i*pri.at(j)]=1;
                if (i%pri.at(j)==0)
                    break;
            }
        }
        return pri.size();
    }
};
