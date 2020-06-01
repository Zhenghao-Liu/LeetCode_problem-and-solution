class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //孩子g
        //饼干s
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_size=g.size();
        int s_size=s.size();
        int child=0,cookie=0;
        while (child<g_size && cookie<s_size)
        {
            if (g.at(child)<=s.at(cookie))
            {
                ++child;
                ++cookie;
            }
            else
                ++cookie;
        }
        return child;
    }
};
