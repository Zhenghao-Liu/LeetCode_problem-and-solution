class Solution {
public:
    int halfQuestions(vector<int>& que) {
        int sz=que.size();
        vector<int> cnt(1e3+1);
        for (int i:que) {
            cnt.at(i)++;
        }
        sort(cnt.rbegin(),cnt.rend());
        int num=0;
        int ans=0;
        for (int i:cnt) {
            num+=i;
            ans++;
            if (num>=sz/2) {
                break;
            }
        }
        return ans;
    }
};