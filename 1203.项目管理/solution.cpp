class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int &i:group) {
            if (i==-1) {
                i=m;
                m++;
            }
        }
        // 组之间的出度指向
        vector<vector<int>> groNxt(m);
        // item组内的出度指向
        vector<vector<int>> nxt(n);
        // 组之间入度
        vector<int> groCnt(m);
        // item组内的入度
        vector<int> cnt(n);
        // 分组的成员
        vector<list<int>> member(m);
        for (int i=0;i<n;i++) {
            int ite=i;
            int gro=group.at(ite);
            member.at(gro).push_back(ite);
            for (int bef:beforeItems.at(ite)) {
                int befGro=group.at(bef);
                if (befGro!=gro) {
                    groCnt.at(gro)++;
                    groNxt.at(befGro).push_back(gro);
                } else {
                    cnt.at(ite)++;
                    nxt.at(bef).push_back(ite);
                }
            }
        }
        queue<int> queGro;
        vector<int> ans;
        ans.reserve(n);
        for (int i=0;i<m;i++) {
            if (groCnt.at(i)==0) {
                queGro.push(i);
            }
        }
        while (!queGro.empty()) {
            int groCur=queGro.front();
            queGro.pop();
            for (int gro:groNxt.at(groCur)) {
                groCnt.at(gro)--;
                if (groCnt.at(gro)==0) {
                    queGro.push(gro);
                }
            }
            int pushCnt=0;
            queue<int> queIte;
            for (int i:member.at(groCur)) {
                if (cnt.at(i)==0) {
                    queIte.push(i);
                }
            }
            while (!queIte.empty()) {
                int iteCur=queIte.front();
                ans.push_back(iteCur);
                queIte.pop();
                pushCnt++;
                for (int iteNxt:nxt.at(iteCur)) {
                    cnt.at(iteNxt)--;
                    if (cnt.at(iteNxt)==0) {
                        queIte.push(iteNxt);
                    }
                }
            }
            if (pushCnt!=(int)member.at(groCur).size()) {
                break;
            }
        }
        if ((int)ans.size()==n) {
            return ans;
        }
        return {};
    }
};
