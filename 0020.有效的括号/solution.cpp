static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isValid(string s) {
    int size_s=s.size();
    if (size_s==0)
        return true;
    stack<char>stack_s;
    for (int i=0;i<size_s;++i)
    {
        switch (s[i]){
        	case '(':
        	case '[':
        	case '{':stack_s.push(s[i]);break;
        	case ')':
        		if (stack_s.empty() || stack_s.top()!='(')
        			return false;
        		else
        		{
					stack_s.pop(); 
        			break;
        		}
        	case ']':
        		if (stack_s.empty() || stack_s.top()!='[')
        			return false;
        		else
        		{
					stack_s.pop(); 
        			break;
        		}
        	case '}': 
        		if (stack_s.empty() || stack_s.top()!='{')
        			return false;
        		else
        		{
					stack_s.pop(); 
        			break;
        		}
        	default:break;
		}
    }
    return (stack_s.empty());
    }
};
