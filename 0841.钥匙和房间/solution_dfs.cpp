class Solution {
    vector<bool> use;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int rooms_size=rooms.size();
        use=vector<bool>(rooms_size,false);
        dfs(rooms,0);
        for (bool i:use)
            if (!i)
                return false;
        return true;
    }
    void dfs(vector<vector<int>>& rooms,int cur)
    {
        use.at(cur)=true;
        for (int i:rooms.at(cur))
            if (!use.at(i))
                dfs(rooms,i);
    }
};
