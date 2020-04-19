class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans=0;
        for (int i=0;i<3;++i)
            if (guess.at(i)==answer.at(i))
                ++ans;
        return ans;
    }
};
