/*
*将数组一分为二判断哪边有序哪边无序，有序则比较两头，无序一边再进行递归运算
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0)
            return -1;
        return search_target(nums,target,0,nums.size()-1);
    }
    int search_target(vector<int> &nums,const int& target,int left,int right)
    {
        if (right==left)
            if (nums.at(left)==target)
                return left;
            else
                return -1;
        int middle=(left+right)/2;
        if (nums.at(middle)>nums.at(right))//左边包括middle有序
            if ( target<=nums.at(middle) && target>=nums.at(left) )
            {
                for (int i=left;i<=middle;++i)
                    if (nums.at(i)==target)
                        return i;
                return -1;
            }
            else
                return search_target(nums,target,middle+1,right);   
        else//右边不包括middle有序
            if ( target<=nums.at(right) && target>=nums.at(middle+1))
            {
                for (int i=middle+1;i<=right;++i)
                    if (nums.at(i)==target)
                        return i;
                return -1;
            }
            else
                return search_target(nums,target,left,middle);
    }
};
