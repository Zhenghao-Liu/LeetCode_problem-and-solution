class NumArray {
private:
    vector<int> sum_l_r;
public:
    NumArray(vector<int>& nums) {
        int nums_size=nums.size();
        sum_l_r.push_back(0);
        for (int i=0;i<nums_size;++i)
            sum_l_r.push_back(sum_l_r.at(i)+nums.at(i));
    }
    
    int sumRange(int i, int j) {
        return sum_l_r.at(j+1)-sum_l_r.at(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
