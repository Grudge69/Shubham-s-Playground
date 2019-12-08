/* COMPUTER SCIENCE PROJECT
   CLASS XII
   NAME : SHUBHAM RAWAT
   SCHOOL : BAL BHARATI PUBLIC SCHOOL, NOIDA
   SESSION : 2016-2017
   */
#include<iostream.h> //Included for input/output related functions
#include<conio.h> //Included for console input/output related functions
#include<stdio.h> //Included for standard input/output functions
#include<fstream.h> //Included for file manipulations
#include<process.h> //Included for exit() function
#include<string.h> //Included for string manipulating functions

//FUNCTION TO PERFORM LOGIN OPERATION
int login() //Definition of function to login
{
 //Declarations of necessary variables
 int flag=0;
 char username[50],password[50],un[50],pw[50];
 //Message on screen
 c:cout<<"Logging in..... Enter your details"<<endl;
 cout<<"ENTER USERNAME ";
 gets(username);//Accepting username from the user via keyboard
 for(int i=0;username[i]!='\0';i++)
  { if(username[i]==' ') //Comparing username for spaces
      { cout<<"Username cannot contain spaces"<<endl; //Error Message
	cout<<"Enter Details Again"<<endl;
	system("pause"); // Holding screen
	clrscr(); //Clearing the screen
	cout<<"***************** WELCOME *******************"<<endl;
	goto c; //Sending back to login again
       }
   }
 cout<<"ENTER PASSWORD ";
 gets(password); //Accepting password fron the user via keyboard
 for(i=0;password[i]!='\0';i++)
  { if(password[i]==' ') //Comparing password for spaces
      { cout<<"Password cannot contain spaces"<<endl; //Error Message
	cout<<"Enter Details Again"<<endl;
	system("pause"); //Holding screen
	clrscr(); //Clearing the screen
	cout<<"***************** WELCOME *******************"<<endl;
	goto c; //Sending back to login again
       }
   }
 fstream l; //Declaring file manipulation related object
 //Opening files in input mode
 l.open(username,ios::in);
 if(!l) //Checking for existence of the file
  {cout<<"Username or password error!!!!!!!!!TERMINATING!!!!"<<endl; //Error message
   cout<<endl<<endl<<endl<<endl<<endl;
   cout<<"       ##########  ##    ##  #######         #######  ##      ##  ########    "<<endl;
   cout<<"	   ##      ##    ##  ##              ##       ###     ##  ##      #   "<<endl;
   cout<<"	   ##      ##    ##  ##              ##       ## #    ##  ##      ##  "<<endl;
   cout<<"	   ##      ########  #######         #######  ##  #   ##  ##      ##  "<<endl;
   cout<<"	   ##      ########  #######         #######  ##   #  ##  ##      ##  "<<endl;
   cout<<"	   ##      ##    ##  ##              ##       ##    # ##  ##      ##  "<<endl;
   cout<<"	   ##      ##    ##  ##              ##       ##     ###  ##      #   "<<endl;
   cout<<"	   ##      ##    ##  #######         #######  ##      ##  ########    "<<endl;
   cout<<endl<<endl<<endl<<endl<<endl;
   system("pause"); //Holding Screen
   exit(0); //Terminating the program
   }
  else //Proceeding if file exist
   {
      strcpy(un,username); //Retrieving username
      l.getline(pw,50,'\0'); //Retrieving password
      //Comparing username and password
      if(strcmp(un,username)==0 && strcmp(pw,password)==0)
       flag=1; //Counter initialised with 1 as username and password matched
      else
       flag=0; //Flag initialised with 0 as username or password didn't matched
      //Closing the file
      l.close();

    }
 if(flag==1)
  return 1; //Returning 1 for successful login
 else
  return 0; //Returning 0 for unsuccessful login
}
void main() //Starting of main function
{
 clrscr(); //Clearing the screen
 //Declaration of necessary variables
 char choice;
 char c;
 int i,k;
 do
 {
  cout<<"***************** WELCOME *******************"<<endl; //Welcome message
  cout<<"1.Register"<<endl;
  cout<<"2.Login"<<endl;
  cout<<"Enter choice ";
  cin>>c; //Accepting choice from user via keyboard
  switch(c)
   { case '1': //Starting registration process if user enters 1
	       char us[50],pa[50]; //Strings containing username and password
	       s:cout<<"Registering..... Enter your details"<<endl;
	       cout<<"Enter username ";
	       gets(us); //Retrieving username via keyboard
	       for(i=0;us[i]!='\0';i++)
		{ if(us[i]==' ') //Checking username for spaces
		  { cout<<"Spaces cannot contain spaces"<<endl;//Error Message
		    cout<<"Enter Details Again"<<endl;
		    clrscr(); //Clearing the screen
		    cout<<"***************** WELCOME *******************"<<endl;		goto s;
		   }
		 }
	       cout<<"Enter password ";
	       gets(pa); //Retrieving password via keyboard
	       for(i=0;pa[i]!='\0';i++)
		{ if(pa[i]==' ') //Checking password for spaces
		  { cout<<"Password cannot contain spaces"<<endl; //Error message
		    cout<<"Enter Details Again"<<endl;
		    clrscr(); //Clearing the screen
		    cout<<"***************** WELCOME *******************"<<endl;
		    goto s; //Going back to enter username and password
		  }
		 }
	       fstream R; //Declaration of file manipulation objects
	       //Opening files in input mode
	       R.open(us,ios::in);
	       if(!R) //Checking for existence of files
		{ //Creating the file if it doesn't exist
		  R.open(us,ios::out);
		  //Storing username and password in the files
		  R<<pa;
		  //Closing the file
		  R.close();
		  system("pause"); //Holding screen
		  clrscr(); //Clearing the screen
		  }
	       else
		{ //Error message if the file already exist
		  cout<<"USERNAME ALREADY EXISTS"<<endl;
		  //Closing the files
		  R.close();
		  system("pause"); //Holding screen
		  clrscr(); //Clearing the screen
		  cout<<"***************** WELCOME *******************"<<endl;
		  goto s; //Going back to enter username and password
		 }
	       clrscr(); //Clearing the screen
	       break; //Breaking out of switch
    case '2':  if(login()==1) //Checking for successful login
		{ cout<<"Successfully logged in"<<endl;
		  system("pause"); //Holding screen
		  clrscr();
		 }
	       else //Unsuccessful login
		{ cout<<"Cannot login successfully"<<endl; //Error message
		  system("pause"); //Holding screen
		 }
	       clrscr(); //Clearing the screen
	       break; //Breaking out of switch
    default :  cout<<"Wrong choice entered!!!!!!"<<endl; //Error message
	       system("pause"); //Holding the screen
	       clrscr(); //Clearing the screen
	       break; //Breaking out of switch
   }
   cout<<"Want to enter more for sign in or register??? (Y/N) "; //Asking to enter more
   cout<<"Enter 0 to signout "<<endl;
   cin>>choice; //Accepting choice via keyboard
   clrscr(); //Clearing the screen
   if(choice=='0')
    { clrscr();
      cout<<"  ######  ##   ######  #       #  ##  #       #   #####"<<endl;
      cout<<" #	  ##  #        ##      #  ##  ##      #  #     "<<endl;
      cout<<"#         ## #         # #     #  ##  # #     # #      "<<endl;
      cout<<" #	  ## #         #  #    #  ##  #  #    # #      "<<endl;
      cout<<"  #####   ## #   ####  #   #   #  ##  #   #   # #  ####  "<<endl;
      cout<<"       #  ## #       # #    #  #  ##  #    #  # #      #   "<<endl;
      cout<<"	# ## #       # #     # #  ##  #     # # #      #   "<<endl;
      cout<<"       #  ##  #     ## #      ##  ##  #      ##  #    ##   "<<endl;
      cout<<" ######   ##   ##### # #       #  ##  #       #   #### #   "<<endl<<endl<<endl;
      cout<<"   ####   ##      ## ##########"<<endl;
      cout<<"  #    #  ##      ##     ##"<<endl;
      cout<<" #      # ##      ##     ##"<<endl;
      cout<<" #      # ##      ##     ##"<<endl;
      cout<<" #      # ##      ##     ##"<<endl;
      cout<<" #      # ##      ##     ##"<<endl;
      cout<<" #      # ##      ##     ##"<<endl;
      cout<<"  #    #   ##    ##      ##"<<endl;
      cout<<"   ####     ######       ##      * * * * * * * * * * * "<<endl;
      cout<<endl<<endl;
      system("pause");
      exit(0);
      }
  }while(choice=='y'||choice=='Y'); //Iterating again if choice is Y or y

 getch(); //Holding the screen and terminating on pressing any keyboard character
 } //End of main function
