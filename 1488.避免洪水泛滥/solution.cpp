/*
* 对于晴天不理，存入sun中
* 对于第一次下雨不理
* 倘若一个地方下两次雨，则必须在两次下雨之间有一个晴天把水抽干
  因为是从头至尾，且sun存的是天数，即保证了最大值小于当前i，所以只要满足大于第一次下雨时间即可
  且尽可能的往前面匹配晴天，因为有可能中间有多个晴天，后面的晴天留给别的湖泊用，理解为早抽水早准备下雨
  因此用lower_bound、upper_bound都是同一个位置，因为索引没有重复的值
* 一个地方下两次雨，且中间有晴天抽水，不会发生洪灾
  但是第二次下雨会导致湖泊是有水的，所以此时的第二次下雨，转变为了下下次下雨的第一次下雨
*/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int rains_size=rains.size();
        //因为最后如果有晴天但是不是必要的抽水天气时仍要给一个值
        vector<int> ans(rains_size,1);
        //key是第几个湖，value是上一次下雨在rains中的索引i
        unordered_map<int,int> last_rain;
        //存晴天在rains中的索引
        set<int> sun;
        for (int i=0;i<rains_size;++i)
        {
            int ii=rains.at(i);
            if (ii==0)
            {
                sun.insert(i);
                continue;
            }
            if (last_rain.find(ii)!=last_rain.end())
            {
                auto p=sun.lower_bound(last_rain[ii]);
                if (p==sun.end())
                    return {};
                ans.at(*p)=ii;
                sun.erase(p);
            }
            last_rain[ii]=i;
            ans.at(i)=-1;
        }
        return ans;
    }
};
