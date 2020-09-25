/*
* 题目是正着一个一个矩形打印，那就模拟方式，倒着从矩形开始去逆打印
* 1. 因为要统计一个矩形，所以要知道他的上下左右四个边界，即left,right,up,down
  2. 因为矩形可能有一部分被下一个打印的矩形覆盖，即他不是一个完整的矩形了，
     所以要用cnt记录当前该颜色的格子有几个，用rectangular_area统计他是完整矩形的话应该有多少个格子
  3. 再用exist记录题目数组中是否出现了该颜色，以及用active记录当前颜色是否已经被逆打印
* 1. 逆打印完一个矩形后，要将逆打印的区域的点增加到所有可能颜色的计数cnt中去，代表别的颜色可以使用这个格子逆打印
  2. 这样当cnt=rectangle_size即他有足够的格子后，可以逆打印该颜色
* 但是逆打印了一个地方的格子后，他不应该重复给别的颜色增加cnt，所以额外bool数组already_print代表该数组是否逆打印过
* 这样子一直去枚举可以逆打印的颜色，知道找不到可以逆打印的颜色，在判断所有存在的颜色是否都被逆打印了即是答案
*/
const int MAXC=61;
class COLOUR{
private:
    int left,right,up,down;
    int cnt,rectangular_area;
    bool active,exist;
public:
    COLOUR():left(INT_MAX),right(INT_MIN),up(INT_MAX),down(INT_MIN),active(false),exist(false),cnt(0),rectangular_area(0){}
    void update(int x,int y)
    {
        left=min(left,y);
        right=max(right,y);
        up=min(up,x);
        down=max(down,x);
        ++cnt;
        rectangular_area=(right-left+1)*(down-up+1);
    }
    bool get_active(){return active;}
    void set_active(bool bo){active=bo;}
    bool get_exist(){return exist;}
    void set_exist(bool bo){exist=bo;}
    bool inside(int x,int y){return left<=y && y<=right && up<=x && x<=down;}
    void inc_cnt(){++cnt;}
    bool can_print(){return active && exist && cnt==rectangular_area;}
    pair<int,int> get_left_right(){return {left,right};}
    pair<int,int> get_up_down(){return {up,down};}
};
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        COLOUR color[MAXC];
        int row=targetGrid.size(),column=targetGrid.at(0).size();
        vector<vector<bool>> already_print(row,vector<bool>(column,false));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
            {
                int cur=targetGrid.at(i).at(j);
                color[cur].set_active(true);
                color[cur].set_exist(true);
                color[cur].update(i,j);
            }
        bool judge_print;
        do
        {
            judge_print=false;
            for (int cur=1;cur<MAXC;++cur)
                if (color[cur].can_print())
                {
                    judge_print=true;
                    color[cur].set_active(false);
                    auto [left,right]=color[cur].get_left_right();
                    auto [up,down]=color[cur].get_up_down();
                    for (int i=up;i<=down;++i)
                        for (int j=left;j<=right;++j)
                        {
                            if (already_print.at(i).at(j))
                                continue;
                            already_print.at(i).at(j)=true;
                            for (int nxt=1;nxt<MAXC;++nxt)
                            {
                                if (!color[nxt].get_exist() || !color[nxt].get_active())
                                    continue;
                                if (color[nxt].inside(i,j))
                                    color[nxt].inc_cnt();
                            }
                        }
                }
        }while (judge_print);
        for (int i=1;i<MAXC;++i)
            if (color[i].get_exist() && color[i].get_active())
                return false;
        return true;
    }
};
