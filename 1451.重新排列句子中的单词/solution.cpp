class Solution {
public:
    string arrangeWords(string text) {
        stringstream ss;
        vector<pair<string,int>> helper;
        string s;
        text.at(0)=char(text.at(0)-'A'+'a');
        ss << text;
        int index=0;
        while (ss >> s)
        {
            helper.push_back({s,index});
            ++index;
        }
        sort(helper.begin(),helper.end(),[](const pair<string,int> &a,const pair<string,int> &b){
            return a.first.size()==b.first.size() ? a.second<b.second : a.first.size()<b.first.size();
        });
        string ans;
        for (auto &i:helper)
            ans+=i.first+' ';
        ans.pop_back();
        ans.at(0)=char(ans.at(0)-('a'-'A'));
        return ans;
    }
};
