class Min_Stack
{
    long int mini;
    stack<long int> s;
    public:
        Min_Stack()
        {
            mini = INT_MAX;
        }
        void push(int x)
        {
            if(x >= mini)
            {
                s.push(x);
            }
            else
            {
                s.push(x - mini);
                mini = x;
            }
        }
        int pop()
        {
            if(isEmpty())
	    {
		return -1;
	    }
	    int val = mini;
            if(s.top() < mini)
            {
                mini = mini - s.top();
            }
            s.pop();
            return val;
        }
	int getMin()
	{
	    return mini;
	}
	bool isEmpty()
	{
	    return s.empty();
	}
};
