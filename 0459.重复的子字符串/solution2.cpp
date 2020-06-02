/**
* 如果一个字符串可以由多个重复子串构成，即具有循环节
  设最小循环节用a来表示，他代表通过子串a重复多次可以构成s
  即s换成a来表示就是aa···aaa，由多少个最小循环节a构成s，那么就有几个a
* 找循环节一个一个对比比较麻烦，最简单方法就是s+s就可以直接增加多一倍的循环节
* 假设原来s=aaaa，那ss=s+s=aaaa aaaa
  因为是不断重复的循环节，可以通过简单的屏蔽的第一个字符，然后再在ss中寻找s
  因为屏蔽第一个字符，即第一个最小循环节被破坏，所以找到的s应该是从第二个循环节开始
* 但倘若不是由一个子串重复构成
  即s=abcd，那ss=abcd abcd=s+s
  屏蔽掉第一个字符，又因不匹配，所以在ss中寻找s，一定是对应着新增s的位置，即s.size()处
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s,1)!=s.size();
    }
};
