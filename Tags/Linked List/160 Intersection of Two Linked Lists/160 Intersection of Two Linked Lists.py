def findIntersection(l1:ListNode, l2:ListNode):
	a, b = l1, l2
	while a != b:
		a = a.next if a.next else l2
		b = b.next if b.next else l1
	return a
