class Solution {
public:
    int minimumOneBitOperations(int n) {
        return dfs_0(n);
    }
    int dfs_0(int n)
    {
        if (n<=1)
            return n;
        if (is_power_of_2(n))
            return highbit(n)*2-1;
        int highbit_n=highbit(n);
        int otherbit_n=n&(highbit_n-1);
        return 1+dfs_10x0(otherbit_n,highbit_n-1)+highbit_n-1;
    }
    int dfs_10x0(int n,int ALL)
    {
        int highbit_ALL=highbit(ALL);
        if (n==highbit_ALL)
            return 0;
        int otherbit_n=n&(highbit_ALL-1);
        if ((n&highbit_ALL)!=0)
            return dfs_0(otherbit_n);
        else
            return 1+dfs_10x0(otherbit_n,highbit_ALL-1)+highbit_ALL-1;
        return -1;
    }
    bool is_power_of_2(int x){return (x!=0) && (x&(x-1))==0;}
    int lowbit(int x){return x&(-x);}
    int highbit(int x)
    {
        int p=lowbit(x);
        while (p!=x)
        {
            x-=p;
            p=lowbit(x);
        }
        return p;
    }
};
