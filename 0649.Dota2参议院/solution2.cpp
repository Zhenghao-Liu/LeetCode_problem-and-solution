/*
* 模拟：对于A阵营的人自然删除的目标是：排在本人后面的阵营B的人
  因为排在前面的阵营B的人已经使用过权利了，删除前面的敌对阵营的人没有意义，
** 所以优先删除排在后面的敌对阵营的人，当后面找不到敌对阵营的时候再去删除排在前面的敌对阵营的人
* 知道序列中只剩下一个阵营为止即是赢家
* 删除字符串复杂度过高，改为变换成一个标记值'-'代表删除了
*/
class Solution {
public:
    string predictPartyVictory(string senate) {
        int i=0;
        int size=senate.size();
        int senate_size=senate.size();
        while (size>1)
        {
            if (senate.at(i)=='-')
            {
                ++i;
                if (i>=senate_size)
                    i=0;
                continue;
            }
            int opposite_char=senate.at(i)=='R' ? 'D' : 'R';
            int opposite_index=senate.find(opposite_char,i);
            if (opposite_index==string::npos)
            {
                opposite_index=senate.find(opposite_char);
                if (opposite_index==string::npos)
                    break;
            }
            senate.at(opposite_index)='-';
            --size;
            ++i;
            if (i>=senate_size)
                i=0;
        }
        for (int i=0;i<senate_size;++i)
            if (senate.at(i)!='-')
                return senate.at(i)=='R' ? "Radiant" : "Dire";
        //无效return
        return "";
    }
};
