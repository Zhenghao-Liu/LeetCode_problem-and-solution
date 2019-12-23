class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //multiset会默认按升序排序
        //采用了pair定义了捆绑的类型，所以按first排序，相同时则按second排序
        multiset<pair<int,int>> all;
        for (vector<int> &i:buildings)
        {
            //左,-高
            all.insert(make_pair(i.at(0),-i.at(2)));
            //右,高
            all.insert(make_pair(i.at(1),i.at(2)));
        }
        vector<vector<int>> answer;
        //用来记录当前遍历中的高度，也是有排序的
        multiset<int> heights;
        //初始高度为0
        heights.insert(0);
        //用来记录上一个节点
        vector<int> last({0,0});
        int max_heights;
        for (auto& i:all)
        {
            if (i.second<0)
                //左端顶点，入堆
                heights.insert(-i.second);
            else
                //右端顶点，出堆
                //切记不可直接erase(int)，这样是删除所有等于int的值，对于有相同高度的会出错
                heights.erase(heights.find(i.second));
            //heights是自动排序的，所以最后一个即最大的值，即当前最大的高度
            max_heights=*(heights.rbegin());
            //如果上一个节点和当前高度不一样，表明出现了转折点
            if (last.at(1)!=max_heights)
            {
                //因为左端点高度入堆，右端点高度出堆
                last.at(1)=max_heights;
                //这里可能是左，可能是右
                last.at(0)=i.first;
                answer.push_back(last);
            }
        }
        return answer;
    }
};
