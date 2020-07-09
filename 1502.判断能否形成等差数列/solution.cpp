class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int d=arr.at(1)-arr.at(0);
        for (int i=2;i<arr.size();++i)
            if (arr.at(i)-arr.at(i-1)!=d)
                return false;
        return true;
    }
};
