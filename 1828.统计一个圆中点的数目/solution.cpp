class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int sz=queries.size();
        vector<int> ans(sz);
        for (int i=0;i<sz;i++) {
            int a=queries.at(i).at(0),b=queries.at(i).at(1);
            int len=queries.at(i).at(2)*queries.at(i).at(2);
            for (vector<int> &j:points) {
                int x=j.at(0),y=j.at(1);
                int d=dis(a,b,x,y);
                if (d<=len) {
                    ans.at(i)++;
                }
            }
        }
        return ans;
    }
    int dis(int a,int b,int x,int y) {
       return (x-a)*(x-a)+(y-b)*(y-b); 
    }
};