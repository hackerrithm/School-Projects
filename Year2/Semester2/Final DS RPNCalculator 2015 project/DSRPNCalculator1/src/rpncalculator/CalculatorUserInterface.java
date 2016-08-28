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

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.StringTokenizer;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.border.EmptyBorder;

import rpncalculator.FileOperation;
import rpncalculator.Stack;

@SuppressWarnings("serial")

public class CalculatorUserInterface extends JFrame
{
	
	private Stack<Double> stack = new Stack<Double>();
	private Stack<String> operator = new Stack<String>();
	private FileOperation file = new FileOperation();
	/*	Declare buttons which will be used in the Reverse Polish Calculator
	 * 	
	 * */
	private JButton zero, one, two, three, four, 
					five, six, seven, eight, 
					nine,	equal, power, divide, 
					multiply, add, subtract, decimal,
					negate, space, mode, clear, 
					backspace, fileStore, memory, exit;		

	private JTextField answerField;
	private JTextField answerField2;
	private JPanel contentPanel;
	

	@SuppressWarnings("unused")
	private String str1, str2, sAnswer;
	private double answer = 0.0;
	
	
	private boolean equalClicked = false;
	private boolean opChosen = false;

	public CalculatorUserInterface()
	{
		super("HP-35 Claculator");
		setVisible(true);
		setDesign();
		setSize(400,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setResizable(false);	

		answerField2 = new JTextField(null,34);
		answerField  = new JTextField(null, 30);
		
		answerField2.setEditable(false);
		answerField.setEditable(false);
		answerField2.setPreferredSize(new Dimension(50,30));
		answerField.setPreferredSize(new Dimension(90,90));
		answerField.setFont(new Font("monospaced", Font.BOLD, 20));
		answerField.setHorizontalAlignment(SwingConstants.RIGHT);
		answerField2.setBorder(new EmptyBorder(3, 5, 3, 25) );
		answerField2.setBackground(Color.DARK_GRAY);
		answerField2.setForeground(Color.WHITE);
		answerField.setBorder(new EmptyBorder(0, 5, 0, 25) );
		answerField.setBackground(Color.BLACK);
		answerField.setForeground(Color.GREEN);
		answerField2.setText("   Reverse Polish Notation Calculator");
		answerField.setText("0");
	
		zero = new JButton("0");
		one = new JButton("1");
		two = new JButton("2");
		three = new JButton("3");
		four = new JButton("4");
		five = new JButton("5");
		six = new JButton("6");
		seven = new JButton("7");
		eight = new JButton("8");
		nine = new JButton("9");
		equal = new JButton("=");
		power = new JButton("^");
		divide = new JButton("/");
		multiply = new JButton("*");
		add = new JButton("+");
		subtract = new JButton("-");
		decimal = new JButton(".");
		negate = new JButton("+/-");
		space = new JButton("Space");
		mode = new JButton("Mode");
		clear = new JButton("c");
		backspace = new JButton("b");
		fileStore = new JButton("f");
		memory = new JButton("m");
		exit = new JButton("x");
		

		Dimension dimen = new Dimension(70, 60);

		//Sets the size, font and color of each Button
		zero.setPreferredSize(dimen);
		zero.setBackground(Color.lightGray);
		zero.setFont(new Font("monospaced", Font.BOLD, 40));
		one.setPreferredSize(dimen);
		one.setBackground(Color.lightGray);
		one.setFont(new Font("monospaced", Font.BOLD, 40));
		two.setPreferredSize(dimen);
		two.setBackground(Color.lightGray);
		two.setFont(new Font("monospaced", Font.BOLD, 40));
		three.setPreferredSize(dimen);
		three.setBackground(Color.lightGray);
		three.setFont(new Font("monospaced", Font.BOLD, 40));
		four.setPreferredSize(dimen);
		four.setBackground(Color.lightGray);
		four.setFont(new Font("monospaced", Font.BOLD, 40));
		five.setPreferredSize(dimen);
		five.setBackground(Color.lightGray);
		five.setFont(new Font("monospaced", Font.BOLD, 40));
		six.setPreferredSize(dimen);
		six.setBackground(Color.lightGray);
		six.setFont(new Font("monospaced", Font.BOLD, 40));
		seven.setPreferredSize(dimen);
		seven.setBackground(Color.lightGray);
		seven.setFont(new Font("monospaced", Font.BOLD, 40));
		eight.setPreferredSize(dimen);
		eight.setBackground(Color.lightGray);
		eight.setFont(new Font("monospaced", Font.BOLD, 40));
		nine.setPreferredSize(dimen);
		nine.setBackground(Color.lightGray);
		nine.setFont(new Font("monospaced", Font.BOLD, 40));
		equal.setPreferredSize(dimen);
		equal.setBackground(Color.YELLOW);
		equal.setFont(new Font("monospaced", Font.BOLD, 40));
		power.setPreferredSize(dimen);
		power.setBackground(Color.CYAN);
		power.setFont(new Font("monospaced", Font.PLAIN, 40));
		divide.setPreferredSize(dimen);
		divide.setBackground(Color.CYAN);
		divide.setFont(new Font("monospaced", Font.PLAIN, 40));
		multiply.setPreferredSize(dimen);
		multiply.setBackground(Color.CYAN);
		multiply.setFont(new Font("monospaced", Font.PLAIN, 40));
		add.setPreferredSize(dimen);
		add.setBackground(Color.CYAN);
		add.setFont(new Font("monospaced", Font.PLAIN, 40));
		subtract.setPreferredSize(dimen);
		subtract.setBackground(Color.CYAN);
		subtract.setFont(new Font("monospaced", Font.PLAIN, 40));
		decimal.setPreferredSize(dimen);
		decimal.setBackground(Color.lightGray);
		negate.setPreferredSize(dimen);
		negate.setBackground(Color.lightGray);
		negate.setFont(new Font("monospaced", Font.PLAIN, 20));
		space.setPreferredSize(dimen);
		space.setBackground(Color.CYAN);
		mode.setPreferredSize(dimen);
		mode.setBackground(Color.CYAN);
		
		clear.setPreferredSize(dimen);
		clear.setBackground(Color.CYAN);
		clear.setFont(new Font("monospaced", Font.PLAIN, 40));
		backspace.setPreferredSize(dimen);
		backspace.setBackground(Color.CYAN);
		backspace.setFont(new Font("monospaced", Font.PLAIN, 40));
		fileStore.setPreferredSize(dimen);
		fileStore.setBackground(Color.CYAN);
		fileStore.setFont(new Font("monospaced", Font.PLAIN, 40));
		memory.setPreferredSize(dimen);
		memory.setBackground(Color.CYAN);
		memory.setFont(new Font("monospaced", Font.PLAIN, 40));
		exit.setPreferredSize(dimen);
		exit.setBackground(Color.RED);
		exit.setFont(new Font("monospaced", Font.BOLD, 40));
		
		
		contentPanel = new JPanel();
		contentPanel.setBackground(Color.GREEN);
		contentPanel.setLayout(new FlowLayout());
		contentPanel = new JPanel();
		contentPanel.setBackground(Color.darkGray);
		contentPanel.setLayout(new FlowLayout());
		contentPanel.add(answerField2, BorderLayout.NORTH);
		contentPanel.add(answerField, BorderLayout.SOUTH);
		contentPanel.add(exit);	
		contentPanel.add(mode); 
		contentPanel.add(clear);
		contentPanel.add(backspace);
		contentPanel.add(multiply);  
		contentPanel.add(power);
		contentPanel.add(seven);
		contentPanel.add(eight); 
		contentPanel.add(nine);	
		contentPanel.add(divide);
		contentPanel.add(memory);
		contentPanel.add(four); 
		contentPanel.add(five);
		contentPanel.add(six); 
		contentPanel.add(subtract);
		contentPanel.add(fileStore); 
		contentPanel.add(one); 
		contentPanel.add(two);
		contentPanel.add(three);
		contentPanel.add(add);
		contentPanel.add(space);
		contentPanel.add(zero); 
		contentPanel.add(decimal);
		contentPanel.add(negate);
		contentPanel.add(equal); 
		

		//ActionerListener for digits
		Numbers n = new Numbers();
		//this displays the buttons
		one.addActionListener(n); two.addActionListener(n); three.addActionListener(n); four.addActionListener(n); 
		five.addActionListener(n); six.addActionListener(n); seven.addActionListener(n); eight.addActionListener(n);
		nine.addActionListener(n); zero.addActionListener(n); decimal.addActionListener(n); backspace.addActionListener(n);
		decimal.addActionListener(n); space.addActionListener(n); negate.addActionListener(n);
		
		//ActionLIstener for Operators
		Calc c = new Calc();
		add.addActionListener(c);
		multiply.addActionListener(c);
		divide.addActionListener(c);
		subtract.addActionListener(c);
		power.addActionListener(c);
		fileStore.addActionListener(c);
		memory.addActionListener(c);
		mode.addActionListener(c);
		equal.addActionListener(c);
		clear.addActionListener(c);
		exit.addActionListener(c);

		
		this.setContentPane(contentPanel);
		

	}
	//---------------------------------- EFFICIENCY = O(1) ------------------------------------------------|| Big O
    public final void setDesign() // function used to set how the interface of the Calculator will look and feel
    {
        try 
        {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
        } catch(Exception e) 
        {   
        }
    }
  //---------------------------------- EFFICIENCY = O(1) ------------------------------------------------|| Big O
	public boolean isOperator(String s)// boolean function used to check operators are entered
	{
		if(s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") || s.equals("^"))//if the string is an operator
			return true;
		else //the string is an operand
			return false;
	}
	//---------------------------------- EFFICIENCY = O(1) ------------------------------------------------|| Big O
	public int priority(String exp)// function used to check the priority of the operators
	{
		int precidence = 0;
		if(exp.equals("^")){
			precidence = 4;// highest precedence
		}
		else if(exp.equals("*") || exp.equals("/")){
			precidence = 3;
		}else if(exp.equals("+") || exp.equals("-")){
			precidence = 2;
		}else{
			precidence = 1;
		}
		return precidence;
	}
	//---------------------------------- EFFICIENCY = O(n^2) ----------------------------------------------|| Big O
	/*	Function used to convert infix expressions
	 * 	and convert them to Reverse Polish Notations
	 * */
	public String infixToPostFix(String express)
	{
		StringTokenizer token = new StringTokenizer(express, " +-*/^", true);
		String ch ="";
		String format = "";
		
		while(token.hasMoreTokens()) //while there are more tokens to be read
		{
			ch = token.nextToken();
			if(isOperator(ch) == false) //if the token is an operand (not an operator)
			{
				format += ch + " "; // add the string to the current string (format)
				//System.out.println("format is:" + format);
			}
			else //if the token is an operator
			{
				//operator.push(ch);
				while(operator.isEmpty() == false && priority(operator.peek()) >= priority(ch))// while the operator stack is not empty and priority is greater
				{
					format += operator.pop() + " "; //pop from stack and add to current string (format)
					//System.out.println("ch: " + ch);
				}
				operator.push(ch); 
				//System.out.println("New CH: " + operator.peek());
			}
		}
		
		while(!operator.isEmpty()) //while operator is not empty
		{
			ch = operator.pop();
			format += ch;
		}
		
		while(!operator.isEmpty())
		{
			operator.pop();
		}
		
		while(!stack.isEmpty()) 
		{
			stack.pop();
		}
		//System.out.println("New Format: " + format);
		return format;
	}
	//---------------------------------- EFFICIENCY = O(n) ------------------------------------------------|| Big O
	
	public double tokenAlgorithm(String express)
	{
		StringTokenizer tokenizer = new StringTokenizer(express, " +-/*^", true);
		
		double op1, op2, ce;
		String c;
		
		while(tokenizer.hasMoreTokens())
		{
			c = tokenizer.nextToken();
			//if token is an operand
			if(c.startsWith("0")|| c.startsWith("1")||c.startsWith("2")||c.startsWith("3")||c.startsWith("4")||
		            c.startsWith("5")||c.startsWith("6")||c.startsWith("7")||c.startsWith("8")||c.startsWith("9"))
		    {
				ce = Double.parseDouble(c); // converts a type string to double
				stack.push(ce); //push ce to stack
		    }
			else if(c.equals("+"))// if c is addition
		    {
				try
				{
		            op1 = stack.pop();  // pop from stack and assign to op1
		            op2 = stack.pop();  // pop from stack and assign to op2
				
	            stack.push(op2 + op1);  // add values and push to stack
				}
				catch(NullPointerException e)
				{
					e.getMessage();
				}
				operator.push(c); //push c to operator stack
		    }
			else if(c.equals("-"))  
			{
				try
				{
					op1 = stack.pop(); // pop from stack and assign to op1
					op2 = stack.pop(); // pop from stack and assign to op2
					stack.push(op2 - op1); // subtracts first value from second value and push result to stack
				}
				catch(NullPointerException e)
				{
					e.getMessage();
				}
				operator.push(c);
			}
			else if(c.equals("*"))
			{
				try
				{
					op1 = stack.pop();
					op2 = stack.pop();
					stack.push(op1 * op2);
				}
				catch(NullPointerException e)
				{
					e.getMessage();
				}
				operator.push(c);
			}
			else if(c.equals("/"))
			{
				try
				{
					op1 = stack.pop(); // pop from stack and assign to op1
					op2 = stack.pop(); // pop from stack and assign to op2
					stack.push(op2 / op1); //divides op2 by op1 (op2 was entered first)
				}
				catch(NullPointerException e)
				{
					e.getMessage();
				}
				operator.push(c);
			}
			else if(c.equals("^"))
			{
				try
				{
					op1 = stack.pop();
					op2 = stack.pop();
					stack.push(Math.pow(op2, op1));
				}
				catch(NullPointerException e)
				{
					e.getMessage();
				}
				operator.push(c);
			}
			
		}//End while loop
		
		try
		{
			answer = stack.peek(); //returns the top value of the stack and stores it in answer
		}
		catch(NullPointerException e)
		{
			e.getMessage();
		}
		
		while(!operator.isEmpty())
		{
			operator.pop();
		}
		
		while(!stack.isEmpty())
		{
			stack.pop();
		}
		
		return answer;
	}
	//---------------------------------- EFFICIENCY = O(n) ------------------------------------------------|| Big O
	public String getTopOfStack(String exp)
	{
		StringTokenizer tokenizer = new StringTokenizer(exp, " +-/*^", true);
		
		double ce;
		String c, ans = null;
		boolean option = false;
		
		while(tokenizer.hasMoreTokens())
		{
			c = tokenizer.nextToken();
			
			if(c.endsWith("0")|| c.endsWith("1")||c.endsWith("2")||c.endsWith("3")||c.endsWith("4")||
		            c.endsWith("5")||c.endsWith("6")||c.endsWith("7")||c.endsWith("8")||c.endsWith("9"))
		    {
				ce = Double.parseDouble(c); // converts string to double
				stack.push(ce);
				option = false;
				
			}
			else if(c.endsWith("+") || c.endsWith("-") || c.endsWith("*") || c.endsWith("/") || c.endsWith("^") || c.endsWith("."))
			{
				ans = c;
				operator.push(ans);
				option = true;
			}
		}
		
		if(option == false){
			try
			{
				answer = stack.peek();
			}
			catch(NullPointerException e)
			{
				e.getMessage();
			}
			ans = Double.toString(answer);
			//System.out.println(ans);
		}
		else
		{
			ans = operator.peek();
		}
		return ans;
	}

	
	public class Numbers implements ActionListener
	{
		//---------------------------------- EFFICIENCY = O(1) ------------------------------------------------|| Big O
		public void actionPerformed(ActionEvent ae)
		{		
			//Button clicking done in here
			JButton src = (JButton) ae.getSource();
			
			if(src.equals(one))
			{
				if(opChosen == false)
				{
					if(str1 == null)
					{
						str1 = "1";
					}else{
						str1 += "1";
					}
				}
			}
			else 
				if(src.equals(two))
				{
				 if(opChosen == false)
				 {
					if(str1 == null)
					{
						str1 = "2";
					}else{
						str1 += "2";
					}
				}
			}
			else
				if(src.equals(three))
				{
					if(opChosen == false)
					{
						if(str1 == null)
						{
							str1 = "3";
						}else{
							str1 += "3";
						}
					}
			}else
				if(src.equals(four))
				{
					if(opChosen == false)
					{
						if(str1 == null)
						{
							str1 = "4";
							}else{
								str1 += "4";
						}
					}
			}else
				if(src.equals(five))
				{
					if(opChosen == false)
					{
						if(str1 == null)
						{
							str1 = "5";
								}else{
								str1 += "5";
						}
					}
			}else
				if(src.equals(six)){
					if(opChosen == false)
					{
						if(str1 == null)
						{
							str1 = "6";
								}else{
								str1 += "6";
						}
					}
			}else
				if(src.equals(seven))
					{
						if(opChosen == false)
						{
							if(str1 == null)
							{
								str1 = "7";
							}else{
								str1 += "7";
								}
						}
			}else
				if(src.equals(eight))
					{
						if(opChosen == false)
						{
							if(str1 == null)
							{
								str1 = "8";
							}else{
								str1 += "8";
						}
					}
			}else
				if(src.equals(nine))
				{
					if(opChosen == false)
					{
						if(str1 == null)
						{
							str1 = "9";
						}else{
							str1 += "9";
					}
				}
			}else
				if(src.equals(zero))
					{
						if(opChosen == false)
						{
							if(str1 == null)
								{
									str1 = "0";
								}else{
									str1 += "0";
						}
					}
				}else
					if(src.equals(backspace))
					{
						if(opChosen == false)
						{
							if(str1 == null)
							{
								//System.out.println("Can't delete nothing");
							}else{
									try
										{
										str1 = str1.substring(0, str1.length() - 1);
										}
									catch(StringIndexOutOfBoundsException e)
										{
										e.getMessage();
										}
								}	
							}
					}else
						if(src.equals(negate))
						{
							if(opChosen == false)
							{
								if(str1 == null)
								{
									answerField.setText(str1.substring(1));
								}
								else
								{
										try
											{
											//System.out.println("str2=" +str2);
											answerField.setText("-"+answerField);
											
											}
										catch(StringIndexOutOfBoundsException e)
											{
											e.getMessage();
											}
								}	
							}
							else if(opChosen == true)
							{
								answer =  Double.parseDouble(answerField.getText());
								if(answer!=0)
								{
									str2 = Double.toString(answer*-1); 
									//System.out.println(" str1= " +str2);
									answerField.setText(str2);
								}
							}
						}
						/*else
							
							if(src.equals(decimal))
							{
								if(opChosen == false){
									if(str1 == null){
										str1 = "0.";
									}else if(str1 != null){
										if(str1.contains(".")){
											//System.out.println("Point already exist");
											answerField.setText("Error: a point already Exist");
										}else{
											str1 += ".";
										}
									}
								}
							}
			*/
			//=================================================================
			if(src.equals(space)){
				if(opChosen == false){
					if(str1 == null){
						str1 = null;
					}else if(str1 != null){
						str1 += " ";
					}
				}
			}else		
				if(opChosen == false){
					answerField.setText(str1);
				}else
					if(equalClicked == false){
						if(opChosen == false){
							answerField.setText(str1);
						}
					}
			
		}//this ends the method
		
	}//this ends this class

	//---------------------------------- EFFICIENCY = O(1) ------------------------------------------------|| Big O
	public class Calc implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{	
			JButton src = (JButton)ae.getSource();
			//----------------------------------------| ADDITION |------------------| + |----------------||
			if(src.equals(add)){
				if(str1 == null){
					//System.out.println("Enter Numbers first");
				}else if(str1 != null){
						str1 += "+";
				}
			}
			//----------------------------------------| SUBTRACTION |---------------| - |----------------||
			if(src.equals(subtract)){
				if(str1 == null){
					//System.out.println("Enter Numbers first");
				}else if(str1 != null){
						str1 += "-";
				}
			}			
			//----------------------------------------| MULTIPLICATION |------------| * |----------------||
			if(src.equals(multiply)){
				if(str1 == null){
					//System.out.println("Enter Numbers first");
				}else if(str1 != null){
					str1 += "*";
				}
			}
			//----------------------------------------| DIVISION |------------------| / |----------------||
			if(src.equals(divide)){
				if(str1 == null){
					//System.out.println("Enter Numbers first");
				}else if(str1 != null){
					str1 += "/";
				}
			}			
			//----------------------------------------| POWER |---------------------| ^ |----------------||
			if(src.equals(power)){
				if(str1 == null){
					//System.out.println("Enter Numbers first");
				}else{
					str1 += "^";
				}
			}
			
			//----------------------------------------| FILE STORAGE |--------------| f |----------------||
			if(src.equals(fileStore)){
				if(str1 == null){
					//System.out.println("Nothing can be stored");
				}else{
					String st = answerField.getText();
					file.writeRecordToFile(st);
				}
			}
			
			//----------------------------------------| MEMORY |--------------------| m |----------------||
			if(src.equals(memory)){
				if(str1 == null){
					//System.out.println("nothing can be retireved from memory");
				}else{
					String p = getTopOfStack(str1);
					answerField.setText(getTopOfStack(p));
					opChosen = true;
				}
			}
			
			//----------------------------------------| MODE |-------------------| mode |----------------||
			/*if(src.equals(mode)){
				String check = answerField.getText(); 
				if(check.endsWith("+") || check.endsWith("-") || check.endsWith("/") || check.endsWith("*") || check.endsWith("^"))
				{
					//System.out.println("Nothing can be converted");
				}
				else
				{
					if(str1 == null)
					{
						System.out.println("Nothing can be converted");
					}
					else
					{
						
						str2 = answerField.getText();
						answerField.setText(infixToPostFix(str2));
						opChosen = true;
					}
					
				}
			*/
			if(src.equals(mode))
			{
				if(str1 == null)
				{
					
				}
				else
				{
					String cc =  answerField.getText();// assign text in the text area to a string variable
					//System.out.println("");
					if(cc.endsWith("+")||cc.endsWith("-")||cc.endsWith("*")||cc.endsWith("/")||cc.endsWith("^"))// if it is an operator
					{
						answer = tokenAlgorithm(cc);
						answerField.setText(Double.toString(answer));
						opChosen = true;
					}
					else
					{
						answerField.setText(infixToPostFix(cc));//convert answer from infix to postfix and dsiplay in text area
						opChosen = true;
						//System.out.println(answerField);
					}
				}
			}
			
			//----------------------------------------| EQUALS |--------------------| = |----------------||
			if(src.equals(equal)){
				if(str1 == null){
					//System.out.println("Enter Numbers first");
				}else if(str1 != null){
					str2 = answerField.getText();
					answer = tokenAlgorithm(str2);
					str1 = Double.toString(answer); 
					answerField.setText(str1);
				}	
			}
			
			//=============================================================
			if(opChosen == false){
				answerField.setText(str1);
			}
			
			//========================================================
			if(equalClicked == false){
				if(opChosen ==false){
					answerField.setText(str1);
				}
			}
			
			//===============================================================
			if(src.equals(exit))
			{
				System.exit(0);
			}
			
			//==================================================================
			if(src.equals(clear))
			{
				str1 = "";
				str1 = "";
				str2 = "";
	
				opChosen = false;
				answerField.setText("0");
			}
		}		
	}
	
	
}

