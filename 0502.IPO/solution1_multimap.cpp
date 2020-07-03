/*
* 贪心：我有足够的资金，当然是选择利润最大的项目
*/
typedef pair<int,multimap<int,int>::iterator> piit;
struct cmp
{
    bool operator()(const piit &A,const piit &B)const
    {
        return A.first<B.first;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int size=Profits.size();
        //key存启动资金，value存利润
        multimap<int,int> dict;
        for (int i=0;i<size;++i)
            dict.insert({Capital.at(i),Profits.at(i)});
        //利用堆求可选项目中利润最大的一个
        priority_queue<piit,vector<piit>,cmp> helper;
        auto last=dict.begin();
        for (int i=0;i<k;++i)
        {
            //因为经过上一个项目后，个人资金必然是增长或者不变，即之前可以选择的项目现在必然还可以选择，所以不用从begin开始遍历
            auto p=last;
            for (;p!=dict.end() && (p->first)<=W;++p)
                helper.push({p->second,p});
            if (helper.empty())
                return W;
            last=p;
            auto [x,y]=helper.top();
            helper.pop();
            W+=x;
            dict.erase(y);
        }
        return W;
    }
};
