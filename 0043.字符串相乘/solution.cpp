class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0")
		    return "0";
	    else if (num1=="1")
		    return num2;
	    else if (num2=="1")
		    return num1;
	    int num1_size=num1.size(),num2_size=num2.size();
	    if (num1_size<num2_size)
	    {
		    swap(num1,num2);
		    swap(num1_size,num2_size);
	    }
	    vector<vector<int>> subproduct;
	    int carry,single_product,single_num2,position=-1;
	    for (int i=num2_size-1;i>=0;--i)
	    {
		    subproduct.push_back(vector<int>({}));
		    ++position;
		    carry=0;
		    single_num2=num2.at(i)-'0';
		    for (int j=num1_size-1;j>=0;--j)
		    {
			    single_product=single_num2*(num1.at(j)-'0')+carry;
			    carry=single_product/10;
			    subproduct.at(position).push_back(int(single_product%10));
		    }
		    subproduct.at(position).push_back(int(carry));
	    }
	    string answer;
	    carry=0;
	    for (int i=0;i<num2_size-1;++i)
	    {
		    single_product=carry;
		    position=i;
		    for (int j=0;j<=i;++j)
			    single_product=single_product+subproduct.at(j).at(position--);
		    carry=single_product/10;
		    answer=answer+char(single_product%10+'0');
	    }
	    for (int i=0;i<num1_size-num2_size+2;++i)
	    {
		    single_product=carry;
		    position=i+num2_size-1;
		    for (int j=0;j<num2_size;++j)
			    single_product=single_product+subproduct.at(j).at(position--);
		    carry=single_product/10;
		    answer=answer+char(single_product%10+'0');
	    }
	    for (int i=1;i<num2_size;++i)
	    {
		    single_product=carry;
		    position=num1_size;
		    for (int j=i;j<num2_size;++j)
			    single_product=single_product+subproduct.at(j).at(position--);
		    carry=single_product/10;
		    answer=answer+char(single_product%10+'0');
	    }
	    if (carry!=0)
		    answer=answer+char(carry+'0');
	    reverse(answer.begin(),answer.end());
	    while (answer.at(0)=='0')
		    answer.erase(0,1);
	    return answer;
    }
};
