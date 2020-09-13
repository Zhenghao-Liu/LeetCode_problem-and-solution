class Solution {
public:
    string toLowerCase(string str) {
        for (char &i:str)
            if (i<='Z' && i>='A')
                i=i+('a'-'A');
        return str;
    }
};
