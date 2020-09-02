//自定义排序规则
typedef pair<string,int> psi;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> count;
        for (string &i:words)
            ++count[i];
        vector<psi> helper(count.begin(),count.end());
        sort(helper.begin(),helper.end(),[](const psi &A,const psi &B){
            return A.second==B.second ? A.first<B.first : A.second>B.second;
        });
        vector<string> ans(k);
        for (int i=0;i<k;++i)
            ans.at(i)=helper.at(i).first;
        return ans;
    }
};
