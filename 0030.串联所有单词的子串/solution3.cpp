class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_size=s.size(),words_size=words.size();
        if (s_size==0 || words_size==0)
            return {};
        int single_words_size=words.at(0).size(),substr_size=words_size*single_words_size;
        if (substr_size>s_size)
            return {};
        unordered_map<string,int> words_show_times;
        int ascii_words=0;
        for (string i:words)
        {
            ++words_show_times[i];
            for (char j:i)
                ascii_words=ascii_words+j;
        }
        unordered_map<string,int> window_words_show_times;
        vector<int> answer;
        bool judge;
        int ascii_windows=0;
        for (int i=0;i<substr_size;++i)
            ascii_windows=ascii_windows+s.at(i);
        for (int i=0;i<s_size-substr_size+1;ascii_windows=ascii_windows-s.at(i)+s[i+substr_size],++i)
        {
            if (ascii_windows!=ascii_words)
                continue;
            window_words_show_times.clear();
            for (int j=i;j<i+substr_size;j=j+single_words_size)
                ++window_words_show_times[s.substr(j,single_words_size)];
            judge=true;
            for (auto k:words_show_times)
                if (k.second!=window_words_show_times[k.first])
                {
                    judge=false;
                    break;
                }
            if (judge)
                answer.push_back(int(i));
        }
        return answer;
    }
};
