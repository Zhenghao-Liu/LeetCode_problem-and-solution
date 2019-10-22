class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size()==0)
            return false;
        int left=0,right=nums.size()-1,middle;
        while (left<=right)
        {
            if (right==left)
                if (nums.at(left)==target)
                    return true;
                else
                    return false;
            middle=(left+right)/2;
			//相比于33题就多了这一个小循环
            while (middle+1 < right && nums.at(middle) == nums.at(right))
			    ++middle;
            if (nums.at(middle)>nums.at(right))//左边包括middle有序
                if ( target<=nums.at(middle) && target>=nums.at(left) )
                {
                    for (int i=left;i<=middle;++i)
                        if (nums.at(i)==target)
                            return true;
                    return false;
                }
                else
                    left=middle+1;   
            else//右边不包括middle有序
                if ( target<=nums.at(right) && target>=nums.at(middle+1))
                {
                    for (int i=middle+1;i<=right;++i)
                        if (nums.at(i)==target)
                            return true;
                    return false;
                }
                else
                    right=middle;
        }
        return false; 
    }
};
