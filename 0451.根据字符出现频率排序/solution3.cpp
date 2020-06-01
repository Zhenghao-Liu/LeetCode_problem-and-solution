class Solution {
public:
    string frequencySort(string s) {
        //ascii最多128位
        vector<int> count(128,0);
        for (char &i:s)
            ++count.at(int(i));
        vector<pair<int,char>> helper;
        for (int i=0;i<128;++i)
            if (count.at(i)!=0)
                helper.push_back({count.at(i),char(i)});
        sort(helper.begin(),helper.end(),[](const pair<int,char> &A,const pair<int,char> &B){
            return A.first>B.first;
        });
        string ans;
        for (pair<int,char> &i:helper)
            ans.append(i.first,i.second);
        return ans;
    }
};
