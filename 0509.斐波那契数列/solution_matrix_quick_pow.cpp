/*
* f(0)=0 f(1)=1
* f(i)=f(i-1)+f(i-2) 求f(n)，通过矩阵快速幂
* 则矩阵通项公式
A=[0 1]   即 A^n * [f(0)] = [f(n)  ]
    [1 1]            [f(1)] = [f(n+1)]
*/
//矩阵A的维度是M*M，这里是2*2
const int M=2;
//矩阵A的类
class Ma
{
public:
    int a[M][M];
    Ma()
    {
        memset(a,0,sizeof(a));
    }
    void become_unit_matrix()
    {
        //设置成单位矩阵
        for (int i=0;i<M;++i)
            for (int j=0;j<M;++j)
                a[i][j]= i==j ? 1 : 0;
    }
    void show()
    {
        cout << "----" << endl;
        cout << "Matrix is " << M << '*' << M << endl;
        for (int i=0;i<M;++i)
        {
            for (int j=0;j<M;++j)
                cout << a[i][j] << ' ';
            cout << endl;
        }
        cout << "----" << endl;
    }
    Ma operator*(const Ma &B) const
    {
        //重载两个矩阵相乘
        Ma ans;
        for (int i=0;i<M;++i)
            for (int j=0;j<M;++j)
                for (int k=0;k<M;++k)
                    ans.a[i][j]+=(this->a[i][k])*(B.a[k][j]);
        return ans;
    }
    Ma operator^(int n) const
    {
        //重载幂次运算，并结合快速幂
        Ma ans;
        //单位矩阵乘任何矩阵还是任何矩阵本身
        ans.become_unit_matrix();
        Ma A=*this;
        while(n!=0)
        {
            if ((n&1)==1)
                ans=ans*A;
            A=A*A;
            n>>=1;
        }
        return ans;
    }
};

class Solution {
public:
    int fib(int N) {
        Ma A;
        A.a[0][0]=0;
        A.a[0][1]=A.a[1][0]=A.a[1][1]=1;
        //A.show();
        Ma F;
        F.a[1][0]=1;
        //F.show();
        Ma ans=(A^N)*F;
        //ans.show();
        return ans.a[0][0];
    }
};
