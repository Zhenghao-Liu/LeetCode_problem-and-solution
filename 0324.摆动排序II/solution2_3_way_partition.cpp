/*
* [nth_element](http://c.biancheng.net/view/566.html)
* 一个stl函数，效果类似于快排的第一次执行，可以直接确定完全排序后，第二个参数指针值所对应的值，并将小于这个值的元素放在前面，大于的放在后面
* 因为我们并不需要完整的排序，只需要将nums可以分成左边右边两部分，且左边所有元素小于右边所有元素值
* 采取三色排序的基本思路，即将nums分成[0,1,2]只有3类元素，1为中间值，0为小于他的，2为大于他的
* nth_element帮我们找到中间值即1，通过三色排序，排成一个nums左边右边两部分的值，且左边元素小于右边所有元素
* 最后按照逆序存入nums即可
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> v(nums);
        int mid=(nums_size-1)/2;
        nth_element(v.begin(),v.begin()+mid,v.end());
        int mid_num=v.at(nums_size/2);
        int left=0,right=nums_size-1,curr=0;
        while (curr<=right)
        {
            if (v.at(curr)<mid_num)
            {
                swap(v.at(curr),v.at(left));
                ++left;
                ++curr;
            }
            else if (v.at(curr)>mid_num)
            {
                swap(v.at(curr),v.at(right));
                --right;
            }
            //else if (v.at(curr)==mid_num)
            else
                ++curr;
        }
        int judge=1;
        int p_l=mid,p_r=nums_size-1;
        for (int i=0;i<nums_size;++i)
        {
            if (judge)
                nums.at(i)=v.at(p_l--);
            else
                nums.at(i)=v.at(p_r--);
            judge^=1;
        }
    }
};
