class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(0)==B.at(0) ? A.at(1)>B.at(1) : A.at(0)<B.at(0);
        });
        int people_size=people.size();
        vector<vector<int>> ans;
        ans.reserve(people_size);
        for (int i=people_size-1;i>=0;--i)
            ans.insert(ans.begin()+people.at(i).at(1),people.at(i));
        return ans;
    }
};
