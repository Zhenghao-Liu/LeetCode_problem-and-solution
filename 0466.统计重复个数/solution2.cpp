/*
1. 真正的最小循环节其实是[start+1,k]，所以循环节所占的段数即cycle_contain_segments=k-(start+1)+1=k-start
2. 段落之间是以序号1开始的，但是start是以0开始的，这是为了防止第一段就是最小循环节的情况，即interval=1=1-0情况
3. s2_not_in_cycles在所有段中，除去循环节所占段数，剩下不是循环节段数所包含的s2(小写的s)个数，因为循环节肯定是在段落的中间，所以start就是循环节左边有几个段，(n1-start)%cycle_contain_segments则是循环节右边有几个段，为什么可以直接相加求呢？因为每个段都是一模一样的啊，times_s2_appea虽然是从左到右每个段出现s2的个数，但既然每个段内容都是一样的，可以想象循环节右边的段直接顶替中间的循环节，和循环节左边的段连接在一起，因为段都是一样的自然times_s2_appea的结果也是一样的
4. 若没有循环节，即退回到第一个方法unsolved1
5. 相比于第一个方法的优化：第一个方法是要遍历一遍S1(大写的S)，而且还要构建S2(大写的S)，而方法二省去构建S1、S2，因为S1是分段讨论，每一段相同没必要构造S1，S2则通过放缩也不必构建，而且方法二是一旦找到了最小的循环节，直接就return了，大部分情况都可以做到遍历几个段直接return，直接起飞好吧
6. 为什么有相同的索引即next_s2_index相同就代表出现了循环节呢？因为每一段都相同，倘若开始匹配的索引相同，结束时候传给下一个段的索引也是必然相同的，自然是循环节的标志
*/
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int s1_size=s1.size(),s2_size=s2.size();
        //将S1分n1个段，每个段是相同的s1，段落序号从1开始
        //times_s2_appear[i]是从到第1段到第i段s2出现的个数，[0]没有实际意义
        vector<int> times_s2_appear(n1+1,0);
        //next_s2_index[i]表示第i段时，要从s2[next_s2_index[i]]这个字符开始匹配
        //因为可能上一段匹配了一半s2，下一段接着匹配
        vector<int> next_s2_index(n1+1,0);
        int count_s2_appear=0;
        int j=0;
        //第k段
        for (int k=1;k<=n1;++k)
        {
            for (int i=0;i<s1_size;++i)
                if (s1.at(i)==s2.at(j))
                {
                    ++j;
                    //匹配完一个s2，增加s2出现个数并重置匹配的索引
                    if (j==s2.size())
                    {
                        j=0;
                        ++count_s2_appear;
                    }
                }
            times_s2_appear.at(k)=count_s2_appear;
            next_s2_index.at(k)=j;
            //通过每一段开始的匹配s2的索引来寻找是否出现最小循环节
            //注意段落k是从1开始的，start是从0开始的，这样是为了防止第一个段落就出现循环节
            for (int start=0;start<k;++start)
                if (next_s2_index.at(start)==next_s2_index.at(k))
                {
                    //即第一个出现最小循环节的段是[start+1,k]
                    int cycle_contain_segments=k-start;
                    //在所有段中最小循环节一共有多少个
                    int num_of_cycles=(n1-start)/cycle_contain_segments;
                    //所有循环节中一共包含了几个s2=一个最小循环节中包含s2个数*一共有多少个最小循环节
                    int s2_in_cycles=(times_s2_appear.at(k)-times_s2_appear.at(start))*num_of_cycles;
                    //在所有段落中除了循环节剩余的段落中一共包含几个s2
                    //所有剩余段落个数=循环节左边段落个数+循环节右边段落个数
                    int s2_not_in_cycles=times_s2_appear.at(start+(n1-start)%cycle_contain_segments);
                    //S1中包含了x个s2，即包含了x/n2个S2
                    return (s2_in_cycles+s2_not_in_cycles)/n2;
                }
        }
        //倘若没有循环节，那么也遍历完一遍S1了，即也求出S1中包含多少个s2了
        return times_s2_appear.at(n1)/n2;
    }
};
