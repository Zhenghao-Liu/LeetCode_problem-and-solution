class Solution {
public:
vector<string> restoreIpAddresses(string s) 
{
	int s_size=s.size();
	if (s_size<4 || s_size>12 || s=="0.0.0.0")
		return {};
	vector<string> possible_answer;
	get_ip_adderss(possible_answer,s,0,1);
	int possible_ip_size,possible_ip_part_size;
	vector<string> answer;
	bool judge;
	for (string possible_ip:possible_answer)
	{
		judge=true;
		possible_ip_size=possible_ip.size();
		int i=0;
		for (int j=0;j<4;++j)
		{
			possible_ip_part_size=0;
			while (i<possible_ip_size && possible_ip.at(i)!='.')
			{
				++i;
				++possible_ip_part_size;
			}
			++i;
			if (possible_ip_part_size==1)
				continue;
			else if (possible_ip_part_size==2 && possible_ip.at(i-3)=='0')
			{
				judge=false;
				break;
			}
			else if (possible_ip_part_size==3)
			{
				if (possible_ip.at(i-4)=='0' || possible_ip.at(i-4)>'2')
				{
					judge=false;
					break;
				}
				int temporary=0;
				for (int k=0;k<3;++k)
					temporary=temporary+(possible_ip.at(i-k-2)-'0')*pow(10,k);
				if (temporary>255)
				{
					judge=false;
					break;
				}
			}
			else if (possible_ip_part_size>3)
			{
				judge=false;
				break;
			}
		}
		if (judge==true)
			answer.push_back(string(possible_ip));
	}
	return answer;
}
void get_ip_adderss(vector<string>& possible_answer,string s,int point_exist,int start_position)
{
	if (point_exist==3)
	{
		possible_answer.push_back(string(s));
		return;
	}	
	string temporary_s;
	for (int i=0;i<3;++i)
	{
		temporary_s=s;
		if (start_position+i>=s.size())
			return;
		temporary_s.insert(temporary_s.begin()+start_position+i,'.');
		get_ip_adderss(possible_answer,temporary_s,point_exist+1,start_position+i+2);
	}
}
};
