/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
    unordered_map<int,Employee*> dict;
public:
    int getImportance(vector<Employee*> employees, int id) {
        dict.clear();
        for (Employee *i:employees)
            dict[i->id]=i;
        return dfs(id);
    }
    int dfs(int id)
    {
        int ans=0;
        ans+=dict.at(id)->importance;
        for (int i:dict.at(id)->subordinates)
            ans+=dfs(i);
        return ans;
    }
};
