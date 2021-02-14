class Solution {
public:
    int countBalls(int low, int high) {
        unordered_map<int,int> ump;
        for (int i=low;i<=high;i++) {
            int j=i;
            int sum=0;
            while (j>0) {
                sum+=j%10;
                j/=10;
            }
            ump[sum]++;
        }
        int ans=0;
        for (auto &i:ump) {
            ans=max(ans,i.second);
        }
        return ans;
    }
};
