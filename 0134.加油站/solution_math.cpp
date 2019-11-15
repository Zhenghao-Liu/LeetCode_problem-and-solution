/*
* 从i到j位置,有 sum(gas) < sum(cost),说明i到不了j,并且i到j之间任何一个位置都到不了j
* 那么表明起点要么在i左边要么在j右边
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int round_size=gas.size();
        int sum=0;
        for (int i=0;i<round_size;++i)
            sum=sum+gas.at(i)-cost.at(i);
        if (sum<0)
            return -1;
        int answer=0,have_gas=0;
        for (int i=0;i<round_size;++i)
        {
            have_gas=have_gas+gas.at(i)-cost.at(i);
            if (have_gas<0)
            {
                answer=i+1;
                have_gas=0;
            }
        }
        return answer;
    }
};
