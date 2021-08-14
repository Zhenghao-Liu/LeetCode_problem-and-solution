class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int sz=graph.size();
        vector<vector<int>> edge(sz);
        for (int i=0;i<sz;i++) {
            for (int j:graph.at(i)) {
                edge.at(j).push_back(i);
            }
        }
        vector<int> out(sz);
        queue<int> que;
        for (int i=0;i<sz;i++) {
            out.at(i)=graph.at(i).size();
            if (out.at(i)==0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int cur=que.front();
            que.pop();
            for (int nxt:edge.at(cur)) {
                out.at(nxt)--;
                if (out.at(nxt)==0) {
                    que.push(nxt);
                }
            }
        }
        vector<int> ans;
        ans.reserve(sz);
        for (int i=0;i<sz;i++) {
            if (out.at(i)==0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};