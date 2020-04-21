class Solution {
public:
    string reformat(string s) {
        queue<char> queue_int;
        queue<char> queue_char;
        for (char &i:s)
            if (i>='0' && i<='9')
                queue_int.push(i);
            else
                queue_char.push(i);
        int int_size=queue_int.size();
        int char_size=queue_char.size();
        string ans;
        if (int_size==char_size)
        {
            while (!queue_int.empty())
            {
                ans+=queue_int.front();
                queue_int.pop();
                ans+=queue_char.front();
                queue_char.pop();
            }
        }
        else if (int_size==char_size+1)
        {
            while (!queue_char.empty())
            {
                ans+=queue_int.front();
                queue_int.pop();
                ans+=queue_char.front();
                queue_char.pop();
            }
            ans+=queue_int.front();
            queue_int.pop();
        }
        else if (char_size==int_size+1)
        {
            while (!queue_int.empty())
            {
                ans+=queue_char.front();
                queue_char.pop();
                ans+=queue_int.front();
                queue_int.pop();
            }
            ans+=queue_char.front();
            queue_char.pop();
        }
        return ans;
    }
};
