/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
	if left == right {
		return head
	}
	dummy := &ListNode{
		Next: head,
	}
	var st *ListNode = dummy
	var idx int
	for idx < left-1 {
		st = st.Next
		idx++
	}
	var ed *ListNode = st.Next
	for idx < right-1 {
		tar := ed.Next
		ed.Next = tar.Next
		tar.Next = st.Next
		st.Next = tar
		idx++
	}
	return dummy.Next
}
