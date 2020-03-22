class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<pair<string,bool>>> mask;
        for (vector<string> &i:tickets)
            mask[i.at(0)].push_back(make_pair(i.at(1),true));
        for (auto &i:mask)
            if (i.second.size()>1)
                sort(i.second.begin(),i.second.end(),[](const pair<string,bool> &A,const pair<string,bool> &B){
                    return A.first<B.first;
                });
        vector<string> ans{"JFK"};
        int final_size=tickets.size()+1;
        ans.reserve(final_size);
        for (pair<string,bool> &i:mask.at("JFK"))
            if (i.second)
            {
                i.second=false;
                ans.push_back(i.first);
                if (dfs(mask,i.first,ans,final_size))
                    return ans;
                i.second=true;
                ans.pop_back();
            }
        return ans;
    }
    bool dfs(unordered_map<string,vector<pair<string,bool>>>& mask,string& index,vector<string>& ans,const int & final_size)
    {
        if (ans.size()==final_size)
            return true;
        if (mask.find(index)==mask.end())
            return false;
        for (pair<string,bool> &i:mask.at(index))
            if (i.second)
            {
                i.second=false;
                ans.push_back(i.first);
                if (dfs(mask,i.first,ans,final_size))
                    return true;
                i.second=true;
                ans.pop_back();
            }
        return false;
    }
};
