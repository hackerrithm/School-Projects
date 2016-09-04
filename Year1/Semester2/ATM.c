//-----------| ID NUMBER: *******      |-------------//
//-----------| NAME: KEMAR A. GALLOWAY |-------------//
//-----------| MODULE: PROGRAMMING 2   |-------------//
//-----------| MODULE CODE: CMP1025    |-------------//

//--------------------------| HEADERS |------------------------KG------//

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<ctype.h>

//----------------------| DECLARATIONS |--------------------------KG------//
void startscreen();
		int mainmenu();
			void init_system();
				void create_seq();
				void create_bin();
				int timestamp();
				void error();
			void admin_log();
			void user_main();
				void umenu();
					void deposit(int);
					void withdraw(int);
					void school_fee(int);
					void check_bal(int);
					void display_log(int);
			void reset_pass();
			void goodbye();
//------------------------| STRUCTURES |---------------KG------//
		struct account
		{
			int account_num;
			char pin[5];
			float account_bal;
		};
		typedef struct account acc;

		
			struct transaction
			{
				int acnum[5];
				char type[30];
				int amount[20];
				int timestamp;
				int other_acc[30];

			}tr;

//-------------------------------| START |---------------------------KG------//	
		void startscreen()
		{
			 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			printf("\n\n\a\a");
			printf("  ___________________________________________________________________________\n");
			printf(" |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$     $$$   $$$$$ $$$ $$$$       $$$ $$$$ $$$      $$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$  $$$$$$$ $$$ $$ $$ $ $$ $$ $$$$$  $$ $$$$ $$ $$$$$$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("##");SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);printf("$$$$$$$$|\n");
			printf(" |$$$   $$$$$$$     $$ $$$ $$$ $$       $$$ $$$$ $$$      $$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("#########");SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);printf("$$$|\n");
			printf(" |$$$   $$$$$$$ $$$ $$ $$$$$$$ $$ $$$$$$$$$ $$$$ $$$$$$$$  $$$$$$");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("###########");SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);printf("$$|\n");
			printf(" |$$$$  $$$$$$$ $$$ $$ $$$$$$$ $$ $$$$$$$$$ $$$$ $$$$$$$$  $$$$$");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("#############");SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);printf("$|\n");
			printf(" |$$$$$      $$ $$$ $$ $$$$$$$ $$ $$$$$$$$$$    $$$$      $$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("@@@@@@@@@@");SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);printf("$$|\n");
			printf(" |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("@@|    |@@");SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);printf("$$|\n");Sleep(500);
			printf(" |$$$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("@@|    |@@");SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);printf("$$|\n");Sleep(100);
			printf(" |$$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("######");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$     $$$$      $$$ $$$$ $$ $$$ $$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("###");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("##");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$ $$$$ $$$ $$$$ $$$ $ $$ $$ $ $$$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("###");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$$     $$$$      $$$ $$ $ $$ $ $$$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("###");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$$ $$$$ $$$ $$$$ $$$ $$$  $$ $$ $$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#########");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$     $$$$ $$$$ $$$ $$$$ $$ $$$ $$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("##");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("##");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("##");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#########");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$$$$$$");SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("#");SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf(" |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");Sleep(100);
			printf("  ----------------------------------------------------------------------------\n");
			Sleep(1500);
		//system("pause");
			}

//---------------------| CREATE SEQUENTIAL AND BINARY FILES |-----------------KG------//

		void create_seq()
		{
			FILE *sq;
			sq=fopen("sequencial.txt","w");
			if(sq!=NULL)
			{
				fclose(sq);
			}
			else
			{
				printf("File could not be created\n");
			}

		}

		void create_bin()
		{
			FILE *bn;
			int count;
			acc a={1000,"0000",1000.00};
			bn=fopen("binary.dat","wb");

			if(bn!=NULL)
			{
				for(count=1000;count<=2000;count++)
				{
					a.account_num=count;
					fwrite(&a,sizeof(a),1,bn);
						}	
				system("cls");
				printf("\n\n\t\t\tS");Sleep(100);
				printf("Y");Sleep(100);
				printf("S");Sleep(100);
				printf("T");Sleep(100);
				printf("E");Sleep(100);
				printf("M");Sleep(100);
				printf(" ");Sleep(100);
				printf("I");Sleep(100);
				printf("N");Sleep(100);
				printf("I");Sleep(100);
				printf("T");Sleep(100);
				printf("I");Sleep(100);
				printf("A");Sleep(100);
				printf("L");Sleep(100);
				printf("I");Sleep(100);
				printf("Z");Sleep(100);
				printf("E");Sleep(100);
				printf("D\n\n");Sleep(100);

				fclose(bn);
				system("pause");
			}else
				printf("File could not be created\n");
			timestamp();
		}

//------------------------------| MAIN MENU |-------------------------------------KG------//

		int mainmenu()
		{
			HANDLE  h= GetStdHandle(STD_OUTPUT_HANDLE);
			int choice;
			system("cls");
			printf("\n\n\n\t\t\t\tMAIN MENU\n\n");
			printf("\t\tWelcome!Please select your option!\n\n");
			printf("\t\tINITIALIZE SYSTEM..................1\n\n");
			printf("\t\tDISPLAY ATM TRANSACTION LOG........2\n\n");
			printf("\t\tUSER TRANSACTION MENU..............3\n\n");
			printf("\t\tEXIT...............................4\n\n\t\t");
			scanf("%d",&choice);
			return choice;
		}

//----------------------------------------| MAIN |---------------------------------KG------//

		void main()
		{
			 HANDLE  h= GetStdHandle(STD_OUTPUT_HANDLE);
			int choice;
			system("Color 0A");
			startscreen();
			system("Color 9F");
			choice=mainmenu();
			while(choice!=4)
			{
				if(choice==1)
					init_system();
				else if(choice==2)
				{
					admin_log();
				}else if(choice==3){
					user_main();
				}else
					error();
				choice=mainmenu();
			}
			goodbye();
		}

//---------------| 1 |----------------| INITIALIZE SYSTEM |----------------------------------KG------//
		
		void init_system()
		{
			char pin[]="1234";
			char hold[30];
			char ch;
			int counter=0;
			system("cls");
			system("Color 80");
			printf("\n\n\t\t\tINITIALIZE SYSTEM\n\n");
			printf("\a\tPASSWORD:");
			while(1)
			{
				ch=getch();                                                           
				if(ch==13)                                                           
					break;
				
				printf("[$]");                                                         
				hold[counter++]=ch; 	
			}
			hold[counter]='\0';                                                               
			if(strcmp(hold,pin)==0)  
			{
				create_seq();
				create_bin();
			}
			else{
				system("cls");
				printf("\a\n\t\tINCORRECT PASSWORD!\n\t\tYou will be directed back to the main menu\n");
				system("pause");
			}
			system("cls");
			system("Color 9F");
		}


//-------------------------------------| TIMESTAMP |------------------------------------KG------//

		int timestamp()
		{
			time_t ltime;
			struct tm *Tm;

			ltime=time(NULL);
			Tm=localtime(&ltime);
			return ltime;

		}

		const char * realtime(int timestamp)
		{
			time_t raw_time = timestamp;
			return ctime(&raw_time);
		}

//--------------------------------------| ERROR MESSAGE |----------------------------------------KG------//

		void error()
		{
			system("cls");
			system("Color 0C");
			printf("\a\a\n\n\n________________________________ERROR________________________________________\n");
			printf("_____________________________________________________________________________\n");
			printf("########################\n");
			printf("##########  ############\n");
			printf("######## ---- ##########     INVALID CHOICE\n");
			printf("####### |       ########\n");
			printf("#####   |____     ######    NOTE: > you may have chosen a number or character\n");
			printf("###     |           ####            that does not corresponds with any of \n");
			printf("#        -----        ##            the choices on the main menu\n");
			printf("########################\n");
			printf("_____________________________________________________________________________\n");
			printf("_____________________________________________________________________________\n");
			system("pause");
			system("Color 9F");
		}

//---------------------------------------| GOOD BYE MESSAGE |----------------------------------KG------//

		void goodbye()
		{
			system("cls");
			printf("\n\n\a");
			printf("  ___________________________________________________________________________\n");
			printf(" |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$              $$$  $$$$$$   $$$             $$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$  $$$$$$$$$$  $$$$  $$$$$  $$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$  $$$$$$$$$$  $$$$$  $$$  $$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$             $$$$$$$     $$$$$$$            $$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$  $$$$$$$$$$   $$$$$$   $$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$  $$$$$$$$$$$$  $$$$$   $$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$  $$$$$$$$$$$$  $$$$$   $$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$               $$$$$$   $$$$$$$              $$$$$$$$$$$$$$$$$$|\n");
			printf(" |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n");
			printf("  ----------------------------------------------------------------------------\n");
			printf("\n\n\t\tTHANK YOU FOR USING CAMPUS BANKING\n");
			Sleep(1000);
			exit(0);
		}

//--------------------------| 2 |---------| TRANSACTIONS LOG |-------------------------------KG------//

		void admin_log()
		{
			char pin[]="1234";
			char hold[30];
			char ch;
			int counter=0;
			system("cls");
			system("Color 80");
			printf("\n\n\t\t\tATM TRANSACTION LOG\n\n");
			printf("\a\t\t\tPlease enter the password\n\t\t\t:");
			while(1)
			{
				ch=getch();                                                           
				if(ch==13)                                                           
					break;
				printf("[$]");                                                         
				hold[counter++]=ch;                                                       
			}
			hold[counter]='\0';                                                               
			if(strcmp(hold,pin)==0)  
			{
				display_log(-1);
			}
			else{
				system("cls");
				printf("\a\n\t\tINCORRECT PASSWORD!\n\t\tYou will be directed back to the main menu\n");
				system("pause");
			}
			system("Color 9F");  
		}

//-----------------------| 3 |---------| USER TRANSACTION MENU |---------------------------------KG------//

		void user_main()
		{
			int choice;
			int p;
			int acnum;
			char hold[30];
			char ch;
			int counter=0;
			int i=0;
			int e_check;
			FILE *sequ;
			FILE *bina;

			acc d={1000,"0000",1000};

			sequ=fopen("sequencial.txt","a");
			bina=fopen("binary.dat","rb+");

			system("cls");
			printf("\n_________________ACCOUNT VARIFICATION_________________\n\n");
			printf(">  ACCOUNT NUMBER MUST BE BETWEEN 1000 TO 2000 TO CONTINUE: ");
			printf("\n\n\n\n\n>  ENTER ACCOUNT NUMBER: ");
			scanf("%d", &acnum);
			while(acnum<1000||acnum>2000)
			{
			system("cls");
			printf("_________________ACCOUNT VARIFICATION_________________");
			printf("\n\n\n\n\n>  ACCOUNT NUMBER MUST BE BETWEEN 1000 TO 2000 TO CONTINUE: ");
			
			printf("\n\n\n\n\n>  ENTER ACCOUNT NUMBER: ");
			scanf("%d", &acnum);
			}

			if((sequ!=NULL)&&(bina!=NULL))
			{

				e_check=fseek(bina,sizeof(d) * (acnum -1000), SEEK_SET); 
				if(e_check!=0)
					
				{
					printf("ERROR FINDING FILE");
					system("pause");
					user_main();
				}

				e_check=fread(&d, sizeof(d), 1, bina);
				
			}
			printf("\n\nFOR FIRST TIME CUSTOMERS YOUR DEFAULT PIN IS 0000\n\n Otherwise please input your set pin\n");			
			printf("\n>  ENTER YOUR PIN: ");
			while(1)
			{
				ch=getch();                                                           
				if(ch==13)                                                           
					break;
				printf("*");                                                         
				hold[counter++]=ch;                                                       
			}
			hold[counter]='\0'; 

			if(strcmp(d.pin,hold)!=0)
			{
				system("cls");
				printf("\a\n\t\tINCORRECT PIN!\n\t\tENTER CORRECT PIN\n");
				system("pause");
				//fflush(stdin);
				user_main();
				fflush(stdin);
			}

			umenu();
			scanf("%d",&choice);
			fflush(stdin);
		while(choice!=7) 
			{
				switch(choice)
				{

				case 1:
					deposit(acnum);
					break;

				case 2:
					withdraw(acnum);
					break;

				case 3:
					school_fee(acnum);
					break;

				case 4:
					check_bal(acnum);
					break;

				case 5:
					display_log(acnum);
					break;

				case 6:
					reset_pass(acnum);
					break;
				
				default:
					error();
					system("pause");
					system("cls");
					break;
				}
				umenu();
				scanf("%d",&choice);
		}
				 fclose(sequ);
				 fclose(bina);
}
//-----------------------| 3 |---------| USER TRANSACTION MENU |--------------------------------------------KG------//

		void umenu()
		{
			system("cls");
			printf("\t\t\t\tUser Transaction menu\n\n");
			printf("\t\tWelcome!Please select your option!\n\n");
			printf("\tDeposit funds......................................1\n\n");
			printf("\tWithdraw funds.....................................2\n\n");
			printf("\tPay school fee.....................................3\n\n");
			printf("\tCheck account balance..............................4\n\n");
			printf("\tDisplay account transaction log....................5\n\n");
			printf("\tReset password.....................................6\n\n");
			printf("\tExit...............................................7\n\n");
		}

//--------------| 3.1 |---------------| DEPOSIT |---------------------------------------KG------//

		void deposit(int acnum)
		{
			FILE *sequ;
			FILE *bina;
			int e_check;
			int deposit;

			acc d={1000,"0000",1000};
			sequ=fopen("sequencial.txt","a");
			bina=fopen("binary.dat","rb+");

			if((sequ!=NULL)&&(bina!=NULL))
			{

				e_check=fseek(bina,sizeof(d) * (acnum -1000), SEEK_SET); 
				if(e_check!=0)
					printf("ERROR READING FILE");
				e_check=fread(&d, sizeof(d), 1, bina);
				system("cls");

				printf("\nENTER THE AMOUNT BEING DEPOSITED\n");
				printf("\nmust be a multiple of 100\n");
				scanf("%d",&deposit);
				while(deposit%100!=0 || deposit < 100)
				{
					printf("\nThe desired amount not a multiple of 100\n");
					printf("\nPlease re-enter\n");
					scanf("%d",&deposit);
				}
				d.account_bal+=deposit;
				d.account_bal-=30;

				fprintf(sequ,"%d,dep,%d,%d,0\n",acnum,deposit,timestamp());
				system("cls");
				printf("\n\n\n\n\t\t\tBALANCE= $%.2f\n",d.account_bal);
				system("pause");

				fseek(bina,sizeof(d)*(acnum-1000),SEEK_SET);
				fwrite(&d,sizeof(d),1,bina);

				fclose(sequ);
				fclose(bina);
			}else
			{
				printf("FILES COULD NOT BE FOUND\n");
			}

		}

//----------| 3.2 |-----------------| WITHDRAW |----------------------------------KG------//

		void withdraw(int acnum)
		{
			FILE *sequ;
			FILE *bina;
			int e_check;
			int withdraw;

			acc d={1000,"0000",1000};

			sequ=fopen("sequencial.txt","a");
			bina=fopen("binary.dat","rb+");

			if((sequ!=NULL)&&(bina!=NULL))
			{
				e_check=fseek(bina,sizeof(d) * (acnum -1000), SEEK_SET); 
				if(e_check!=0)
					printf("ERROR READING FILE");

				e_check=fread(&d, sizeof(d), 1, bina);
				system("cls");

				printf("\nENTER WITHDRAWAL AMOUNT\n");
				printf("\nmust be a multiple of 100\n");
				scanf("%d",&withdraw);
				while(withdraw%100!=0 || withdraw < 100 || withdraw>d.account_bal||d.account_bal-withdraw<1000)
				{
					printf("\nCan't withdraw the amount specified\n");
					printf("\nPlease re-enter\n");
					scanf("%d",&withdraw);
				}

				d.account_bal-=withdraw;
				d.account_bal-=30;

				fprintf(sequ,"%d,wit,%d,%d,0\n",acnum,withdraw,timestamp());
				system("cls");

				printf("\n\n\n\t\t\tBALANCE= $%.2f\n",d.account_bal);
				system("pause");

				fseek(bina,sizeof(d)*(acnum-1000),SEEK_SET);
				fwrite(&d,sizeof(d),1,bina);

				fclose(sequ);
				fclose(bina);
			}else{
				printf("files could not be found\n");
			}

		}

//----------| 3.3 |-------------------| SCHOOL FEE |--------------------------------------KG------//


		void school_fee(int acnum)
		{
			int payment;
			int sch_acnum;
			int student_id;
			int e_check;

			FILE *sequ;
			FILE *bina;

			acc d={1000,"0000",1000};

			sequ=fopen("sequencial.txt","a");
			bina=fopen("binary.dat","rb+");

			if((sequ!=NULL)&&(bina!=NULL))
			{

				e_check=fseek(bina,sizeof(d) * (acnum -1000), SEEK_SET); 
				if(e_check!=0)
					printf("error reading file");

				e_check=fread(&d, sizeof(d), 1, bina);
				
				system("cls");

				printf("\nSCHOOL'S ACCOUNT NUMBER: ");
				scanf("%d",&sch_acnum);
				printf("\nSTUDENT'S ID: ");
				scanf("%d",&student_id);
				printf("\nAMOUNT BEING PAID: ");
				scanf("%d",&payment);
				while(payment%100!=0 || payment < 100)
				{
					printf("\nThe desired amount not a multiple of 100\n");
					printf("\nPlease re-enter\n");
					scanf("%d",&payment);
				}

					while(d.account_bal-payment<1000)
				{
					printf("\nCan't withdraw the amount specified\n");
					printf("\nPlease re-enter\n");
					scanf("%d",&payment);

				}
				d.account_bal-=payment;
				d.account_bal-=30;


				fprintf(sequ,"%d,pay,%d,%d,0\n",acnum,payment,timestamp());
				system("cls");
				printf("\nSCHOOL'S ACCOUNT NUMBER: %d",sch_acnum);
				
				printf("\nSTUDENT'S ID: %d",student_id);
				
				printf("\nAMOUNT BEING PAID: $%d",payment);
				printf("\n\n\n\t\t\tREMAINING BALANCE= $%.2f\n",d.account_bal);
				system("pause");

				fseek(bina,sizeof(d)*(acnum-1000),SEEK_SET);
				fwrite(&d,sizeof(d),1,bina);

				fclose(sequ);
				fclose(bina);
			}else{
				printf("files could not be found\n");
			}
		}

//----------| 3.4 |------------------| CHECK BALANCE |------------------------------------KG------//

		void check_bal(int acnum)
		{
			FILE *bina;
			int e_check;

			acc d={1000,"0000",1000};

			bina=fopen("binary.dat","rb+");

			if(bina!=NULL)
			{

				e_check=fseek(bina,sizeof(d) * (acnum -1000), SEEK_SET); 
				if(e_check!=0)
					printf("error reading file");

				e_check=fread(&d, sizeof(d), 1, bina);
				fclose(bina);

				system("cls");
				printf("\n\n\n\t\t\tEXISTING BALANCE= $%.2f\n",d.account_bal);
				system("pause");

			}else{
				printf("files could not be found\n");
			}
		}

//------------| 3.4 |----------------| TRANSACTION LOG |--------------------------------------KG------//


		void display_log(int acnum)
		{

			FILE *sequ;
			int e_check;
			int count=0;
			sequ=fopen("sequencial.txt","r");

			if(sequ!=NULL)
			{
				system("cls");
				printf("\n\t\t   TRANSACTION LOG\n\n\n");

				while(1){

					fscanf(sequ,"%d,%c%c%c,%d,%d,%d\n",&tr.acnum[count], &tr.type[0], &tr.type[1], &tr.type[2], &tr.amount[count],&tr.timestamp,&tr.other_acc[count]);
					tr.type[3] = '\0';
					
					if(tr.acnum[count]==acnum || acnum==-1)
					{
						switch(tr.type[0])
						{
						case 'd': printf(" > %s\t- Account number: %d deposited $%.2f\n\n", realtime(tr.timestamp), tr.acnum[count], (float)tr.amount[count]);
										break;
						case 'w': printf(" > %s\t- Account number: %d withdrew $%.2f\n\n", realtime(tr.timestamp), tr.acnum[count], (float)tr.amount[count]);
										break;
						case 'p': printf(" > %s\t- Account number: %d paid $%.2f\n\n", realtime(tr.timestamp), tr.acnum[count], (float)tr.amount[count]);
										break;
						}

					}if(feof(sequ))
						break;
					++count;
				}
				system("pause");
				fclose(sequ);
			}else{
				printf("files could not be found\n");
			}

		}
//--------------| 3.6 |---------------| PASSWORD RESET |----------------------------------KG------//


		void reset_pass(int acnum)
		{
			FILE *bina;
			char newpass0[30], newpass1[30];
			int counter=0;
			char ch;			

			acc d={1000,"0000",1000};

			bina=fopen("binary.dat","rb+");

			system("cls");

			printf(" > ENTER NEW PIN:");
			while(1)
			{
				ch=getch();                                                           
				if(ch==13)                                                           
					break;
				printf("*");                                                         
				newpass0[counter++]=ch;                                                       
			}
			newpass0[counter]='\0'; 

			counter=0;
			printf("\n\nFOR CONFIRMATION\n\n > ENTER PIN AGAIN:");
			while(1)
			{
				ch=getch();                                                           
				if(ch==13)                                                           
					break;
				printf("*");                                                         
				newpass1[counter++]=ch;                                                       
			}
			newpass1[counter]='\0'; 

			if(strcmp(newpass0,newpass1)==0)  
			{
				strcpy(d.pin,newpass1);
				
				fseek(bina,sizeof(d)*(acnum-1000),SEEK_SET);
				fwrite(&d,sizeof(d),1,bina);
				system("cls");
				printf("\n\n\t\t\tP");Sleep(50);
				printf("I");Sleep(50);
				printf("N");Sleep(50);
				printf(" ");Sleep(50);
				printf("S");Sleep(50);
				printf("U");Sleep(50);
				printf("C");Sleep(50);
				printf("C");Sleep(50);
				printf("E");Sleep(50);
				printf("S");Sleep(50);
				printf("S");Sleep(50);
				printf("F");Sleep(50);
				printf("U");Sleep(50);
				printf("L");Sleep(50);
				printf("L");Sleep(50);
				printf("Y");Sleep(50);
				printf(" ");Sleep(50);
				printf("C");Sleep(50);
				printf("H");Sleep(50);
				printf("A");Sleep(50);
				printf("N");Sleep(50);
				printf("G");Sleep(50);
				printf("E");Sleep(50);
				printf("D\n\n");Sleep(50);
								
				system("pause");
			}
			else{
				printf("\a\n\t\tPASSWORDS DON'T MATCH!\n\t\tPlease re-enter password\n");
				system("pause");
				system("cls");
				reset_pass(acnum);
			}
			fclose(bina);
}
