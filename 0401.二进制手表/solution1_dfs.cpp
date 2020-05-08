class Solution {
    vector<int> hour{1,2,4,8};
    vector<int> minute{1,2,4,8,16,32};
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        dfs_hour(ans,num,0,0,0);
        dfs_minute(ans,num,0,0,0,0);
        return ans;
    }
    void dfs_hour(vector<string> &ans,int num,int led_hour,int start,int cur_hour)
    {
        for (int i=start;i<4;++i)
        {
            if (led_hour+1<=num && cur_hour+hour.at(i)<=11)
            {
                dfs_hour(ans,num,led_hour+1,i+1,cur_hour+hour.at(i));
                dfs_minute(ans,num-led_hour-1,0,0,cur_hour+hour.at(i),0);
            }
            else
                break;
        }
    }
    void dfs_minute(vector<string> &ans,int num,int led_minute,int start,int cur_hour,int cur_minute)
    {
        if (led_minute==num)
        {
            string temp=to_string(cur_hour)+':';
            if (cur_minute/10==0)
                temp+='0'+to_string(cur_minute);
            else
                temp+=to_string(cur_minute);
            ans.push_back(temp);
            return;
        }
        for (int i=start;i<6;++i)
        {
            if (cur_minute+minute.at(i)<=59)
                dfs_minute(ans,num,led_minute+1,i+1,cur_hour,cur_minute+minute.at(i));
            else
                break;
        }
    }
};
