/*
 * 因为不用在意左右两头的元素的个数，所以只要两头出现相同的，那么与两头相连的一堆都可以删除
 * 所以先贪心的去尽可能删
 * 特殊情况就是当只剩一种字母的时候，如果个数>1的话可以全部删除，如果只有1个则删不成
 */
typedef pair<char,int> pii;
class Solution {
public:
    int minimumLength(string s) {
        int sz=s.size();
        vector<pii> vec;
        vec.reserve(sz);
        for (int i=0;i<sz;) {
            int j=i;
            for (j=i+1;j<sz && s.at(j)==s.at(i);j++);
            vec.push_back({s.at(i),j-i});
            i=j;
        }
        int len=vec.size();
        int l=0,r=len-1;
        while (l<r) {
            if (vec.at(l).first==vec.at(r).first) {
                l++;
                r--;
            } else {
                break;
            }
        }
        if (l==r && vec.at(l).second!=1) {
            return 0;
        }
        int ans=0;
        for (int i=l;i<=r;i++) {
            ans+=vec.at(i).second;
        }
        return ans;
    }
};
