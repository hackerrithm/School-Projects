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

import javax.swing.SwingUtilities;

public class Driver {

	public static void main(String[] args) {
		
		SwingUtilities.invokeLater(new Runnable(){

			@Override
			public void run() {
				 new CalculatorUserInterface();
				
				
			}
			
		});


	}

}
