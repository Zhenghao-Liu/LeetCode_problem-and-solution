class Solution {
public:
    int calculate(string s) {
        int x=1,y=0;
        for (char i:s)
            if (i=='A')
                x=x*2+y;
            else
                y=y*2+x;
        return x+y;
    }
};
