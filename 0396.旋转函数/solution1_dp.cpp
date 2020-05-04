/*
* 设[a b c d e]
* f(0)=0a+1b+2c+3d+4e
* f(1)=1a+2b+3c+4d+0e
* f(2)=2a+3b+4c+0d+1e
* f(3)=3a+4b+0c+1d+2e
* f(4)=4a+0b+1c+2d+3e
* 找规律
* f(1)-f(0)=1a+1b+1c+1d-4e=sum-5e
* f(2)-f(1)=1a+1b+1c-4d+1e=sum-5d
* f(3)-f(2)=1a+1b-4c+1d+1e=sum-5c
* 类推状态方程得f(n+1)=f(n)+sum-size*[size-(n+1)]
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int A_size=A.size();
        if (A_size==0)
            return 0;
        long long sum=0;
        vector<int> dp(A_size);
        for (int i=0;i<A_size;++i)
        {
            dp.at(0)+=i*A.at(i);
            sum+=A.at(i);
        }
        int ans=dp.at(0);
        for (int i=1;i<A_size;++i)
        {
            dp.at(i)=dp.at(i-1)+(int)(sum-(long long)A_size*A.at(A_size-i));
            if (dp.at(i)>ans)
                ans=dp.at(i);
        }
        return ans;
    }
};
