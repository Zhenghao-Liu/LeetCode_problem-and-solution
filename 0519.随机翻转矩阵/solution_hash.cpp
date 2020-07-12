/*
* n_rows*n_cols最大1e8开数组存会mle
* 那么直接通过随机二维数组索引来返回1的位置即可
  即[i][j]代表index=i*row+j
* 但是要尽量少用rand，不然的话可以采用缓存已经是1的点，然后while随机位置变1，判断有无重复即可
* 先回到通过二维数组索引来定位[i][j]，假设一个映射关系V[index]={i,j} index=i*row+j
  假设此时一共有zero_size个0，那么如果要想一次随机就能随机到一定是0的位置，
  最理想的方法就是将0的位置和1的位置分开来存，可以用两个哈希表分别存，但是也mle的感觉而且插入删除很麻烦
** 改进方法:假设现在有zero_size个0，有V[index]即index在[0,zero_size-1]的范围内
  必然随机的范围也是在[0,zero_size-1]里面
  如果我随机到了V[x]这个位置要把他变成1，那么V[x]所对应的[x/column,x%column]就应该不再随机到
  那找到一个可以变成1的位置，zero_size=zero_size-1
  为了将0和1的位置分离开来，我可以把V[x]所对应的这个位置移动到当前0范围的末尾
  但是0范围末尾这个index所对应的位置没有被随机到，它有可能是被下次随机到的，要保留
  所以应该是将V[x]所对应的位置和当前0范围的末尾所对应的位置交换
  但是映射的key不变，
eg: 即映射的value=[[0][0] [0][1] [0][1] [1][1]]随机到index=1这个位置，那么将swap(V[1],V[3])，即之后value=[[0][0] [1][1] [0][1] [0][1]]
  但是对应的key一直是[0 1 2 3]只是V[1]原来是[0][1] 变成了 [1][1] 且zero_size=3
  这样下次再随机位置[0,zero_size-1]即只在[0,2]这个范围随机index了
* 但是V[index]为0的位置都是index=i*row+j，即通过index就可以求在二维矩阵里面的坐标
  因此没有必要存那些没有交换过且是0的位置
  只需要用changed_kv来存那些交换过后的映射即可
  即changed_kv[刚刚随机到要变成1的旧位置的index]=原本0范围末尾所对应的位置
* 注意一种情况：当前0范围的末尾的index已经交换过位置了，即这个index!=i*row+j
  所以不能单纯的changed_kv[cur]=zero_size
*/
class Solution {
    int row,column;
    int zero_size;
    unordered_map<int,int> changed_kv;
public:
    Solution(int n_rows, int n_cols) {
        row=n_rows;
        column=n_cols;
        zero_size=row*column;
        changed_kv.clear();
    }
    
    vector<int> flip() {
        int index=rand()%zero_size;
        --zero_size;
        int ans;
        if (changed_kv.find(index)==changed_kv.end())
            ans=index;
        else
            ans=changed_kv[index];
        int changed_pos;
        if (changed_kv.find(zero_size)==changed_kv.end())
            changed_pos=zero_size;
        else
            changed_pos=changed_kv[zero_size];
        changed_kv[index]=changed_pos;
        return {ans/column,ans%column};
    }
    
    void reset() {
        zero_size=row*column;
        changed_kv.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
