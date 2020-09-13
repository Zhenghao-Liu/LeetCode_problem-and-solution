//其实就是求数组中不重复的元素
class Solution {
public:
    int expectNumber(vector<int>& scores) {
        sort(scores.begin(),scores.end());
        return unique(scores.begin(),scores.end())-scores.begin();
    }
};
