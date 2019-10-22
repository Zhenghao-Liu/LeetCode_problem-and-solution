class Solution {
public:
    string addBinary(string a, string b) {
        int a_size=a.size(),b_size=b.size();
        //保证a的长度为小的
        if (a_size>b_size)
        {
            swap(a,b);
            swap(a_size,b_size);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string answer="";
        int carry=0,sum;
        int key[4]({0,1,10,11});
        for (int i=0;i<a_size;++i)
        {
            sum=a.at(i)-'0'+b.at(i)-'0'+carry;
            answer=answer+char(key[sum]%10+'0');
            carry=key[sum]/10;     
        }
        for (int i=a_size;i<b_size;++i)
        {
            sum=carry+b.at(i)-'0';
            answer=answer+char(key[sum]%10+'0');
            carry=key[sum]/10;
        }
        if (carry==1)
            answer=answer+'1';
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
