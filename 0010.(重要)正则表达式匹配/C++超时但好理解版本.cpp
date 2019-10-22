class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        if (p==".*")
            return true;
        if ( !s.empty() && p.size()>=2 && (s.at(0)==p.at(0) || p.at(0)=='.') && p.at(1)=='*'
            && ( isMatch(s.substr(1),p) || isMatch(s.substr(1),p.substr(2)) || isMatch(s,p.substr(2))) )
            return true;
        else if ( !s.empty() && p.size()>=2 && s.at(0)!=p.at(0) && p.at(1)=='*'
                && isMatch(s,p.substr(2)) )
            return true;
        else if ( !s.empty() && (s.at(0)==p.at(0) || p.at(0)=='.') 
                && isMatch(s.substr(1),p.substr(1)) )
            return true;
        else if ( p.size()>=2 && p.at(1)=='*' 
                && isMatch(s,p.substr(2)) )
            return true;
        return false;
    }
};
//c++超时版本，好理解
//substr会新造一个字符串导致时间剧增
//且复杂度感觉O(3^n)