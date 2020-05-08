/**
* 在二分中倘若是缩小范围的的查找
* while(left<right)
* 对于分成[left,mid] [mid+1,right]的mid=left+(right-left)/2
* 对于分成[left,mid-1] [mid,right]的mid=left+(right-left+1)/2
*/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size=mountainArr.length();
        //查找山峰
        int peak_index=find_peak_index(mountainArr,0,size-1);
        if (mountainArr.get(peak_index)==target)
            return peak_index;
        //在山峰的左边即升序序列进行查找
        int ascending_target_index=find_ascending_target_index(mountainArr,0,peak_index-1,target);
        if (mountainArr.get(ascending_target_index)==target)
            return ascending_target_index;
        //在山峰的右边即降序序列进行查找
        int descending_target_index=find_descending_target_index(mountainArr,peak_index+1,size-1,target);
        if (mountainArr.get(descending_target_index)==target)
            return descending_target_index;
        return -1;
    }
    int find_peak_index(MountainArray & mountainArr,int left,int right)
    {
        while (left<right)
        {
            int mid=left+((right-left)>>1);
            if (mountainArr.get(mid)>mountainArr.get(mid+1))
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
    int find_ascending_target_index(MountainArray &mountainArr,int left,int right,const int &target)
    {
        while (left<right)
        {
            int mid=left+((right-left+1)>>1);
            if (mountainArr.get(mid)>target)
                right=mid-1;
            else
                left=mid;
        }
        return left;
    }
    int find_descending_target_index(MountainArray &mountainArr,int left,int right,const int &target)
    {
        while (left<right)
        {
            int mid=left+((right-left)>>1);
            if (mountainArr.get(mid)>target)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};
