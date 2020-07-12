class Solution {
public:
    bool detectCapitalUse(string word) {
        int size=word.size();
        int count_big=0;
        for (char i:word)
            if (i>='A' && i<='Z')
                ++count_big;
        return word.empty() || count_big==0 || count_big==size || (count_big==1 && word.at(0)>='A' && word.at(0)<='Z');
    }
};
