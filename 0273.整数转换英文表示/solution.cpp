    static vector<string> below_20={
        "One","Two","Three","Four","Five",
        "Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen",
        "Sixteen","Seventeen","Eighteen","Nineteen"
    };
    static vector<string> over_20={
        "Twenty","Thirty","Forty","Fifty","Sixty",
        "Seventy","Eighty","Ninety"
    };
class Solution {
public:
    string numberToWords(int num) {
        if (num==0)
            return "Zero";
        int num_size=to_string(num).size();
        string s_num(10-num_size,'0');
        s_num=s_num+to_string(num);
        string answer="";
        if (num_size>9)
            answer=answer+helper(s_num.substr(0,1))+"Billion ";
        if (num_size>6)
        {
            string temp=s_num.substr(1,3);
            if (stoi(temp)!=0)
                answer=answer+helper(temp)+"Million ";
        }  
        if (num_size>3)
        {
            string temp=s_num.substr(4,3);
            if (stoi(temp)!=0)
                answer=answer+helper(temp)+"Thousand ";
        }
        answer=answer+helper(s_num.substr(7,3));
        answer.erase(answer.end()-1);
        return answer;
    }
    string helper(string num)
    {
        if (num.size()==1)
            return below_20.at(num.at(0)-'0'-1)+' ';
        string answer="";
        if (num.at(0)>'0')
            answer=answer+below_20.at(num.at(0)-'0'-1)+" Hundred ";
        if (num.at(1)<'2')
        {
            int index=(num.at(1)-'0')*10+num.at(2)-'0';
            if (index!=0)
                answer=answer+below_20.at(index-1)+' ';
        }
        else
        {
            answer=answer+over_20.at(num.at(1)-'2')+' ';
            if (num.at(2)>'0')
                answer=answer+below_20.at(num.at(2)-'0'-1)+' ';
        }
        return answer;
    }
};
