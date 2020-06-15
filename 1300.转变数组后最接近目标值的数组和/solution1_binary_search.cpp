/*
* 题意是>value的值都会变成value
  其实可以延伸成>=value的值都会变成value
* arr[i]<=10^5那么可以枚举所有情况
* 可能取值的下界是0，因为target>=1，arr[i]>=1，ans小于0的sum和ans为0的sum一样
* 可能取值的上界是arr中最大的元素，因为他是最大的元素，往更大的数去试，也没有arr元素会更新成value了
* 为了优化sum可以采用前缀和
* 且通过二分去查找有哪些元素是>value要更新成value的
* lower_bound是找有序数组中第一个大于等于元素的位置，按理来说应该是找>value的第一个位置
  但是题意是可以延伸成>=value的值都会变成value，所以直接用lower_bound就可以了
*/
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int arr_size=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> prefix(arr_size+1,0);
        for (int i=0;i<arr_size;++i)
            prefix.at(i+1)=prefix.at(i)+arr.at(i);
        int left=0,right=arr.back();
        //因为有可能出现abs(sum-target)一进循环就等于target的可能，所以要初始化ans
        int ans=0,diff=target;
        for (int i=left;i<=right;++i)
        {
            vector<int>::iterator p=lower_bound(arr.begin(),arr.end(),i);
            int sum=prefix.at(p-arr.begin())+i*(arr.end()-p);
            if (abs(sum-target)<diff)
            {
                diff=abs(sum-target);
                ans=i;
                if (diff==0)
                    return ans;
            }
        }
        return ans;
    }
};
