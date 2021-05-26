// 虫洞算法：标记每个括号对应的括号位置，用于遍历时进行跳跃，以及别忘了转向
class Solution {
public:
    string reverseParentheses(string s) {
        int sz=s.size();
        stack<int> sta;
        vector<int> jmp(sz,-1);
        for (int i=0;i<sz;i++) {
            if (s.at(i)=='(') {
                sta.push(i);
            } else if (s.at(i)==')'){
                int top=sta.top();
                sta.pop();
                jmp.at(top)=i;
                jmp.at(i)=top;
            }
        }
        string ans;
        int dir=1;
        for (int i=0;i<sz;i+=dir) {
            if (s.at(i)=='(' || s.at(i)==')') {
                dir*=-1;
                i=jmp.at(i);
            } else {
                ans+=s.at(i);
            }
        }
        return ans;
    }
};