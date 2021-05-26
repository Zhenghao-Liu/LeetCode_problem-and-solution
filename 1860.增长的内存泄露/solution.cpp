class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int a=memory1,b=memory2;
        int cur=1;
        while (a>=cur || b>=cur) {
            if (a>=b) {
                a-=cur;
            } else {
                b-=cur;
            }
            cur++;
        }
        return vector<int>{cur,a,b};
    }
};