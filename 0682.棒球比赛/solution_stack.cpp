//用栈模拟分数即可
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> helper;
        for (string &i:ops)
        {
            if (i=="+")
            {
                int a=helper.top();
                helper.pop();
                int cur=helper.top()+a;
                helper.push(a);
                helper.push(cur);
            }
            else if (i=="D")
                helper.push(helper.top()*2);
            else if (i=="C")
                helper.pop();
            else
                helper.push(stoi(i));
        }
        int ans=0;
        while (!helper.empty())
        {
            ans+=helper.top();
            helper.pop();
        }
        return ans;
    }
};
