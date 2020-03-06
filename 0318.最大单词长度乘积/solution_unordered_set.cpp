//brute_force，采用集合优化查找效率
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int words_size=words.size();
        vector<unordered_set<char>> mask(words_size);
        for (int i=0;i<words_size;++i)
            for (char &j:words.at(i))
                mask.at(i).insert(j);
        int answer=0;
        for (int i=0;i<words_size;++i)
            for (int j=i+1;j<words_size;++j)
            {
                bool judge=true;
                for (char k:mask.at(i))
                    if (mask.at(j).find(k)!=mask.at(j).end())
                    {
                        judge=false;
                        break;
                    }
                if (!judge)
                    continue;
                for (char k:mask.at(j))
                    if (mask.at(i).find(k)!=mask.at(i).end())
                    {
                        judge=false;
                        break;
                    }
                if (judge && words.at(i).size()*words.at(j).size()>answer)
                    answer=words.at(i).size()*words.at(j).size();
            }
        return answer;
    }
};
