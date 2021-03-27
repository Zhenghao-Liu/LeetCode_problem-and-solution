/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (this NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (this NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (this *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (this NestedInteger) GetList() []*NestedInteger {}
 */

type NestedIterator struct {
	idx, sz int
	num     []int
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	ans := &NestedIterator{}
	ans.build(nestedList)
	ans.sz = len(ans.num)
	return ans
}

func (this *NestedIterator) build(nestedList []*NestedInteger) {
	for _, i := range nestedList {
		if i.IsInteger() {
			this.num = append(this.num, i.GetInteger())
		} else {
			this.build(i.GetList())
		}
	}
}

func (this *NestedIterator) Next() int {
	res := this.num[this.idx]
	this.idx++
	return res
}

func (this *NestedIterator) HasNext() bool {
	return this.idx < this.sz
}