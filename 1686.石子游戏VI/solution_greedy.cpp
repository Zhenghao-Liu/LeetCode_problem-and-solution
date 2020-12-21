/*
 * 贪心：按aliceValues、bobValues的和从大到小排序，先取和更大的
 * 一个是我自己的得分，一个是对方拿不到的得分，所以两个都越大越好
 * eg: aliceValues[a1,b1] bobValues[a2,b2]
   有两种拿法，alice先手所以以alice为自己视角
   1. alice拿a1，bob拿b2，得分差是a1-b2
   2. alice拿a2，bob拿b1，得分差是a2-b1
 * 哪种方法更优呢？就比较哪种方法得分差更大
   (a1-b2)-(a2-b1)=(a1+b1)-(a2+b2)
   即哪个方法更优，其实是比较 (a1+b1) 和 (a2+b2) 的和的大小
   归纳到多个石头也是同样贪心策略
 */
class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int size=a.size();
        vector<int> vec(size);
        for (int i=0;i<size;++i)
            vec.at(i)=i;
        sort(vec.begin(),vec.end(),[&a,&b](const int &A,const int &B){
            return a.at(A)+b.at(A)>a.at(B)+b.at(B);
        });
        int sca=0;
        int scb=0;
        for (int i=0;i<size;i+=2)
        {
            sca+=a.at(vec.at(i));
            if (i+1<size)
                scb+=b.at(vec.at(i+1));
        }
        int ans=0;
        if (sca>scb)
            ans=1;
        else if (sca<scb)
            ans=-1;
        return ans;
    }
};
