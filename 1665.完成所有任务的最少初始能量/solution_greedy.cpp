//按照差值大的降序排列
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int> &A,const vector<int> &B)->bool{
            int diffa=A.at(1)-A.at(0);
            int diffb=B.at(1)-B.at(0);
            return diffa>diffb;
        });
        int ans=0,cur=0;
        for (vector<int> &i:tasks)
        {
            int act=i.at(0);
            int mini=i.at(1);
            if (cur<mini)
            {
                ans+=mini-cur;
                cur=mini;
            }
            cur-=act;
        }
        return ans;
    }
};
