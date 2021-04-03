class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> ump;
        for (vector<string> &i:knowledge) {
            ump[i.at(0)]=i.at(1);
        }
        string ans;
        int sz=s.size();
        for (int i=0;i<sz;i++) {
            if (s.at(i)=='(') {
                int j=i+1;
                for (;j<sz && s.at(j)!=')';j++);
                string key=string(s.begin()+i+1,s.begin()+j);
                i=j;
                auto p=ump.find(key);
                if (p==ump.end()) {
                    ans+="?";
                } else {
                    ans+=p->second;
                }
            } else {
                ans+=s.at(i);
            }
        }
        return ans;
    }
};