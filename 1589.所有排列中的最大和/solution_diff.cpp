/*
* 贪心：查询区间越多次，那么区间对应的数字权值越大越好
  所以求出每个位置查询的次数，从高到低逆序排序，依次从高到低权值分配给对应的数字
* 如果本题采用暴力复杂度n2即1e10显然不行，所以采用差分数组
* 设原数组nums[]
* 差分数组diff[]，设定为diff[i]=nums[i]-nums[i-1]
  且diff[0]=nums[0]
  一般diff会比nums长度要长一位(在末尾)，但是下标是对应的
* 因为diff[i]=nums[i]-nums[i-1]
  所以通过差分数组diff恢复原数组nums只需
  nums[i]=nums[i-1]+diff[i]通过类似于前缀和方式
* 差分数组设计目标：区间增加：设在[l]~[r]左闭右闭区间范围内，nums的元素都增加val
  因为区间增加，即区间内相邻元素间的差值是不会改变的，
  即原来是a b，增加后a+val b+val，差值还是b-a
  影响的是增加区间的左端和右端
  即diff[l]+=val,diff[r+1]-=val
* 即将区间增加复杂度从o(n)降到o(2)
*/
typedef long long ll;
class Solution {
    ll mod=1e9+7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int size=nums.size();
        vector<int> diff(size+1);
        for (vector<int> &i:requests)
        {
            int l=i.at(0),r=i.at(1);
            diff.at(l)+=1;
            diff.at(r+1)-=1;
        }
        vector<int> cnt(size);
        cnt.at(0)=diff.at(0);
        for (int i=1;i<size;++i)
            cnt.at(i)=cnt.at(i-1)+diff.at(i);
        sort(cnt.rbegin(),cnt.rend());
        sort(nums.rbegin(),nums.rend());
        ll ans=0;
        for (int i=0;i<size && cnt.at(i)!=0;++i)
        {
            ans+=(ll)nums.at(i)*cnt.at(i);
            ans%=mod;
        }
        return ans;
    }
};
