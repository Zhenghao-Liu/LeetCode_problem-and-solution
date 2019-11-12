class Solution {
public:
    vector<vector<string>> partition(string s) {
        int s_size=s.size();
        vector<vector<string>> answer;
        vector<string> temporary;
        get_partition(s,s_size,answer,0,temporary);
        return answer;
    }
    void get_partition(string& s,const int & s_size,vector<vector<string>>& answer,int index,vector<string>& temporary)
    {
        if (index==s.size())
        {
            answer.push_back(vector<string>(temporary));
            return;
        }
        string temporary_str;
        for (int i=s_size-1;i>=index;--i)
        {
            temporary_str=s.substr(index,i-index+1);
            if (isPalindrome(temporary_str))
            {
                temporary.push_back(string(temporary_str));
                get_partition(s,s_size,answer,i+1,temporary);
                temporary.pop_back();
            }
        }  
    }
    bool isPalindrome(string& s) {
        int left=0,right=s.size()-1;
        while(left<=right)
            if (tolower(s.at(left))==tolower(s.at(right)))
            {
                ++left;
                --right;
            }
            else
                return false;
        return true;
    }
};
