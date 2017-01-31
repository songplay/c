/*
 * Sort a stack
 * 1/8/2017
 */
#include <stdio.h>

/* Find and pop the Biggest */
Item
FindBiggest()
{
	s1 = new stack();

	s = this();
	Biggest = s.pop();
	while (s.IsEMpty() == FALSE){
		item = s.pop();
		if (item < Biggest)
			Biggest = item;
		else
			s1.Push(item);
	}

	/* restore the stack */
	while (s1.IsEMpty() == FALSE){
		s.push(s1.pop());
}

void
SortStack()
{

	/* pop the whole stack to find the Biggest,
	 * place the Biggest to the stack bottom
	 * repeat this process with sp+1 until the top
	 */
	s = this();

	/* allocate a new stack as temp storage */
	s2 = new stack();
	while (!s.IsEmpty())
		s2.push(s.FindBiggest());

	/* copy s2 back to s with a reverse */
	while (!s2.IsEmpty)
		s.push(s2.pop));
}
