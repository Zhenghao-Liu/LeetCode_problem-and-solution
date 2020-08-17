//把删除掉的字符标记为'-'，之后用R_kill_D表示当下R有几次禁止他人权利的机会
class Solution {
public:
    string predictPartyVictory(string senate) {
        bool has_R=true,has_D=true;
        int R_kill_D=0;
        int size=senate.size();
        while (has_R && has_D)
        {
            has_R=has_D=false;
            for (int i=0;i<size;++i)
            {
                if (senate.at(i)=='-')
                    continue;
                if (senate.at(i)=='R')
                {
                    has_R=true;
                    if (R_kill_D<0)
                        senate.at(i)='-';
                    ++R_kill_D;
                }
                //else if (senate.at(i)=='D)
                else
                {
                    has_D=true;
                    if (R_kill_D>0)
                        senate.at(i)='-';
                    --R_kill_D;
                }
            }
        }
        return R_kill_D>0 ? "Radiant" : "Dire";
    }
};
