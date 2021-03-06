type NumArray struct {
	prefix []int
}

func Constructor(nums []int) NumArray {
	sz := len(nums)
	var p NumArray
	p.prefix = make([]int, sz+1)
	p.prefix[0] = 0
	for i := 1; i <= sz; i++ {
		p.prefix[i] = nums[i-1] + p.prefix[i-1]
	}
	return p
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.prefix[j+1] - this.prefix[i]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
