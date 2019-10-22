static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int romanToInt(string s) {
    int s_size=s.size(),num=0;
    for (int i=0;i<s_size;++i)
	{
		switch (s[i]){
			case 'I':
				if (s[i+1]=='V')
				{
					num=num+4;
					++i;
					break;
				}
				else if (s[i+1]=='X')
				{
					num=num+9;
					++i;
					break;
				}
				else
				{
					++num;
					break;	
				}		
			case 'V':
				num=num+5;
				break;
			case 'X':
				if (s[i+1]=='L')
				{
					num=num+40;
					++i;
					break;
				}
				else if (s[i+1]=='C')
				{
					num=num+90;
					++i;
					break;
				}
				else
				{
					num=num+10;
					break;	
				}
			case 'L':
				num=num+50;
				break;
			case 'C':
				if (s[i+1]=='D')
				{
					num=num+400;
					++i;
					break;
				}
				else if (s[i+1]=='M')
				{
					num=num+900;
					++i;
					break;
				}
				else
				{
					num=num+100;
					break;	
				}
			case 'D':
				num=num+500;
				break;
			case 'M':
				num=num+1000;
				break;
		}
	}
	return num;        
    }
};
