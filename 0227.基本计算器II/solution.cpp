//先把乘除左右两边位置存起来，然后函数操作，时间复杂度O(2N)
class Solution {
public:
    int calculate(string s) 
    {
        int s_size=s.size();
        queue<vector<int>> multiply_divide;
        for (int i=0;i<s_size;++i)
            if (s.at(i)=='*' || s.at(i)=='/')
            {
                int j=i;
                while (j>-1 && s.at(j)!='+' && s.at(j)!='-')
                    --j;
                ++j;
                while (i<s_size && s.at(i)!='+' && s.at(i)!='-')
                    ++i;
                --i;
                multiply_divide.push({j,i});
            }
        int answer=0,sign=1;
        for (int i=0;i<s_size;++i)
        {
            if (!multiply_divide.empty() && i==multiply_divide.front().at(0))
            {
                answer=answer+sign*get_multiply_divide(s,s_size,i,multiply_divide.front().at(1)+1);
                multiply_divide.pop();
            }
            else if (s.at(i)>='0')
            {
                int num=0;
                while (i<s_size && s.at(i)>='0')
                {
                    //这个顺序先减后加，不然越界
                    num=num*10-'0'+s.at(i);
                    ++i;
                }
                --i;
                answer=answer+sign*num;
            }
            else if (s.at(i)=='+')
                sign=1;
            else if (s.at(i)=='-')
                sign=-1;
        }
        return answer;
    }
    int get_multiply_divide(const string& s,const int & s_size,int &i,int end)
    {
        int answer=1;
        bool multiply=true;
        for (;i<end;++i)
        {
            if (s.at(i)>='0')
            {
                int num=0;
                while (i<end && s.at(i)>='0')
                {
                    num=num*10-'0'+s.at(i);
                    ++i;
                }
                --i;
                if (multiply)
                    answer=answer*num;
                else
                    answer=answer/num;
            }
            else if (s.at(i)=='*')
                multiply=true;
            else if (s.at(i)=='/')
                multiply=false;
        }
        --i;
        return answer;
    }
};
