class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        if (6*n<m || 6*m<n) {
            return -1;
        }
        int st1=0,ed1=n-1;
        int st2=0,ed2=m-1;
        int sum1=accumulate(nums1.begin(),nums1.end(),0);
        int sum2=accumulate(nums2.begin(),nums2.end(),0);
        int ans=0;
        while (sum1!=sum2) {
            if (sum1>sum2) {
                int sub=sum1-sum2;
                int dec1=INT_MAX;
                if (st1<=ed1 && nums1.at(ed1)!=1) {
                    dec1=min(nums1.at(ed1)-1,sub);
                }
                int dec2=INT_MAX;
                if (st2<=ed2 && nums2.at(st2)!=6) {
                    dec2=min(6-nums2.at(st2),sub);
                }
                if (dec1==INT_MAX && dec2==INT_MAX) {
                    return -1;
                }
                if (dec1==INT_MAX) {
                    nums2.at(st2)+=dec2;
                    sum2+=dec2;
                    st2++;
                } else if (dec2==INT_MAX) {
                    nums1.at(ed1)-=dec1;
                    sum1-=dec1;
                    ed1--;
                } else if (dec1>=dec2) {
                    nums1.at(ed1)-=dec1;
                    sum1-=dec1;
                    ed1--;
                } else {
                    nums2.at(st2)+=dec2;
                    sum2+=dec2;
                    st2++;
                }
            } else {
                int sub=sum2-sum1;
                int dec1=INT_MAX;
                if (st1<=ed1 && nums1.at(st1)!=6) {
                    dec1=min(6-nums1.at(st1),sub);
                }
                int dec2=INT_MAX;
                if (st2<=ed2 && nums2.at(ed2)!=1) {
                    dec2=min(nums2.at(ed2)-1,sub);
                }
                if (dec1==INT_MAX && dec2==INT_MAX) {
                    return -1;
                }
                if (dec1==INT_MAX) {
                    nums2.at(ed2)-=dec2;
                    sum2-=dec2;
                    ed2--;
                } else if (dec2==INT_MAX) {
                    nums1.at(st1)+=dec1;
                    sum1+=dec1;
                    st1++;
                } else if (dec1>=dec2) {
                    nums1.at(st1)+=dec1;
                    sum1+=dec1;
                    st1++;
                } else {
                    nums2.at(ed2)-=dec2;
                    sum2-=dec2;
                    ed2--;
                }
            }
            ans++;
        }
        return ans;
    }
};
