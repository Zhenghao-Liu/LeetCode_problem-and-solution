/*
* 对于所有除法a/b
  1.想要结果更大，分子a要更大，分母b要更小
  2.想要结果更小，分子a要更小，分母b要更大
* 设a/b/c/d，且题目说明所有数字>1
  对于a和b来说，a一定是分子，b一定是分母，无论怎么加括号都是无法改变的
  所以要想a/b/c/d变得更大，就应该让分母(b/c/d)变得更小
* 现在目标是要让b/c/d变得更小
  只有两种可能b/c/d=b/(c*d)
  b/(c/d)=b*d/c
  上两个式子同除b/c ，式1=1/d，式2=d显然式1<式2
  所以选b/c/d
* 所以结果是a/(b/c/d)
* 继续延伸a/b/c/d/e可以看成a/b/c/(d*e)而转变成上面的a/b/c/d即d*e变成上面的d
*/
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        int nums_size=nums.size();
        if (nums_size==1)
            return to_string(nums.at(0));
        if (nums_size==2)
            return to_string(nums.at(0))+"/"+to_string(nums.at(1));
        ans=to_string(nums.at(0))+"/(";
        for (int i=1;i<nums_size;++i)
            ans+=to_string(nums.at(i))+"/";
        ans.pop_back();
        ans+=")";
        return ans;
    }
};
