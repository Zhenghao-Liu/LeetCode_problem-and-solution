// 可以直接替换成twosum来做，这样就是等式的4种情况，再加上等式左右互换2种，就是4*2
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> ump;
        int size=nums.size();
        int ans=0;
        for (int i=0;i<size;i++) {
            int a=nums.at(i);
            for (int j=i+1;j<size;j++) {
                int b=nums.at(j);
                ans+=ump[a*b]*8;
                ump[a*b]++;
            }
        }
        return ans;
    }
};
