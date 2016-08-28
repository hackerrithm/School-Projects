/*
------| Group Members 						|-------
------| Andrex Reid   ID#: 1302569			|-------
------| Kemar Galloway ID#: 1301055			|-------
------| Module: Data Structures				|-------
------| Module code: CMP2006				|-------
------| Tutor: Mr. David White				|-------
------| University of Technology, Jamaica	|-------

*/
package rpncalculator;
import java.util.Vector;

public class Stack<UserDataType>
{
	private Vector<UserDataType> stack;
	private int top = -1;
	
	public Stack()
	{
		stack = new Vector<UserDataType>();
	}
	
	//Big O efficiency is O(1)
	public void push(UserDataType object)
	{
		stack.add(object);
		top++;
	}
	
	//Big O efficiency is O(1)
	public UserDataType peek()
	{
		if(top == -1)
		{
			return null;
		}
		UserDataType temp = stack.get(top);
		return temp;
	}
	
	//Big O efficiency is O(1)
	public UserDataType pop()
	{
		if(top == -1)
		{
			return null;
		}
		UserDataType temp = stack.get(top);
		stack.remove(top);
		top--;
		return temp;
	}
	//Big O efficiency is O(1)
	public boolean isEmpty()
	{
		return (top == -1);
	}
}


