/*
 * 首先筛去那些已经可以沟通的边
 * 因为只能教一种语言
 * 统计剩下需要教语言的人会的语言的个数
 * 贪心选择最多人会的语言去教
 */
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        vector<int> cnt(n+1);
        vector<bool> cho(m+1);
        for (vector<int> &i:friendships) {
            int a=i.at(0);
            int b=i.at(1);
            fill(cnt.begin(),cnt.end(),0);
            for (int j:languages.at(a-1)) {
                cnt.at(j)++;
            }
            bool flag=false;
            for (int j:languages.at(b-1)) {
                if (cnt.at(j)==1) {
                    flag=true;
                    break;
                }
            }
            if (!flag) {
                cho.at(a)=true;
                cho.at(b)=true;
            }
        }
        int peo=0;
        fill(cnt.begin(),cnt.end(),0);
        for (int i=1;i<=m;i++) {
            if (cho.at(i)) {
                peo++;
                for (int j:languages.at(i-1)) {
                    cnt.at(j)++;
                }
            }
        }
        return peo-*max_element(cnt.begin(),cnt.end());
    }
};
