class Solution {
public:
    int compress(vector<char>& chars) {
        int chars_size=chars.size();
        int slow=0,fast=0;
        int fast_start;
        char target;
        string s_count;
        int s_count_size;
        while (fast<chars_size)
        {
            target=chars.at(fast);
            chars.at(slow)=target;
            fast_start=fast;
            while (fast<chars_size && chars.at(fast)==target)
                ++fast;
            if (fast-fast_start!=1)
            {
                s_count=to_string(fast-fast_start);
                s_count_size=s_count.size();
                for (int i=0;i<s_count_size;++i)
                    chars.at(slow+i+1)=s_count.at(i);
                slow+=s_count_size+1;
            }
            else
                ++slow;
        }
        return slow;
    }
};
