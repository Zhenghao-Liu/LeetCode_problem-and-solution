class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int p_s=S.size()-1,del_s=0;
        int p_t=T.size()-1,del_t=0;
        while (p_s>=0 || p_t>=0)
        {
            move_idx(S,p_s,del_s);
            move_idx(T,p_t,del_t);
            if (p_s>=0 && p_t>=0)
            {
                if (S.at(p_s)!=T.at(p_t))
                    return false;
            }
            else if (p_s>=0 || p_t>=0)
                return false;
            --p_s;
            --p_t;
        }
        return true;
    }
    void move_idx(string &s,int &idx,int &del)
    {
        while (idx>=0)
        {
            char c=s.at(idx);
            if (c=='#')
            {
                --idx;
                ++del;
            }
            else if (del>0)
            {
                --idx;
                --del;
            }
            else
                break;
        }
    }
};
