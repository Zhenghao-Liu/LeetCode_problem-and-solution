class Solution {
public:
    int numDecodings(string s) {
        int s_size=s.size();
        if (s_size==0 || s.at(0)=='0')
            return 0;
        else if (s_size==1)
            return 1;
        vector<int> answer(s_size,0);
        answer.at(0)=1;
        if (s.at(1)=='0')
            if (s.at(0)<'3' && s.at(0)>'0')
                    answer.at(1)=1;
                else
                    return 0;
        else if (s.at(0)=='1')
            answer.at(1)=2;
        else if (s.at(0)=='2' && s.at(1)<'7')
            answer.at(1)=2;
        else
            answer.at(1)=1; 
        for (int i=2;i<s_size;++i)
            if (s.at(i)=='0')
                if (s.at(i-1)<'3' && s.at(i-1)>'0')
                        answer.at(i)=answer.at(i-2);
                else
                    return 0;
            else if (s.at(i-1)=='1')
                    answer.at(i)=answer.at(i-1)+answer.at(i-2);
            else if (s.at(i-1)=='2' && s.at(i)<'7')
                    answer.at(i)=answer.at(i-1)+answer.at(i-2);
            else
                answer.at(i)=answer.at(i-1);
        return answer.at(s_size-1);
    }
};
