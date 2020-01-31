//因为已经有序，再优化到对数复杂度，那就二分查找
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int citations_size=citations.size();
        int left=0,right=citations_size-1;
        int mid,answer=0;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (citations.at(mid)>=citations_size-mid)
            {
                answer=citations_size-mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return answer;
    }
};
