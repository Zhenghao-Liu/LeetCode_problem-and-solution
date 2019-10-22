//滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int s_size=s.size();
        if (s_size==0)
            return 0;
        unordered_map<char,int> letter_show_times;
        bool judge_stop_right,judge_stop_left;
        int maxmum=INT_MIN,left=0,right=-1;
        while(right+1<s_size)
        {
            ++right;
			++letter_show_times[s.at(right)];
			while(right+1<s_size)
            {
                ++letter_show_times[s.at(right+1)];
                judge_stop_right=false;
                for (auto i:letter_show_times)
                    if (i.second>1)
                    {
                        judge_stop_right=true;
                        break;
                    }
                if (judge_stop_right)
                {
					--letter_show_times[s.at(right+1)];
					break;
				}
				else
					++right;
            }
            if (right-left+1>maxmum)
                maxmum=right-left+1;
			while (left<=right && right+1<s_size)
			{
				--letter_show_times[s.at(left)];
				++left;
				if (s.at(left-1)==s.at(right+1))
					break;
			}
        }
        return maxmum;
    }
};
