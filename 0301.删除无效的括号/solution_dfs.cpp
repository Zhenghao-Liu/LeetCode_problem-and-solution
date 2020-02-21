class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int delete_left=0,delete_right=0;
        for (char &i:s)
            if (i=='(')
                ++delete_left;
            else if (i==')')
            {
                if (delete_left>0)
                    --delete_left;
                else
                    ++delete_right;
            }
        vector<string> answer;
        dfs(s,answer,delete_left,delete_right,0);
        return answer;
    }
    void dfs(string s,vector<string> & answer,int delete_left,int delete_right,int index)
    {
        if (delete_left==0 && delete_right==0)
        {
            if (judge_valid(s))
                answer.push_back(s);
            return;
        }
        int s_size=s.size();
        for (int i=index;i<s_size;++i)
        {
            if (i!=index && s.at(i)==s.at(i-1))
                continue;
            if (s.at(i)=='(')
                dfs(s.substr(0,i)+s.substr(i+1,s_size-i-1),answer,delete_left-1,delete_right,i);
            if (s.at(i)==')')
                dfs(s.substr(0,i)+s.substr(i+1,s_size-i-1),answer,delete_left,delete_right-1,i);
        }
    }
    bool judge_valid(string &s)
    {
        int left=0,right=0;
        for (char &i:s)
            if (i=='(')
                ++left;
            else if (i==')')
            {
                if (left<=0)
                    return false;
                --left;
            }
        return right==0;
    }
};
