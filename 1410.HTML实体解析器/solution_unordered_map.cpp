unordered_map<string,char> mask{
        {"quot;",'\"'},
        {"apos;",'\''},
        {"amp;",'&'},
        {"gt;",'>'},
        {"lt;",'<'},
        {"frasl;",'/'},
    };
class Solution {
public:
    string entityParser(string text) {
        string ans;
        ans.reserve(text.size());
        for (int i=0;i<text.size();++i)
        {
            if (text.at(i)=='&')
            {
                int erase_start=i;
                string helper;
                ++i;
                while (i<text.size() && text.at(i)!='&')
                {
                    helper+=text.at(i);
                    if (text.at(i)==';')
                        break;
                    ++i;
                }
                if (i<text.size() && text.at(i)==';' && mask.find(helper)!=mask.end())
                    ans+=mask.at(helper);
                else
                    ans+='&'+helper;
            }
            else
                ans+=text.at(i);
        }
        return ans;
    }
};
