struct pair_hash {
    size_t operator()(const pair<int,int> & A) const {
        return A.first ^ A.second;
    }
};
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z==0 || x+y==z)
            return true;
        if (x+y<z)
            return false;
        unordered_set<pair<int,int>,pair_hash> helper_set;
        queue<pair<int,int>> helper_queue;
        helper_queue.push(make_pair(0,0));
        while (!helper_queue.empty())
        {
            if (helper_set.find(helper_queue.front())!=helper_set.end())
            {
                helper_queue.pop();
                continue;
            }
            pair<int,int> state=helper_queue.front();
            helper_queue.pop();
            helper_set.insert(state);
            int state_x=state.first,state_y=state.second;
            if (state_x==z || state_y==z || state_x+state_y==z)
                return true;
            //把A装满
            if (state_x<x)
                helper_queue.push(make_pair(x,state_y));
            //把B装满
            if (state_y<y)
                helper_queue.push(make_pair(state_x,y));
            //把A清空
            if (state_x!=0)
                helper_queue.push(make_pair(0,state_y));
            //把B清空
            if (state_y!=0)
                helper_queue.push(make_pair(state_x,y));
            //A倒水进B，B满了，A还有剩
            if (state_x+state_y>y)
                helper_queue.push(make_pair(state_x-y+state_y,y));
            //A倒水进B，B没满，A空了
            if (state_x+state_y<y)
                helper_queue.push(make_pair(0,state_x+state_y));
            //B倒水进A，A满了，B还有剩
            if (state_y+state_x>x)
                helper_queue.push(make_pair(x,state_y-x+state_x));
            //B倒水进A，A没满，B空了
            if (state_y+state_x<x)
                helper_queue.push(make_pair(state_x+state_y,0));
        }
        return false;
    }
};
