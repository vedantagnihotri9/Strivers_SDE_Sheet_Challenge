#include <bits/stdc++.h>
void sortedInsert(stack<int> &stack, int num)
{
	if (stack.empty() || stack.top() < num) 
	{
		stack.push(num);
		return;
	}

	int x= stack.top();
	stack.pop();

	sortedInsert(stack, num);
	//inserting removed element
	stack.push(x);
} 
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
		return;
	int num=stack.top();
	stack.pop();

	sortStack(stack);

	sortedInsert(stack,num);
}