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
**
* 证明一个点，对于枚举的数value不断上升，sum也是单调严格递增的
  eg[a b c d]且a<b<c<d
  若value取a则数组变成[a a a a]，sum是4a
  若vlaue取b则数组变成[a b b b]，sum是a+3b
  显然4a<a+3b因为a<b
* 枚举所有数过于麻烦了，既然是找最接近target的数
  必然存在一个可能的ans1，他的sum<=target且在小于范围中最接近于target，
  存在另一个ans2，他的sum>target且在大于范围中最接近sum
  也显然ans1+1==ans2
* 那么二分value所有的可能性就好了，去找这个ans1，最后比较下abs(target-ans1)和abs(target-ans2)即可
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
        while (left<right)
        {
            int mid=left+(right-left+1)/2;
            int sum=get_sum(arr,target,mid,prefix);
            if (sum<=target)
                left=mid;
            else if (sum>target)
                right=mid-1;
            else
                return mid;
        }
        cout << left;
        int value1_ans=abs(get_sum(arr,target,left,prefix)-target);
        int value2_ans=abs(get_sum(arr,target,left+1,prefix)-target);
        if (value1_ans<=value2_ans)
            return left;
        else
            return left+1;
    }
    int get_sum(vector<int> &arr,int target,int i,vector<int> & prefix)
    {
        vector<int>::iterator p=lower_bound(arr.begin(),arr.end(),i);
        return prefix.at(p-arr.begin())+i*(arr.end()-p);
    }
};
