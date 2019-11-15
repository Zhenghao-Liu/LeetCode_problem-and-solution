class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int round_size=gas.size();
        int position,have_gas;
        for (int i=0;i<round_size;++i)
        {
            if (cost.at(i)>gas.at(i))
                continue;
            if (i!=round_size-1)
                position=i+1;
            else
                position=0;
            have_gas=gas.at(i)-cost.at(i);
            while (position!=i)
            {
                have_gas=have_gas+gas.at(position)-cost.at(position);
                if (have_gas>=0)
                {
                    if (position==round_size-1)
                        position=0;
                    else
                        ++position;
                }
                else
                    break;
            }
            if (position==i)
                return position;
        }
        return -1;
    }
};
