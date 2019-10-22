static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int vector_size=strs.size();
        if (vector_size==1)
            return strs.at(0);
        else if (vector_size==0)
            return "";
        int j=0,string_size=strs.at(0).size();
        for (int i=1;i<vector_size;++i)
        {
            j=strs.at(i).size();
            string_size=j<string_size?j:string_size;
        }
        string ans="";
        for (int i=0;i<string_size;++i)
        {
            for (int j=0;j<vector_size-1;++j)
                if (strs.at(j).at(i)!=strs.at(j+1).at(i))
                    return ans;
            ans=ans+strs.at(0).at(i);                    
        }
        return ans;
    }
};
