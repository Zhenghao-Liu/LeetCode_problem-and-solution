//和207.课程表 一样做法
class Solution {
private:
    struct adjacency_list
    {
        //记录前驱
        int precursor=0;
        //记录它所有后继，按理来说应该用链表
        vector<int> nextarc;
        //采用vector的下标来实现记录顺序
    };
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        int p,p_nextarc_size;
        vector<int> answer;
        while (!helper_stack.empty())
        {
            p=helper_stack.top();
            answer.push_back(p);
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
        if (answer.size()==numCourses)
            return answer;
        else
            return {};
    }
};
