//先把所有可能子数组区间存进来，借助multimap排序，来搜寻在不重叠下最小的数组和
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int arr_size=arr.size();
        int sum=0;
        //first存长度，second存可能子数组的左边界
        multimap<int,int> helper;
        int left=0;
        for (int i=0;i<arr_size;++i)
        {
            sum+=arr.at(i);
            if (sum>target)
                while (left<=i && sum>target)
                {
                    sum-=arr.at(left);
                    ++left;
                }
            else if (sum<target)
                continue;
            if (sum==target)
                helper.insert({i-left+1,left});
        }
        int ans=INT_MAX;
        for (auto i=helper.begin();i!=helper.end();++i)
        {
            //因为multimap有排序，可以剪枝
            if (i->first*2>=ans)
                break;
            for (auto j=next(i,1);j!=helper.end();++j)
            {
                if (i->second<=j->second && i->second+i->first-1>=j->second)
                    continue;
                if (i->second>=j->second && j->second+j->first-1>=i->second)
                    continue;
                ans=min(ans,i->first+j->first);
                break;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
