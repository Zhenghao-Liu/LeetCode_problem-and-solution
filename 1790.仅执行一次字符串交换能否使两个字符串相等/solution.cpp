class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> vec;
        int sz=s1.size();
        for (int i=0;i<sz;i++) {
            if (s1.at(i)!=s2.at(i)) {
                vec.push_back(i);
            }
        }
        return vec.size()==0 || (vec.size()==2 && s1.at(vec.at(0))==s2.at(vec.at(1)) && s1.at(vec.at(1))==s2.at(vec.at(0)));
    }
};
