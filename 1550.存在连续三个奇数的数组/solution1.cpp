class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int size=arr.size();
        for (int i=2;i<size;++i)
        {
            if (arr.at(i)%2!=0 && arr.at(i-1)%2!=0 && arr.at(i-2)%2!=0)
                return true;
        }
        return false;
    }
};
