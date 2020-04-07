//首先看懂300题，其实是LIS的二维拓展
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int envelopes_size=envelopes.size();
        if (envelopes_size==0)
            return 0;
        int len=1;
        vector<int> last_h_in_LIS(envelopes_size+1);
        //排序好了第一位，那么就可以对第二位进行LIS分析
        //注意[i][0]==[j][0]时对于第二个值要逆序，这样子对于[[1,1],[1,2]]排序成[[1,2],[1,1]]就不会出现错误
        sort(envelopes.begin(),envelopes.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(0)==B.at(0) ? A.at(1)>B.at(1) : A.at(0)<B.at(0);
        });
        last_h_in_LIS.at(1)=envelopes.at(0).at(1);
        for (int i=1;i<envelopes_size;++i)
            if (envelopes.at(i).at(1)>last_h_in_LIS.at(len))
            {
                ++len;
                last_h_in_LIS.at(len)=envelopes.at(i).at(1);
            }
            else if (envelopes.at(i).at(1)<last_h_in_LIS.at(len))
            {
                //偷懒使用lower_bound,注意该函数处理的是有序的区间，所以要限定好区间
                int pos=lower_bound(last_h_in_LIS.begin()+1,last_h_in_LIS.begin()+len+1,envelopes.at(i).at(1))-last_h_in_LIS.begin();
                last_h_in_LIS.at(pos)=envelopes.at(i).at(1);
            }
        return len;
    }
};
