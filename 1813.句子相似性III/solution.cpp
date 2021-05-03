class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> vec1,vec2;
        int sz1=sentence1.size(),sz2=sentence2.size();
        int st=0;
        for (int i=0;i<=sz1;i++) {
            if (i==sz1 || sentence1.at(i)==' ') {
                vec1.push_back(sentence1.substr(st,i-st));
                st=i+1;
            }
        }
        st=0;
        for (int i=0;i<=sz2;i++) {
            if (i==sz2 || sentence2.at(i)==' ') {
                vec2.push_back(sentence2.substr(st,i-st));
                st=i+1;
            }
        }
        if (vec1.size()==vec2.size()) {
            return sentence1==sentence2;
        }
        if (vec1.size()>vec2.size()) {
            return helper(vec1,vec2);
        }
        return helper(vec2,vec1);
    }
    bool helper(vector<string> &vec1,vector<string> &vec2) {
        int cnt=0;
        for (int i=0;i<vec2.size();i++) {
            if (vec1.at(i)==vec2.at(i)) {
                cnt++;
            } else {
                break;
            }
        }
        for (int i=1;(int)vec2.size()-i>=0;i++) {
            if (vec1.at(vec1.size()-i)==vec2.at(vec2.size()-i)) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt>=vec2.size();
    }
};