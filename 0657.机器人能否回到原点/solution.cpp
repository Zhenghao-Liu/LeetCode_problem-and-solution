//回到原点就是往上走步数等于往下走步数且往左走步数等于往右走步数
class Solution {
public:
    bool judgeCircle(string moves) {
        int count[4];
        memset(count,0,sizeof(count));
        unordered_map<char,int> dir;
        dir.insert({'U',0});
        dir.insert({'D',1});
        dir.insert({'L',2});
        dir.insert({'R',3});
        for (char &i:moves)
            ++count[dir.at(i)];
        return count[0]==count[1] && count[2]==count[3];
    }
};
