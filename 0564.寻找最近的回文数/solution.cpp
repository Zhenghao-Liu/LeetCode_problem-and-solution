/*
* 设n=abcxy
  有两种普通形式
  1. abcba 两者间差距是10*(abs(x-b))+abs(y-1)
  2. yxcxy 两者间差距是10000*(abs(x-b))+100000(abs(y-a))
  显然第一种情况的差值要更小，我们把这种情况设为diff1
* 但假如是10000，变成10001，但倘若将前半部分减1,再构建回文，即10000->09900->9999，虽然绝对差值一样但是后者更小所以答案是9999
  这种情况还有1000，即1000->990>999
  把这种将中间位置倘若出现了0，那么将它左半部分减1，
  但有可能最左边是1的情况即要删除一位字符，这时候还要考虑是否要补充多一位9，像上面1000的例子
  把这种中间出现0，要减去1的情况差值设为diff2
* 假如是10987，按diff1来变成10901，当倘若将前半部分加1，再构建回文，即10987->11087->11011，后者绝对差值更小所以答案是11011
  把这种中间出现9的情况，将他左半部分加1，
  但有可能最左边还是9，这时候要补充一个"1"在最左边
  把这种中间出现9，左半部分加1情况差值设为diff3
* 比较3者差值，在差值相同情况下选择回文后值最小的数
* 但有特殊情况就是只有一位数时候，他自身就是回文数，又要绝对差最小，且回文数小，那么就是本身-1
*/
class Solution {
public:
    string nearestPalindromic(string n) {
        int size=n.size();
        long long num=stoll(n);
        if (num<10)
            return to_string(num-1);
        string n1=mirror_num(n);
        long long diff1=abs(num-stoll(n1));
        if (diff1==0)
            diff1=INT_MAX;
        string n2=n;
        int i;
        for (i=(size-1)/2;i>0;--i)
            if (n2.at(i)=='0')
                n2.at(i)='9';
            else
                break;
        if (i==0 && n2.at(i)=='1')
        {
            n2.erase(n2.begin());
            int j=((int)n2.size()-1)/2;
            n2.at(j)='9';
        }
        else
            n2.at(i)=char(n2.at(i)-1);
        n2=mirror_num(n2);
        long long diff2=abs(num-stoll(n2));
        string n3=n;
        for (i=(size-1)/2;i>=0;--i)
            if (n3.at(i)=='9')
                n3.at(i)='0';
            else
                break;
        if (i==-1)
            n3.insert(n3.begin(),'1');
        else
            n3.at(i)=char(n3.at(i)+1);
        n3=mirror_num(n3);
        long long diff3=abs(num-stoll(n3));
        if (diff2<=diff3 && diff2<=diff1)
            return n2;
        else if (diff1<=diff2 && diff1<=diff3)
            return n1;
        return n3;
    }
    string mirror_num(string s)
    {
        int s_size=s.size();
        string ss;
        int end=(s_size+1)/2;
        for (int i=0;i<end;++i)
            ss+=s.at(i);
        int i;
        if (s_size%2==0)
            i=end-1;
        else
            i=end-2;
        for (;i>=0;--i)
            ss+=s.at(i);
        return ss;
    }
};
