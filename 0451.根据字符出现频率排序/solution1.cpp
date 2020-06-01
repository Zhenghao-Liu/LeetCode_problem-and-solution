class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> temp;
        for (char &i:s)
            ++temp[i];
        vector<pair<char,int>> mask;
        for (auto &i:temp)
            mask.push_back(make_pair(i.first,i.second));
        sort(mask.begin(),mask.end(),[](const pair<char,int>& A,const pair<char,int> &B){
            return A.second>B.second;
        });
        string ans;
        for (auto &i:mask)
            ans.append(i.second,i.first);
        return ans;
    }
};
