class Solution {
public:
    string removeKdigits(string num, int k) {
        int num_size=num.size();
        int ans_size=num_size-k;
        //[start,end]
        int start=0,end=k;
        string ans;
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> window;
        for (int i=start;i<end;++i)
            window.push({num.at(i),i});
        while (end<num_size)
        {
            window.push({num.at(end),end});
            while (window.top().second<start)
                window.pop();
            auto [min,min_pos]=window.top();
            window.pop();
            //注意前导0
            if (!(ans.empty() && min=='0'))
                ans+=min;
            start=min_pos+1;
            ++end;
        }
        return ans.empty() ? "0" : ans;
    }
};
