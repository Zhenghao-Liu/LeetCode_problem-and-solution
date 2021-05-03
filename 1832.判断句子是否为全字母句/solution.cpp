class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[26]={0};
        for (int i:sentence) {
            cnt[i-'a']++;
        }
        int i=0;
        for (i=0;i<26;i++) {
            if (cnt[i]==0) {
                break;
            }
        }
        return i==26;
    }
};