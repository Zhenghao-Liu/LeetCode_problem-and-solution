//自定义排序，优化了空间
typedef pair<string,int> psi;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> count;
        for (string &i:words)
            ++count[i];
        sort(words.begin(),words.end(),[&count](const string &A,const string &B){
            return count.at(A)==count.at(B) ? A<B : count.at(A)>count.at(B);
        });
        //别忘了去除重复的单词
        unique(words.begin(),words.end());
        return vector<string>(words.begin(),words.begin()+k);
    }
};
