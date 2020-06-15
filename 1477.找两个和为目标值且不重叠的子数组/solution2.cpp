class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int arr_size=arr.size();
        int sum=0;
        //first存区间的右边界，second存该区间的长度
        vector<pair<int,int>> helper;
        int left=0;
        for (int i=0;i<arr_size;++i)
        {
            sum+=arr.at(i);
            if (sum>target)
            {
                while (left<=i && sum>target)
                {
                    sum-=arr.at(left);
                    ++left;
                }
            }
            else if (sum<target)
            {
                continue;
            }
            //sum==target
            if (sum==target)
            {
                int length=i-left+1;
                if (helper.empty())
                {
                    helper.push_back({i,length});
                    continue;
                }
                pair<int,int> p=helper.back();
                if ((p.first)>=left)
                {
                    if (length<(p.second))
                    {
                        helper.pop_back();
                        helper.push_back({i,length});
                    }
                }
                else
                    helper.push_back({i,length});
            }
        }
        if (helper.size()<2)
            return -1;
        sort(helper.begin(),helper.end(),[](const pair<int,int> &A,const pair<int,int> &B){
            return A.second<B.second;
        });
        return helper.at(0).second+helper.at(1).second;
    }
};
