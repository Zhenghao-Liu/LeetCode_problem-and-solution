class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int sz=words.size();
        vector<int> vec(26);
        for (string &i:words) {
            for (char j:i) {
                vec.at(j-'a')++;
            }
        }
        for (int i:vec) {
            if ((i%sz)!=0) {
                return false;
            }
        }
        return true;
    }
};