//从大往小放
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sum=m+n;
        --m;
        --n;
        for (int i=sum-1;i>-1;--i)
            if (m==-1)
            {
                nums1.at(i)=nums2.at(n);
                --n;
            }
            else if (n==-1)
                break;
            else if (nums1.at(m)>nums2.at(n))
            {
                nums1.at(i)=nums1.at(m);
                --m;
            }
            else
            {
                nums1.at(i)=nums2.at(n);
                --n;
            }
    }
};
