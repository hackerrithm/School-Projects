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

import java.io.FileWriter;
import java.io.IOException;

public class FileOperation {
	//private JTextField textField;
	public void writeRecordToFile(String input)
	{
		try
		{
			FileWriter file = new FileWriter("Calc.txt", true);
			file.write(input);
			file.write("\n");
			file.close();
		}
		catch(IOException e)
		{
			System.err.println(e.getMessage());
		}
	}
}
