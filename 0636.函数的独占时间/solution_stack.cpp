//用栈去模拟即可
//first是id，second是time
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<pii> helper;
        //类似于虚拟头节点
        helper.push({-1,0});
        for (string &i:logs)
        {
            int id;
            int cur_time;
            bool judge_start;
            help_func(i,id,judge_start,cur_time);
            auto [prev_id,prev_time]=helper.top();
            if (judge_start)
            {
                //id!=prev_id
                if (prev_id!=-1)
                    ans.at(prev_id)+=cur_time-prev_time;
                helper.push({id,cur_time});
            }
            else
            {
                //id==prev_id
                ans.at(prev_id)+=cur_time-prev_time+1;
                helper.pop();
                helper.top().second=cur_time+1;
            }
        }
        return ans;
    }
    void help_func(string &i,int &id,bool &judge_start,int &cur_time)
    {
        id=0;
        int size=i.size();
        int j;
        for (j=0;i.at(j)!=':';++j)
            id=id*10+(i.at(j)-'0');
        ++j;
        judge_start= i.at(j)=='s' ? true : false;
        while (i.at(j)!=':')
            ++j;
        ++j;
        cur_time=0;
        for (;j<size;++j)
            cur_time=cur_time*10+(i.at(j)-'0');
    }
};
