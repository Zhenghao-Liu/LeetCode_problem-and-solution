/*
* 洗牌算法，保证所有序列出现概率都一样
* 在遍历到i时，从[i]到[nums.size()-1]所有元素中随机选取一个，设为[index]
* 将[index]与[i]进行交换，再++i接着向下遍历
* 注意：不能直接选[index]元素，因为这样下一次[i]就没有出现的可能了，就不是所有序列概率都一样
*/
class Solution {
    vector<int> original;
    int size;
public:
    Solution(vector<int>& nums) {
        original=nums;
        size=nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(original);
        for (int i=0;i<size;++i)
        {
            int index=rand()%(size-i)+i;
            swap(ans.at(i),ans.at(index));
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
