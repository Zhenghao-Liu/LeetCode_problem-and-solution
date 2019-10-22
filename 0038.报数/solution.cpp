class Solution {
public:
    string countAndSay(int n) {
        if (n==1)
            return "1";
        string one_before(countAndSay(n-1));
        int one_before_size=one_before.size(),same_size=1;
        string answer;
        for (int i=0;i<one_before_size-1;++i)
            if (one_before.at(i)==one_before.at(i+1))
        	    ++same_size;
            else
            {
        	    answer=answer+char(same_size+'0')+one_before.at(i);
        	    same_size=1;
		    }
        answer=answer+char(same_size+'0')+one_before.at(one_before_size-1);
	    return answer;  
    }
};
