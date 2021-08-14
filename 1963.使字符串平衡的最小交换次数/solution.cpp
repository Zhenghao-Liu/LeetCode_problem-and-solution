class Solution {
public:
    int minSwaps(string s) {
        stack<char> sta;
        for (char i:s) {
            if (i==']') {
                if (!sta.empty() && sta.top()=='[') {
                    sta.pop();
                    continue;
                }
                sta.push(i);
            } else {
                sta.push(i);
            }
        }
        return (sta.size()/2+1)/2;
    }
};