/*
* (a+bi)*(c+di)=(ac-bd)+(ad+bc)i
*/
class Solution {
public:
    string complexNumberMultiply(string _a, string _b) {
        stringstream ss;
        ss << _a;
        int a,b;
        char ch1,ch2;
        ss >> a >> ch1 >> b >> ch2;
        ss.clear();
        ss << _b;
        int c,d;
        ss >> c >> ch1 >> d >> ch2;
        return to_string(a*c-b*d)+"+"+to_string(a*d+b*c)+"i";
    }
};
