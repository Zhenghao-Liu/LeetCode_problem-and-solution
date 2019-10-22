static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int length=height.size();
        int max_c=0,capacity=0,left=0,right=length-1;
        while (left!=right)
        {
            capacity=min(height.at(left),height.at(right))*(right-left);
            max_c=max(max_c,capacity);
            if (height.at(left)<height.at(right))
                ++left;
            else
                --right;
        }
        return max_c;
    }
};
