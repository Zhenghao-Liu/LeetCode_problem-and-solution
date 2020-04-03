class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> helper{'a','e','i','o','u','A','E','I','O','U'};
        int left=0,right=s.size()-1;
        while (left<right)
        {
            while (left<right && helper.find(s.at(left))==helper.end())
                ++left;
            while (left<right && helper.find(s.at(right))==helper.end())
                --right;
            if (left<right && s.at(left)!=s.at(right))
                swap(s.at(left),s.at(right));
            ++left;
            --right;
        }
        return s;
    }
};
