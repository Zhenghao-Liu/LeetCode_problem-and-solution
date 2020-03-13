class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int nums_size=nums.size();
        vector<pair<int,int>> arr(nums_size);
        for (int i=0;i<nums_size;++i)
            arr.at(i)=make_pair(i,nums.at(i));
        vector<int> count(nums_size,0);
        merge(arr,count);
        return count;
    }
    void merge(vector<pair<int,int>> & arr,vector<int> & count)
    {
        int arr_size=arr.size();
        if (arr_size<2)
            return;
        int mid=arr_size/2;
        vector<pair<int,int>> left(mid);
        for (int i=0;i<mid;++i)
            left.at(i)=arr.at(i);
        merge(left,count);
        vector<pair<int,int>> right(arr_size-mid);
        for (int i=mid;i<arr_size;++i)
            right.at(i-mid)=arr.at(i);
        merge(right,count);
        arr.clear();
        merge_sort(left,right,arr,count);
    }
    void merge_sort(vector<pair<int,int>> & left,vector<pair<int,int>> & right,vector<pair<int,int>> & arr,vector<int> & count)
    {
        int i=0,j=0;
        int left_size=left.size(),right_size=right.size();
        //求逆序对，对于归并排序来说，左半、右半部分一定有序
        //当right.at(j).second<left.at(i).second时即，左边部分，从i开始到left_size-1的元素都可以与j构成逆序对
        //所以一种做法是让所有i到left_size-1的count值加1，但复杂度较高
        //所以换种思路，在left.at(i).second<=right.at(j).second时，此时可以构成逆序对第二个元素的，即right中的值已经提出
        //提出了几个其实就是索引j，所以左边元素count直接加上j即可
        while (i<left_size && j<right_size)
        {
            if (left.at(i).second<=right.at(j).second)
            {
                count.at(left.at(i).first)+=j;//关键
                arr.push_back(left.at(i));
                ++i;
            }
            else
            {
                arr.push_back(right.at(j));
                ++j;
            }
        }
        while (i<left_size)
        {
            count.at(left.at(i).first)+=j;//关键
            arr.push_back(left.at(i));
            ++i;
        }
        while (j<right_size)
        {
            arr.push_back(right.at(j));
            ++j;
        }
    }
};
