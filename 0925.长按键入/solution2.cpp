class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.empty())
            return typed.empty();
        int size1=name.size();
        int size2=typed.size();
        if (size1>size2)
            return false;
        vector<vector<bool>> dp(size1,vector<bool>(size2,false));
        dp.at(0).at(0)=name.at(0)==typed.at(0) ? true : false;
        for (int j=1;j<size2;++j)
            if (typed.at(j)==name.at(0))
                dp.at(0).at(j)=dp.at(0).at(j-1);
        for (int i=1;i<size1;++i)
            for (int j=i;j<size2;++j)
                if (name.at(i)==typed.at(j))
                    dp.at(i).at(j)=dp.at(i-1).at(j-1) || dp.at(i).at(j-1);
        return dp.at(size1-1).at(size2-1);
    }
};
