/*
* 对于fibo[i]=fibo[i-1]+fibo[i-2]，所以倘若能用两个连续斐波那契数表示一个数，必然能单用一个斐波那契数来表示
* 对于fibo[i+1]=fibo[i]+fibo[i-1]所以2*fibo[i]=fibo[i+1]+fibo[i-2]所以两个相同的斐波那契数也必然能用两个一大一小的数来表示
*/
class Solution {
public:
    unordered_map<int,int> cache;
    int findMinFibonacciNumbers(int k) {
        vector<int> helper{1,1};
        int left=1,right=1;
        while (right<k)
        {
            int next=left+right;
            helper.push_back(next);
            left=right;
            right=next;
        }
        reverse(helper.begin(),helper.end());
        int ans=0;
        for (int &i:helper)
        {
            if (k>=i)
            {
                k-=i;
                ++ans;
                if (k==0)
                    return ans;
            }
        }
        return ans;
    }
};
