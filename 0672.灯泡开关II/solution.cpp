/*
* 1. 首先验证其实只用4位就可以代替所有情况
  5号肯定和3号状态一致， 6号肯定和2号状态一致，7肯定和1一致，8-->2 9-->3 10-->4 等等；
  所以压缩成4位就可以代表全部
* 2. 其实还可以进一步压缩成3位
  假设操作1实现a次，操作2实现b次，操作3实现c次，操作4实现d次
  灯泡1状态=(1+a+c+d)%2
  灯泡2状态=(1+a+b)%2
  灯泡3状态=(1+a+c)%2
  灯泡4状态=(1+a+b+d)%2
  可以根据灯泡1和灯泡2来判断d是偶数还是奇数，进而结合灯泡2和d来判断出灯泡4的状态
  即前3个灯泡就可以决定所有情况
*/
class Solution {
    int a=0b1;
    int b=0b10;
    int c=0b100;
    int d=0b1000;
    int key;
public:
    int flipLights(int n, int m) {
        key=(1<<min(4,n))-1;
        unordered_set<int> helper;
        helper.insert(0b1111);
        unordered_set<int> t;
        for (int i=0;i<m;++i)
        {
            t.clear();
            for (int i:helper)
            {
                t.insert(func1(i));
                t.insert(func2(i));
                t.insert(func3(i));
                t.insert(func4(i));
            }
            helper=t;
        }
        return helper.size();
    }
    int func1(int i)
    {
        i^=a;
        i^=b;
        i^=c;
        i^=d;
        i&=key;
        return i;
    }
    int func2(int i)
    {
        i^=b;
        i^=d;
        i&=key;
        return i;
    }
    int func3(int i)
    {
        i^=a;
        i^=c;
        i&=key;
        return i;
    }
    int func4(int i)
    {
        i^=a;
        i^=d;
        i&=key;
        return i;
    }
};
