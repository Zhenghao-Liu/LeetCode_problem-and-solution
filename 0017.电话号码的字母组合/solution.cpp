static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> answer;
        int digits_size=digits.size();
        if (digits_size<1)
            return answer;
        answer.push_back(string(""));
        int number,answer_size;
        for (int i=0;i<digits_size;++i)
        {
            number=digits.at(i)-'2';
            answer_size=answer.size();
            for (int j=0;j<answer_size;++j)
                for (auto single_letter:map.at(number))//C++11新特性,https://zhidao.baidu.com/question/1836435665587272340.html
                    answer.push_back(string( answer.at(j)+single_letter ));
            answer.erase(answer.begin(),answer.begin()+answer_size);
        }
        return answer;
    }
};
