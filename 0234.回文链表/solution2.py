#这个方法只适合python，就是从前往后排成一个字符串，从后往前排成一个字符串，比较，但数过于太大不太适合其他语言
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        a=0
        b=0
        t=1
        while (head!=None):
            a=a*10+head.val
            b=b+(head.val)*t
            t=t*10
            head=head.next
        return a==b
