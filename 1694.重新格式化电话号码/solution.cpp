class Solution {
public:
    string reformatNumber(string number) {
        string num;
        for (char i:number) {
            if (i!='-' && i!=' ') {
                num+=i;
            }
        }
        int size=num.size();
        int idx=0;
        string ans;
        while(size>4) {
            ans+=num.substr(idx,3);
            ans+='-';
            idx=idx+3;
            size-=3;
        }
        if (size==4) {
            ans+=num.substr(idx,2);
            ans+='-';
            idx+=2;
            ans+=num.substr(idx,2);
        } else if (size==3) {
            ans+=num.substr(idx,3);
        } else {
            ans+=num.substr(idx,2);
        }
        return ans;
    }
};
