class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int orders_size=orders.size();
        if (orders_size==0)
            return {{"Table"}};
        unordered_map<int,unordered_map<string,int>> helper;
        vector<int> table;
        vector<string> food; 
        for (vector<string> &i:orders)
        {
            table.push_back(stoi(i.at(1)));
            food.push_back(i.at(2));
            ++(helper[stoi(i.at(1))][i.at(2)]);
        }
        sort(table.begin(),table.end());
        table.erase(unique(table.begin(),table.end()),table.end());
        sort(food.begin(),food.end());
        food.erase(unique(food.begin(),food.end()),food.end());
        vector<vector<string>> ans;
        ans.push_back({"Table"});
        for (string &i:food)
            ans.at(0).push_back(i);
        int count=0;
        for (int &i:table)
        {
            ++count;
            ans.push_back({to_string(i)});
            for (string &j:food)
                if (helper[i].find(j)==helper[i].end())
                    ans.at(count).push_back("0");
                else
                    ans.at(count).push_back(to_string(helper[i][j]));
        }
        return ans;
    }
};
