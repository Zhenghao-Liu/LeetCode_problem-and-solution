class Solution {
    vector<char> dict{'A','G','C','T'};
    int size=8;
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> helper_set(bank.begin(),bank.end());
        queue<pair<string,int>> helper_queue;
        helper_queue.push({start,0});
        while (!helper_queue.empty())
        {
            auto [curr_str,step]=helper_queue.front();
            if (curr_str==end)
                return step;
            helper_queue.pop();
            for (int i=0;i<size;++i)
            {
                char curr_char=curr_str.at(i);
                for (char &j:dict)
                {
                    if (j==curr_char)
                        continue;
                    curr_str.at(i)=j;
                    if (helper_set.find(curr_str)!=helper_set.end())
                    {
                        helper_set.erase(helper_set.find(curr_str));
                        helper_queue.push({curr_str,step+1});
                    }
                }
                curr_str.at(i)=curr_char;
            }
        }
        return -1;
    }
};
