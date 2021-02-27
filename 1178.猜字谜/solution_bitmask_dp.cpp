// 状压，然后枚举子集即可
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> ump;
        for (string &i:words) {
            int num=helper(i);
            // 剪枝
            if (__builtin_popcount(num)>7) {
                continue;
            }
            ump[num]++;
        }
        int sz=puzzles.size();
        vector<int> ans(sz);
        for (int i=0;i<sz;i++) {
            int cur=helper(puzzles.at(i));
            int fir=1<<(puzzles.at(i).at(0)-'a');
            int res=0;
            int subset=cur;
            do {
                if (subset==0 || (subset&fir)==0) {
                    subset=(subset-1)&cur;
                    continue;
                }
                auto p=ump.find(subset);
                if (p!=ump.end()) {
                    res+=p->second;
                }
                subset=(subset-1)&cur;
            }while(subset!=cur);
            ans.at(i)=res;
        }
        return ans;
    }
    int helper(string &s) {
        int ans=0;
        for (char i:s) {
            ans|=1<<(i-'a');
        }
        return ans;
    }
};
