class Solution {
public:
    string getHint(string secret, string guess) {
        int size=secret.size();
        vector<int> mask(10,0);  
        int bulls=0;
        for (int i=0;i<size;++i)
            if (secret.at(i)==guess.at(i))
                ++bulls;
            else
            {
                ++mask.at(secret.at(i)-'0');
                --mask.at(guess.at(i)-'0');
            }
        int temp=0;
        for (int &i:mask)
            //mask中大于0的个数，因为是++mask.at(secret.at(i)-'0')，即没有猜到的数字的个数
            if (i>0)
                temp+=i;
        //总长减去bulls，即不等的位置的总个数，再减去错误位置的个数
        int cows=size-temp-bulls;
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};
