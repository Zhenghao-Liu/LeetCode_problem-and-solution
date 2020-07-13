class Solution {
    unordered_map<string,string> a;
public:
    string reformatDate(string date) {
        get_a();
        string ans;
        int size=date.size();
        ans+=date.substr(size-4,4)+'-';
        ans+=a.at(date.substr(size-8,3))+'-';
        if (date.at(1)>='0' && date.at(1)<='9')
            ans+=date.substr(0,2);
        else
        {
            ans+='0';
            ans+=date.at(0);
        }
        return ans;
    }
    void get_a()
    {
        if (!a.empty())
            return;
        a["Jan"]="01";
        a["Feb"]="02";
        a["Mar"]="03";
        a["Apr"]="04";
        a["May"]="05";
        a["Jun"]="06";
        a["Jul"]="07";
        a["Aug"]="08";
        a["Sep"]="09";
        a["Oct"]="10";
        a["Nov"]="11";
        a["Dec"]="12";
    }
};
