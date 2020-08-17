//方法同solution1_dp，但是既然有序就可以直接二分
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)==B.at(1) ? A.at(0)<B.at(0) : A.at(1)<B.at(1);
        });
        int pairs_size=pairs.size();
        vector<int> dp(pairs_size);
        dp.at(0)=1;
        for (int i=1;i<pairs_size;++i)
        {
            dp.at(i)=dp.at(i-1);
            int left=0,right=i-1;
            int cur=pairs.at(i).at(0);
            while (left<right)
            {
                int mid=left+(right-left+1)/2;
                if (pairs.at(mid).at(1)<cur)
                    left=mid;
                else
                    right=mid-1;
            }
            if (pairs.at(left).at(1)<cur)
                dp.at(i)=max(dp.at(i),dp.at(left)+1);  
        }
        int ans=1;
        for (int i:dp)
            ans=max(ans,i);
        return ans;
    }
};
