#include<stdexcept>
class Solution {
    vector<int> helper{0};
public:
    int sumNums(int n) {
        try
        {
            return helper.at(n);
        }
        catch(out_of_range & oe)
        {
            return n+sumNums(n-1);
        }
    }
};
