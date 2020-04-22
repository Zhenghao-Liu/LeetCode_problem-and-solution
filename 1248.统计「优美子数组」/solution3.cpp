/*
* 我们可以设arr[i]为第i个字符结尾时有几个奇数
* 那么对于统计有k个字符我们可以在遍历数组是找arr[i]-arr[j]=k的情况
* 但如果循环到一个i，我们就要通过再一次循环去遍历j即在[0,i-1]所有范围去遍历，找到arr[i]-arr[j]则++ans，复杂度又变成了O(n^2)了
* 能否降低复杂度呢
* 我们可以将式子变一下arr[j]=arr[i]-k
* 注意arr[i]是有几个奇数
* 根据arr[i]不同奇数的个数存入一个哈希表中，即奇数为1的情况有几个，奇数为0的情况有几个等等
* 然后我们从左到右一直统计奇数的个数sum，其实就是上面式子中的arr[i]
* 我们只需要根据有多少个arr[j]满足上面式子即可了，找到sum-k即arr[i]-k的奇数个符合的有几个
* 其实就是存入公式中单个元素的每一个值，对于一个sum，有多少个arr[j]满足上面式子，ans就加几
*/
//设key为奇数的个数，value为出现某奇数个数组合的个数
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> prefix_count(nums.size()+1);
        prefix_count.at(0)=1;
        int sum=0,ans=0;
        for (int &i:nums)
        {
            sum+=i&1;
            ++prefix_count.at(sum);
            if (sum>=k)
                ans+=prefix_count.at(sum-k);
        }
        return ans;
    }
};
