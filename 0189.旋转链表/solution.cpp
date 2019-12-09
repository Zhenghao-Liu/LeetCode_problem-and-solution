//环状替换
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nums_size=nums.size();
        k=k%nums_size;
        if (nums_size<2 || k==0)
            return;
        int loop_times=get_gcd(nums_size,k),temporary;
        for (int i=0;i<loop_times;++i)
        {
            temporary=nums.at(i);
            for (int j=i+k;j!=i;)
            {
                swap(temporary,nums.at(j));
                j=(j+k)%nums_size;
            }
            swap(temporary,nums.at(i));
        }
    }
    int get_gcd(int a,int b)
    {
      if (a<b)
        swap(a,b);
      int temporary;
      while (b!=0)
      {
        temporary=a%b;
        a=b;
        b=temporary;
      }
      return a;
    }
};
