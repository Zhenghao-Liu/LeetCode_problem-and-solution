class Solution {
    //这个顺序是有意义的
    vector<pair<string,int>> dict{{"zero",0},{"two",2},{"four",4},{"six",6},{"eight",8},{"three",3},{"five",5},{"seven",7},{"one",1},{"nine",9}};
public:
    string originalDigits(string s) {
        vector<int> count(26,0);
        for (char &i:s)
            ++count.at(i-'a');
        string ans;
        unordered_map<char,int> count_dict;
        for (int i=0;i<10;++i)
        {
            count_dict.clear();
            for (char &j:dict.at(i).first)
                ++count_dict[j];
            int max_cut=INT_MAX;
            for (auto &j:count_dict)
            {
                int have=count.at(j.first-'a');
                int try_cut=0;
                while (have-j.second>=0)
                {
                    ++try_cut;
                    have-=j.second;
                }
                if (try_cut<max_cut)
                    max_cut=try_cut;
            }
            for (auto &j:count_dict)
                count.at(j.first-'a')-=max_cut*(j.second);
            while (max_cut>0)
            {
                ans+=char(dict.at(i).second+'0');
                --max_cut;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
