/*算法与solution1相同，将递归改成循环模式而已*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0)
            return -1;
        int left=0,right=nums.size()-1,middle;
        while (left<=right)
        {
            if (right==left)
                if (nums.at(left)==target)
                    return left;
                else
                    return -1;
            middle=(left+right)/2;
            if (nums.at(middle)>nums.at(right))//左边包括middle有序
                if ( target<=nums.at(middle) && target>=nums.at(left) )
                {
                    for (int i=left;i<=middle;++i)
                        if (nums.at(i)==target)
                            return i;
                    return -1;
                }
                else
                    left=middle+1;   
            else//右边不包括middle有序
                if ( target<=nums.at(right) && target>=nums.at(middle+1))
                {
                    for (int i=middle+1;i<=right;++i)
                        if (nums.at(i)==target)
                            return i;
                    return -1;
                }
                else
                    right=middle;
        }
        return -1; 
    }
};
