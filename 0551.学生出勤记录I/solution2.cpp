class Solution {
public:
    bool checkRecord(string s) {
        return (s.find("LLL")==-1) && (s.find('A')==s.rfind('A'));
    }
};
