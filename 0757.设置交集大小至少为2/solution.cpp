/*
 * 是子集，所以不需要连续，且保证了[a,b]至少有两个元素
 * 必然是希望先处理小的区间再处理大的区间，这样子好处理
 * 因为希望从左往右遍历区间，那么区间要处理的就是右边界
   所以先按右边界升序排序，当相等时，再按左边界降序排序
 * 因为只用符合2个元素相交，所以只用维护答案集合的右边界的两个位置即可
 * 贪心：因为已经按右边界排好序，且是先处理小的再处理大的，所以在选择ans区间时
   选择intervals[]尽可能右边的位置作为ans区间
   1. 当ans区间与当前处理区间无交集时，选择当前区间的最右边两个加入ans中
   2. 当ans区间与当前处理区间有一个交集时，必然是当前区间最左边元素造成的交集
      所以只用额外多拿一位即可，选择当前区间最右边一个加入ans中
   3. 当ans区间与当前处理区间>=2的交集，则不需要往ans中添加
 */
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)==B.at(1) ? A.at(0)>B.at(0) : A.at(1)<B.at(1);
        });
        int ans=0;
        int p1=-1,p2=-1;
        for (vector<int> &i:intervals)
        {
            int a=i.at(0),b=i.at(1);
            if (a<=p1)
                continue;
            else if (a>p2)
            {
                ans+=2;
                p2=b;
                p1=b-1;
            }
            else
            {
                ans+=1;
                p1=p2;
                p2=b;
            }
        }
        return ans;
    }
};
