class Solution {
public:
    int calculate(string s) {
        int s_size=s.size();
        if (s_size==0)
            return 0;
        s=s+')';
        s_size=s_size+1;
        int index=0;
        return in_bracket(s,s_size,index);

    }
    int in_bracket(const string &s,const int& s_size,int &index)
    {
        bool add=true;
        int part_answer=0;
        string temp="";
        for (;index<s_size;++index)
        {
            if (s.at(index)==' ')
                continue;
            if (s.at(index)==')')
                return calculate_part(part_answer,temp,add);	
            if (s.at(index)=='+')
            {
                part_answer=calculate_part(part_answer,temp,add);
                add=true;
                continue;
            }
            else if (s.at(index)=='-')
            {
                part_answer=calculate_part(part_answer,temp,add);
                add=false;
                continue;
            }
            if (s.at(index)=='(')
            {
                ++index;
                if (add)
                    part_answer=part_answer+in_bracket(s,s_size,index);
                else
                    part_answer=part_answer-in_bracket(s,s_size,index);
                continue;
            }
            temp=temp+s.at(index);
        }
        //无用的return
        return calculate_part(part_answer,temp,add);
    }
    int calculate_part(const int &part_answer,string &temp,const bool & add)
    {
        if (temp=="")
            return part_answer;
        int t;
        if (add)
            t=part_answer+stoi(temp);
        else
            t=part_answer-stoi(temp);
        temp="";
        return t;
    }
};
