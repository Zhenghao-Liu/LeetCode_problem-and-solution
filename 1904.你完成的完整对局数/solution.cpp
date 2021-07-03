class Solution {
public:
    int numberOfRounds(string st, string fi) {
        int a=(st.at(0)-'0')*10+(st.at(1)-'0'),b=(st.at(3)-'0')*10+(st.at(4)-'0');
        int x=(fi.at(0)-'0')*10+(fi.at(1)-'0'),y=(fi.at(3)-'0')*10+(fi.at(4)-'0');
        if (!less(a,b,x,y)) {
            x+=24;
        }
        int ans=0;
        if (b==0 || b==15 || b==30 || b==45) {
            ans++;
        }
        while (1) {
            inc(a,b);
            if (less(a,b,x,y)) {
                ans++;
            } else {
                break;
            }
        }
        return ans-1;
    }
    bool less(int a,int b,int x,int y) {
        return a<x || (a==x && b<=y);
    }
    void inc(int &a,int &b) {
        if (b>=0 && b<15) {
            b=15;
        } else if (b>=15 && b<30) {
            b=30;
        } else if (b>=30 && b<45) {
            b=45;
        } else if (b>=45 && b<60) {
            b=0;
            a++;
        }
    }
};