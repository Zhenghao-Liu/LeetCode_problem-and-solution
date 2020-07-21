/*
* 要想同样数字变得更大，那么自然是要将某个较小的数字和某个较大的数字交换
* 且题目要求时一个更大元素，即这个交换后的数要尽可能的小，自然是从后往前找一个较小的数，然后再在该数的后面找一个比较小数大的数交换
* 但如果数字n是降序，eg：4321，即已经是最大的数字了，所以不存在下一个更大元素，return -1
* eg：1234，那么自然3<4,3就是这个较小的数，4就是较大的数，return 1243
* eg：1234321，那么[2]=3是这个较小的数，[3]=4是较大的数，交换得1243321，但显然有更小的元素但是还是比n大，
  那么需要的是排序交换后面的部分，因为前面已经确保比n大，后面部分应该尽可能的小，因此最小就是升序的情况
* eg: 1294321，此时[1]=2是这个较小的数，但是较大的数可以选[2]=9、[3]=4、[4]=3，为了能使交换后的数字最小，
  应该竟可能的选择比较小的数[1]=2大，但是在这个范围中最小的数，所以选择[4]=3，这个选择可以直接遍历，或者因为后面部分是降序的也可以用二分
  交换后1394221，此时13·····已经确保了大于n，所以后面要取最小情况即是升序情况，最终1312249
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        if (n<10)
            return -1;
        string s=to_string(n);
        int s_size=s.size();
        int min_pos;
        for (min_pos=s_size-2;min_pos>=0;--min_pos)
            if (s.at(min_pos)<s.at(min_pos+1))
                break;
        if (min_pos==-1)
            return -1;
        int l=min_pos+1,r=s_size-1;
        while (l<r)
        {
            int mid=l+(r-l+1)/2;
            if (s.at(mid)>s.at(min_pos))
                l=mid;
            else
                r=mid-1;
        }
        int max_pos=l;
        swap(s.at(min_pos),s.at(max_pos));
        sort(s.begin()+min_pos+1,s.end());
        long long num=stoll(s);
        return num<(long long)INT_MAX ? (int)num : -1;
    }
};
