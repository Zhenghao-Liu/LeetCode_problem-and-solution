//更为巧妙
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26,0);
        for (char &i:magazine)
            ++count.at(i-'a');
        int index;
        for (char &i:ransomNote)
        {
            index=i-'a';
            --count.at(index);
            if (count.at(index)<0)
                return false;
        }
        return true;
    }
};
