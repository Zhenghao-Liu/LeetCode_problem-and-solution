int base=2e4+1;
int z=1e4;
vector<vector<bool>> helper(base,vector<bool>(base,false));
class Solution {
public:
    bool isPathCrossing(string path) {
        for (vector<bool> &i:helper)
            fill(i.begin(),i.end(),false);
        helper.at(0+z).at(0+z)=true;
        unordered_map<char,vector<int>> dict;
        dict['N']={-1,0};
        dict['S']={1,0};
        dict['E']={0,1};
        dict['W']={0,-1};
        int cur_x=0,cur_y=0;
        for (char i:path)
        {
            int a=dict[i].at(0);
            int b=dict[i].at(1);
            if (helper[cur_x+z+a][cur_y+z+b])
                return true;
            helper[cur_x+z+a][cur_y+z+b]=true;
            cur_x+=a;
            cur_y+=b;
        }
        return false;
    }
};
