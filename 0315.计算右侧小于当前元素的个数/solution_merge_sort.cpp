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
        while (i<left_size && j<right_size)
        {
            if (left.at(i).second<=right.at(j).second)
            {
                count.at(left.at(i).first)+=j;//神奇
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
            count.at(left.at(i).first)+=j;//神奇
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
