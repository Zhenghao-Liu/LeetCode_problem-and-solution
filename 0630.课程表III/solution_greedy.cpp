/*
* 假设(t1,d1)和(t2,d2)，设起始时间为x
* 可以先选择t1，再t2，那么需要满足
  1. x+t1<=d1
  2. x+t1+t2<=d2
* 也可以选先t2，再t1，那么需要满足
  3. x+t2<=d2
  4. x+t2+t1<=d1
* 倘若我们按照d的升序来排列，即设d1<=d2
  则4.公式可以变成x+t1+t2<=d1<=d2即4.公式一定满足2.公式
  且4.公式可以变成x+t1<=d1-t2<=d1即4.公式一定满足2.公式
  即结论：d1<=d2下，
  若能先t2再t1，则一定也可以先t1再t2
  若先t1再t2，不一定满足先t2再t1
  为了能满足尽可能多的课程，先将数组按照d的升序排列，且先t1再t2的顺序去选
* 若当前已经选了k门课
  即满足t1+t2+···+tk<=dk
* 选择第k+1门课，设i=k+1
  1. 若满足t1+t2+···+tk+ti<=di则直接选入
  2. 若不满足上式子，要想不等式左边加上ti后尽可能的小，应该选择[t1 t2 ··· tk]中的最大值设为tmax，
     且要了不等式满足，要保证tmax>ti，这样不等式左边移出tmax，再加上ti后，且因为di>=dk，不等式一定还满足
* 维护已经选择t的最大值采用堆
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int courses_size=courses.size();
        sort(courses.begin(),courses.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)<B.at(1);
        });
        int cur_time=0;
        int ans=0;
        priority_queue<int,vector<int>,less<int>> pq;
        for (vector<int> &i:courses)
        {
            if (i.at(0)+cur_time<=i.at(1))
            {
                cur_time+=i.at(0);
                pq.push(i.at(0));
            }
            else if (!pq.empty() && i.at(0)<pq.top())
            {
                cur_time-=pq.top();
                pq.pop();
                cur_time+=i.at(0);
                pq.push(i.at(0));
            }
        }
        return (int)pq.size();
    }
};
