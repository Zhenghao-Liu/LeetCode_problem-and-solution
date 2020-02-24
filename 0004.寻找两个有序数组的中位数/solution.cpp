/*
* 将A(nums1)与B(nums2)的集合分成两部分left_part,right_part
* 且保证 1. left_part,right_part个数相同（集合个数为偶数则同，为奇数时则left_part多一个）
         2. 且left_part所有个数都小于right_part个数
* 即   left_part       |    right_part
  A[0] A[1] ... A[i-1] | A[i] A[i+1] ... A[m-1]
  B[0] B[1] ... B[j-1] | B[j] B[j+1] ... B[n-1]
* 设A共有m个元素，在left_part中有i个元素，B共有n个元素，在left_part中共有j个元素
* 因为left_part个数和right_part个数相同，则推出i在[0,m]范围，则j=(m+n+1)/2-i个(整除)
  因为left_part所有个数都小于right_part个数，则推出B[j-1]<=A[i] && A[i-1]<=B[j]
* 我们只需要通过二分法，设置i的左右边界imin,imax，即i=(imin+imax)/2来确定i，并通过二分法缩减i的边界来找到i
* 当找到最终的i时
  m+n为奇数时，answer=max(A[i-1],B[j-1])//倘若开始设置是奇数时right_part多一个则answer=min(A[i],B[j])
  m+n为偶数时，answer=(max(A[i-1],B[j-1])+min(A[i],B[j]))/2.0
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size=nums1.size(),nums2_size=nums2.size();
        if (nums1_size>nums2_size)
            return findMedianSortedArrays(nums2,nums1);
        int imin=0,imax=nums1_size;
        while (imin<=imax)
        {
            int i=imin+(imax-imin)/2;
            int j=(nums1_size+nums2_size+1)/2-i;
            if (j>0 && i<nums1_size && nums2.at(j-1)>nums1.at(i))
                imin=i+1;
            else if (i>0 && j<nums2_size && nums1.at(i-1)>nums2.at(j))
                imax=i-1;
            else
            {
                int left_part_max;
                if (i>0 && j>0)
                    left_part_max=max(nums1.at(i-1),nums2.at(j-1));
                else if (i==0)
                    left_part_max=nums2.at(j-1);
                else if (j==0)
                    left_part_max=nums1.at(i-1);
                if ((nums1_size+nums2_size)%2==1)
                    return left_part_max;
                int right_part_min;
                if (i<nums1_size && j<nums2_size)
                    right_part_min=min(nums1.at(i),nums2.at(j));
                else if (i==nums1_size)
                    right_part_min=nums2.at(j);
                else if (j==nums2_size)
                    right_part_min=nums1.at(i);
                return (left_part_max+right_part_min)/2.0;
            }
        }
        return 0;
    }
};
