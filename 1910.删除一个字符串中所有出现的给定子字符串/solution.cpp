class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (true) {
            int pos=s.find(part);
            if (pos==string::npos) {
                break;
            }
            s.erase(pos,part.size());
        }
        return s;
    }
};