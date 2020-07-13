//要想根据权重随机选择，可以转成前缀和形式，然后二分查找在哪个区间即可
class Solution {
    vector<int> prefix;
    int upper;
public:
    Solution(vector<int>& w) {
        int sum=0;
        prefix.reserve(w.size());
        for (int i:w)
        {
            sum+=i;
            prefix.push_back(sum);
        }
        upper=prefix.back();
    }
    
    int pickIndex() {
        int num=rand()%upper+1;
        return lower_bound(prefix.begin(),prefix.end(),num)-prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
