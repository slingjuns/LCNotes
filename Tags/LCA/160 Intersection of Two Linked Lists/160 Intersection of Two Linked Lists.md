# 160. Intersection of Two Linked Lists

Careful: No
Difficulty: Easy
Index: 160
Programming Language: C++
Skills: 1. Actually we don't care about the "value" of difference, we just want to make sure two pointers reach the intersection node at the same time.
2. We can use two iterations to do that. In the first iteration, we will reset the pointer of one linkedlist to the head of another linkedlist after it reaches the tail node. In the second iteration, we will move two pointers until they points to the same node. Our operations in first iteration will help us counteract the difference. So if two linkedlist intersects, the meeting point in second iteration must be the intersection point. If the two linked lists have no intersection at all, then the meeting pointer in second iteration must be the tail node of both lists, which is null
Tags: LCA, Linked List
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

```python
def findIntersection(l1:ListNode, l2:ListNode):
	a, b = l1, l2
	while a != b:
		a = a.next if a.next else l2
		b = b.next if b.next else l1
	return a
```