class Solution {
public:
    string getHint(string secret, string guess) {
        int size=secret.size();
        vector<int> mask(10,0);  
        int bulls=0,cows=0;
        for (int i=0;i<size;++i)
            if (secret.at(i)==guess.at(i))
                ++bulls;
            else
                ++mask.at(secret.at(i)-'0');
        for (int i=0;i<size;++i)
            if (secret.at(i)!=guess.at(i) && mask.at(guess.at(i)-'0')>0)
            {
                ++cows;
                --mask.at(guess.at(i)-'0');
            }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};
