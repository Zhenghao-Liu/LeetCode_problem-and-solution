/*
* 模拟：对于A阵营的人自然删除的目标是：排在本人后面的阵营B的人
  因为排在前面的阵营B的人已经使用过权利了，删除前面的敌对阵营的人没有意义，
** 所以优先删除排在后面的敌对阵营的人，当后面找不到敌对阵营的时候再去删除排在前面的敌对阵营的人
* 知道序列中只剩下一个阵营为止即是赢家
*/
class Solution {
public:
    string predictPartyVictory(string senate) {
        int i=0;
        while (senate.size()>1)
        {
            int opposite_char=senate.at(i)=='R' ? 'D' : 'R';
            int opposite_index=senate.find(opposite_char,i);
            if (opposite_index==string::npos)
            {
                opposite_index=senate.find(opposite_char);
                if (opposite_index==string::npos)
                    break;
            }
            senate.erase(senate.begin()+opposite_index);
            ++i;
            if (i>=(int)senate.size())
                i=0;
        }
        return senate.at(0)=='R' ? "Radiant" : "Dire";
    }
};
