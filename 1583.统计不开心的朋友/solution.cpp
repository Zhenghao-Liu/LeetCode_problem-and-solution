//硬模拟
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans=0;
        int size=pairs.size();
        if (size==1)
            return 0;
        //用朋友作为key值，value作为喜欢程度，降低查找喜欢朋友的复杂度
        vector<vector<int>> vec(n,vector<int>(n,0));
        int p_size=preferences.size();
        for (int i=0;i<p_size;++i)
        {
            int value=n;
            for (int j:preferences.at(i))
                vec.at(i).at(j)=value--;
        }
        for (int i=0;i<size;++i)
        {
            int x=pairs.at(i).at(0);
            int y=pairs.at(i).at(1);
            for (int j=0;j<size;++j)
            {
                if (i==j)
                    continue;
                int u=pairs.at(j).at(0);
                int v=pairs.at(j).at(1);
                if (vec.at(x).at(u)>vec.at(x).at(y) && vec.at(u).at(x)>vec.at(u).at(v))
                {
                    ++ans;
                    break;
                }
                swap(u,v);
                if (vec.at(x).at(u)>vec.at(x).at(y) && vec.at(u).at(x)>vec.at(u).at(v))
                {
                    ++ans;
                    break;
                }
            }
            swap(x,y);
            for (int j=0;j<size;++j)
            {
                int u=pairs.at(j).at(0);
                int v=pairs.at(j).at(1);
                if (vec.at(x).at(u)>vec.at(x).at(y) && vec.at(u).at(x)>vec.at(u).at(v))
                {
                    ++ans;
                    break;
                }
                swap(u,v);
                if (vec.at(x).at(u)>vec.at(x).at(y) && vec.at(u).at(x)>vec.at(u).at(v))
                {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
