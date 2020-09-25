class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> vec;
        string s;
        int cnt_s=0;
        int size=text.size();
        for (char i:text)
            if (i==' ')
                ++cnt_s;
        stringstream ss;
        ss << text;
        while (ss >> s)
            vec.push_back(s);
        int vec_size=vec.size();
        if (vec_size==1)
        {
            s.append(cnt_s,' ');
            return s;
        }
        int cnt=cnt_s/(vec_size-1);
        string ans;
        for (int i=0;i<vec_size-1;++i)
        {
            ans+=vec.at(i);
            ans.append(cnt,' ');
        }
        ans+=vec.back();
        ans.append(cnt_s-cnt*(vec_size-1),' ');
        return ans;
    }
};
