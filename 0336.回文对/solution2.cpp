//同solution1，进行优化
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int words_size=words.size();
        unordered_map<string,int> mask;
        mask.reserve(words_size);
        for (int i=0;i<words_size;++i)
            mask.insert({words.at(i),i});
        vector<vector<int>> ans;
        for (string &i:words)
        {
            int index_i=mask.at(i);
            //情况一:找与i相反次序的单词
            string i_reverse=i;
            reverse(i_reverse.begin(),i_reverse.end());
            unordered_map<string,int>::iterator index_i_reverse=mask.find(i_reverse);
            //注意当i本身是回文串时不能添加本身
            if (index_i_reverse!=mask.end() && (*index_i_reverse).second!=index_i)
                ans.push_back({index_i,(*index_i_reverse).second});
            //情况2:找i前缀回文的可能，翻转后缀，查找翻转后后缀
            for (string & j:find_prefix_palindrome(i_reverse))
            {
                if (mask.find(j)!=mask.end())
                    ans.push_back({mask.at(j),index_i});
            }
            //情况3:找i后缀回文的可能，翻转前缀，查找翻转后前缀
            for (string & j:find_suffix_palindrome(i_reverse))
            {
                if (mask.find(j)!=mask.end())
                    ans.push_back({index_i,mask.at(j)});
            }
        }
        return ans;
    }
    bool judge_palindrome(string & str,int begin,int end)
    {
        while (begin<end)
            if (str.at(begin)==str.at(end))
            {
                ++begin;
                --end;
            }
            else
                return false;
        return true;
    }
    vector<string> find_prefix_palindrome(string & str)
    {
        int str_size=str.size();
        vector<string> suffix;
        for (int i=str_size-1;i>=0;--i)
            if (judge_palindrome(str,i,str_size-1))
                suffix.push_back(str.substr(0,i));
        return suffix;
    }
    vector<string> find_suffix_palindrome(string & str)
    {
        int str_size=str.size();
        vector<string> prefix;
        for (int i=0;i<str_size;++i)
            if (judge_palindrome(str,0,i))
                prefix.push_back(str.substr(i+1));
        return prefix;
    }
};
