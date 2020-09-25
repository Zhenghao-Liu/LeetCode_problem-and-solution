/*
* 现在是n*n的格子矩阵
* 1. 涂i行，则会涂i*n个格子
  2. 涂j列，则会涂j*n个格子
  3. 但是涂行和涂列会导致格子有i*j个重复
  4. 所以涂i行，涂j列的总格子数是i*n+j*n-i*j
* 所以只要满足涂格子数i*n+j*n-i*j==k，即该种涂法有效
  那现在知道总共要涂几行，那如何分配去涂哪些行？
  就用到组合数$C_{n}^{m}$即comb[n][m]
  即该涂法总共有$C_{n}^{i}*C_{n}^{j}$种
* 此外对于不涂和涂满矩形要特判
*/
const int MAXN=6+1;
bool already_build=false;
//$C_{n}^{m}$即comb[n][m]
//上面是m，下面是n
int comb[MAXN][MAXN];
void build_comb(int limit)
{
    if (already_build)
        return;
    //memset(comb,0,sizeof(comb));
    for (int n=1;n<=limit;++n)
        for (int m=0;m<=n;++m)
        {
            if (m==n || m==0)
                comb[n][m]=1;
            else
                comb[n][m]=comb[n-1][m]+comb[n-1][m-1];
        }
    already_build=true;
}
class Solution {
public:
    int paintingPlan(int n, int k) {
        if (k==0 || k==n*n)
            return 1;
        build_comb(MAXN-1);
        int ans=0;
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                if (n*i+n*j-i*j==k)
                    ans+=comb[n][i]*comb[n][j];
        return ans;
    }
};
