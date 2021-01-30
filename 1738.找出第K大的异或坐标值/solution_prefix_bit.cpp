// 二维前缀位运算
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int row=matrix.size();
        int col=matrix.at(0).size();
        pq.push(matrix.at(0).at(0));
        for (int i=1;i<col;i++) {
            matrix.at(0).at(i)^=matrix.at(0).at(i-1);
            pq.push(matrix.at(0).at(i));
            if (pq.size()>k) {
                pq.pop();
            }
        }
        for (int i=1;i<row;i++) {
            matrix.at(i).at(0)^=matrix.at(i-1).at(0);
            pq.push(matrix.at(i).at(0));
            if (pq.size()>k) {
                pq.pop();
            }
        }
        for (int i=1;i<row;i++) {
            for (int j=1;j<col;j++) {
                matrix.at(i).at(j)^=matrix.at(i-1).at(j)^matrix.at(i).at(j-1)^matrix.at(i-1).at(j-1);
                pq.push(matrix.at(i).at(j));
                if (pq.size()>k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
