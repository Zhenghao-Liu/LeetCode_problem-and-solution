/*
 * 设每个人的所坐的是座位，每两个相邻的座位构成一张沙发
   即要求交换到最后所有情侣坐一张沙发
 * 一个人的编号为 x，那么他的情侣的编号为 x ^ 1
 * 对每张沙发，去匹配第一个人，即交换第二个人与第一个人的情侣的位置
 */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans=0;
        int seat_size=row.size();
        vector<int> pos(seat_size);
        for (int i=0;i<seat_size;++i)
            pos.at(row.at(i))=i;
        for (int i=0;i<seat_size;i+=2)
        {
            int cur=row.at(i);
            int tar=cur^1;
            if (tar==row.at(i+1))
                continue;
            int cur_pos=i+1,tar_pos=pos.at(tar);
            pos.at(tar)=cur_pos;
            pos.at(row.at(i+1))=tar_pos;
            swap(row.at(i+1),row.at(tar_pos));
            ++ans;
        }
        return ans;
    }
};
