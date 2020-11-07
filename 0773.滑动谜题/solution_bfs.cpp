//把board看成是一个一维的string，但是注意[2]和[3]是不能左右交换的
vector<vector<int>> dir;
bool already_build=false;
void build_dir()
{
    if (already_build)
        return;
    already_build=true;;
    dir.clear();
    dir.reserve(6);
    dir.push_back({1,3});
    dir.push_back({0,2,4});
    dir.push_back({1,5});
    dir.push_back({0,4});
    dir.push_back({1,3,5});
    dir.push_back({2,4});
}
const int tar=123450;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        build_dir();
        unordered_set<int> memo;
        string start;
        for (vector<int> &i:board)
            for (int j:i)
                start+=char('0'+j);
        int start_num=stoi(start);
        if (start_num==tar)
            return 0;
        queue<string> que;
        int ans=0;
        que.push(start);
        memo.insert(stoi(start));
        while (!que.empty())
        {
            int size=que.size();
            ++ans;
            for (int i=0;i<size;++i)
            {
                string s=que.front();
                que.pop();
                int idx=0;
                for (idx=0;idx<6;++idx)
                    if (s.at(idx)=='0')
                        break;
                for (int nxt:dir.at(idx))
                {
                    swap(s.at(idx),s.at(nxt));
                    int num=stoi(s);
                    if (num==tar)
                        return ans;
                    if (memo.find(num)==memo.end())
                    {
                        que.push(s);
                        memo.insert(num);
                    }
                    swap(s.at(idx),s.at(nxt));
                }
            }
        }
        return -1;
    }
};
