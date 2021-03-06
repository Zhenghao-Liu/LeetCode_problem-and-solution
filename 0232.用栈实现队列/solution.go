type MyQueue struct {
	sta1, sta2 []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	ans := MyQueue{}
	return ans
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.sta1 = append(this.sta1, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	if len(this.sta2) == 0 {
		for len(this.sta1) != 0 {
			this.sta2 = append(this.sta2, this.sta1[len(this.sta1)-1])
			this.sta1 = this.sta1[:len(this.sta1)-1]
		}
	}
	ans := this.sta2[len(this.sta2)-1]
	this.sta2 = this.sta2[:len(this.sta2)-1]
	return ans
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	if len(this.sta2) == 0 {
		for len(this.sta1) != 0 {
			this.sta2 = append(this.sta2, this.sta1[len(this.sta1)-1])
			this.sta1 = this.sta1[:len(this.sta1)-1]
		}
	}
	return this.sta2[len(this.sta2)-1]
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.sta1) == 0 && len(this.sta2) == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
