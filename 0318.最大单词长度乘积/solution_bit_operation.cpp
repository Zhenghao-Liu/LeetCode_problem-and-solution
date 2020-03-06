/*
* 采用位运算
* 在二进制下，设a是1，b是10，c是100，以此类推
* 这样一个单词就可以转换为一个有26个数位的二进制数
* int就32位就可以存的下
* 对于不同的单词，要求不能含有公共字母，所以他们对应的数字采用与运算结果为0，则不含公共字母
  eg:aabd->1011 c->100 则1011 & 100==0，即不含公共字母
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int words_size=words.size();
        vector<int> helper(words_size,0);
        for (int i=0;i<words_size;++i)
            for (char &j:words.at(i))
                //因为单词中可能有重复的字母出现，采用unordered_set来存字母再相加，但采用或运算就能巧妙的提高效率
                helper.at(i)|=(1<<(j-'a'));
        int answer=0;
        for (int i=0;i<words_size;++i)
            for (int j=i+1;j<words_size;++j)
                if ((helper.at(i) & helper.at(j))==0)
                {
                    int temp=words.at(i).size()*words.at(j).size();
                    if (temp>answer)
                        answer=temp;
                }
        return answer;
    }
};
