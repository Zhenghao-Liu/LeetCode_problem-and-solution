// 模拟
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> que;
        int sand=0;
        int size=students.size();
        for (int i=0;i<size;i++) {
            que.push(i);
        }
        int st=-1;
        while (sand<size) {
            int tar=sandwiches.at(sand);
            if (tar==students.at(que.front())) {
                sand++;
                que.pop();
                st=-1;
            } else {
                st=que.front();
                int tmp=que.front();
                que.pop();
                que.push(tmp);
                while (que.front()!=st && tar!=students.at(que.front())) {
                    tmp=que.front();
                    que.pop();
                    que.push(tmp);
                }
                if (que.front()==st) {
                    break;
                }
            }
            
        }
        return size-sand;
    }
};
