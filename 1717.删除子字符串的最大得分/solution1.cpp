class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> sta;
        string tar;
        if (x>y) {
            tar="ab";
        } else {
            tar="ba";
            swap(x,y);
        }
        int size=s.size();
        int ans=0;
        for (char i:s) {
            if (i=='a' || i=='b') {
                if (!sta.empty() && sta.top()==tar.at(0) && i==tar.at(1)) {
                    sta.pop();
                    ans+=x;
                } else {
                    sta.push(i);
                }
            } else {
                int a=0,b=0;
                while (!sta.empty()) {
                    if (sta.top()=='a') {
                        a++;
                    } else if (sta.top()=='b') {
                        b++;
                    }
                    sta.pop();
                }
                int res=min(a,b);
                ans+=res*y;
            }
        }
        int a=0,b=0;
        while (!sta.empty()) {
            if (sta.top()=='a') {
                a++;
            } else if (sta.top()=='b') {
                b++;
            }
            sta.pop();
        }
        int res=min(a,b);
        ans+=res*y;
        return ans;
    }
};
