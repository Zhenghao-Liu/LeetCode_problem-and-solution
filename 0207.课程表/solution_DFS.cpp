class Solution {
    struct adjacency_list
    {
        //记录前驱
        int precursor=0;
        //记录它所有后继，按理来说应该用链表
        vector<int> nextarc;
        //还有一个是记录当下节点权值，因为拓扑排序只用到了检测有无环，所以记录个数即可
    };
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<adjacency_list> all_class(numCourses);
        for (vector<int>& i:prerequisites)
        {
            ++all_class.at(i.at(0)).precursor;
            all_class.at(i.at(1)).nextarc.push_back(i.at(0));
        }
        stack<int> helper_stack;
        for (int i=0;i<numCourses;++i)
            if (all_class.at(i).precursor==0)
            {
                --all_class.at(i).precursor;
                helper_stack.push(i);
            }   
        int count=0,p,p_nextarc_size;
        while (!helper_stack.empty())
        {
            ++count;
            p=helper_stack.top();
            helper_stack.pop();
            p_nextarc_size=all_class.at(p).nextarc.size();
            for (int i=0;i<p_nextarc_size;++i)
                --all_class.at(all_class.at(p).nextarc.at(i)).precursor;
            for (int i=0;i<numCourses;++i)
                if (all_class.at(i).precursor==0)
                {
                    --all_class.at(i).precursor;
                    helper_stack.push(i);
                } 
        }
        return count==numCourses;
    }
};
