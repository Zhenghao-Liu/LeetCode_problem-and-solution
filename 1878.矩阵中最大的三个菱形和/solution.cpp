class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid.at(0).size();
        set<int> st;
        for (vector<int> &i:grid) {
            for (int j:i) {
                st.insert(j);
                if (st.size()>3) {
                    st.erase(st.begin());
                }
            }
        }
        int edg=2;
        while (m>=edg*2-1 && n>=edg*2-1) {
            for (int i=edg-1;i+edg-1<m;i++) {
                for (int j=edg-1;j+edg-1<n;j++) {
                    int sum=0;
                    for (int a=i,b=j-(edg-1);a>i-(edg-1) && b<j;a--,b++) {
                        sum+=grid.at(a).at(b);
                    }
                    for (int a=i-(edg-1),b=j;a<i && b<j+(edg-1);a++,b++) {
                        sum+=grid.at(a).at(b);
                    }
                    for (int a=i,b=j+(edg-1);a<i+(edg-1) && b>j;a++,b--) {
                        sum+=grid.at(a).at(b);
                    }
                    for (int a=i+(edg-1),b=j;a>i && b>j-(edg-1);a--,b--) {
                        sum+=grid.at(a).at(b);
                    }
                    st.insert(sum);
                    if (st.size()>3) {
                        st.erase(st.begin());
                    }
                }
            }
            edg++;
        }
        vector<int> ans(st.begin(),st.end());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};