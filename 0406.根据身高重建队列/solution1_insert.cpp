/*
* 首先按照身高排序，再对second进行降序排序
  eg[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
  排序[[4,4],[5,2],[5,0],[6,1],[7,1],[7,0]]
* 我们填的时候要从数组后面往前填ans(即从[7,0]开始填)
* 为什么要这样子填？
  倘若我们按身高从小到大填，根据[i][1]我们还要往前面填几个比当前身高高的元素，那我选哪几个？无法确定
  但是按照身高由高到低填，就可以保证已填的ans中所有元素都是身高高于要填元素的，我只需要像插入排序一样找到前面有[i][1]个元素的位置插入即可
* 为什么要对second进行降序排序？
  因为同等身高的话，如果出现[i][1]大于0的情况，那么必然在ans中是同等身高[i][1]大的在后面，小的在前面，这样既可以做到和上述统一的插入方式
  eg:[1,1] [1,0] 那ans = [[1,0],[1,1]]
*/
struct ListPos
{
    int pos;
    ListPos *next;
    ListPos(int _pos) : pos(_pos) { next=NULL; }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(0)==B.at(0) ? A.at(1)>B.at(1) : A.at(0)<B.at(0);
        });
        //如果采用vector.insert每次插入都O(N)，不如用链表先存着，最后再赋值给ans
        ListPos *head=new ListPos(-1);
        int last_count=0;
        ListPos *p=head;
        int people_size=people.size();
        for (int i=people_size-1;i>=0;--i)
        {
            int count=people.at(i).at(1);
            //小优化，不用每次都从头开始遍历
            if (last_count<=count)
                count-=last_count;
            else
                p=head;
            while (count!=0)
            {
                p=p->next;
                --count;
            }
            ListPos *temp=p->next;
            p->next=new ListPos(i);
            p->next->next=temp;
            last_count=people.at(i).at(1);
        }
        vector<vector<int>> ans;
        p=head->next;
        while (p!=NULL)
        {
            ans.push_back(people.at(p->pos));
            p=p->next;
        }
        return ans;
    }
};
