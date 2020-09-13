/*
* 选择一个区间使得字符升序排序
  那么进一步限定，使得只能选择相邻的两个元素进行升序排序
  这样子的好处是使得一个大区间的数字能够交换过来，且区间内剩下的元素的相对顺序不改变
* 此外选择从后往前遍历
* 但是交换因为是要求升序排序，所以要交换过来的数字的位置a，与当前所在位置b
  区间中不能有数字是大于要交换过来的数字的
* 为什么从后往前而不是从前往后，因为数组弹出最后一个元素复杂度要优于弹出第一个元素
* 所以倘若交换不来对应的数字，则false
*/
class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<vector<int>> pos(10);
        int size=s.size();
        for (int i=0;i<size;++i)
            pos.at(s.at(i)-'0').push_back(i);
        for (int i=size-1;i>=0;--i)
        {
            int c=t.at(i)-'0';
            if (pos.at(c).empty())
                return false;
            int from_pos=pos.at(c).back();
            pos.at(c).pop_back();
            for (int num=c+1;num<10;++num)
                if (!pos.at(num).empty() && pos.at(num).back()>from_pos)
                    return false;
        }
        return true;
    }
};
