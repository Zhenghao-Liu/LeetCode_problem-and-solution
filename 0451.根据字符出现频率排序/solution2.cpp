struct cmp
{
    bool operator()(const int &A,const int &B) const
    {
        return A>B;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> count;
        for (char &i:s)
            ++count[i];
        map<int,vector<char>,cmp> helper;
        for (auto &i:count)
            helper[i.second].push_back(i.first);
        string ans;
        for (auto &i:helper)
            for (char &j:i.second)
                ans.append(i.first,j);
        return ans;
    }
};
