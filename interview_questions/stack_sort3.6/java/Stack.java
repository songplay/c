class Stack {
	private	int	sp;
	private	int	stack_size;
	private int[]	mystack;

	boolean IsEmpty()
	{
		if (sp <= 0)
			return	true;
		else
			return	false;
	}

	void Push(int data)
	{
		if (sp < stack_size) {
			sp = sp+1;
			mystack[sp] = data;
		}else
		System.err.println("Stack is full. size=" + stack_size);
	}

	int Pop()
	{
		int	d=0;

		if (!IsEmpty()) {
			d = mystack[sp];
			sp = sp -1;
		} else
		System.err.println("Pop: Stack is underflow.");

		return	d;
	}

	int Peek()
	{
		if (!IsEmpty())
			return	mystack[sp];
		else {
			System.err.println("Peek: Stack is empty.");
			return	0;
		}
	}

	Stack()
	{	
		stack_size = 100;
		mystack = new int[stack_size];
		this.sp = 0;
	}

	Stack(int size)
	{	
		stack_size = size;
		mystack = new int[stack_size];
		this.sp = 0;
	}

	public static void main(String[] args) {
		int	d;
		Stack	s;

		s = new Stack();
		System.out.println("Hello this is a new Stack");
		s.Push(111);
		s.Push(222);

		d = s.Peek();
		System.out.println(d);
	}
}
