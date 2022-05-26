#include<iostream>
#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
	long long phono;
	char address[20];
public:
	void create_account();	//function to get data from user
	void show_account();	//function to show data on screen
	void modify();   //function to get new data from user
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report();	//function to show data in tabular format
	int retacno();	//function to return account number
	int retdeposit();	//function to return balance amount
	char rettype();	//function to return type of account
};

void account::create_account()
{
    cout<<"\nEnter The account No. : ";
	cin>>acno;
    cout<<"\nEnter The Name of The account Holder : ";
    fflush(stdin);
	cin.getline(name,49);
	cout<<"\nEnter The Address : ";
	fflush(stdin);
	cin.getline(address,19);
	cout<<"\nEnter The Phone num:";
	cin>>phono;

	cout<<"\nEnter Type of The account (C/S/Fixed for 1 year(F)/Fixed for 2 years(T)/Fixed for 3 years(X)) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current and >=5000 for Fixed for 1,2,3 years) : ";
	cin>>deposit;
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Created..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
}

void account::show_account()
{
	cout<<"\nAccount No."<<"\t: "<<acno;
	cout<<"\nAccount Holder Name"<<": ";
	cout<<name;
	cout<<"\nAddress  "<<"\t: "<<address;
	cout<<"\nPhone number"<<"\t: "<<phono;
	cout<<"\nType of Account"<<"\t: "<<type;
	cout<<"\nBalance amount" <<"\t: "<<deposit;
}


void account::modify()
{
	cout<<"\nThe account No"<<"\t: "<<acno;
	cout<<"\n\nEnter The Name of The account Holder"<<"\t: ";
	fflush(stdin);
	gets(name);
	cout<<"\nEnter The Address"<<"\t: ";
	fflush(stdin);
	gets(address);
	cout<<"\nEnter The Phone number"<<"\t: "<<phono;
	cout<<"\nEnter Type of The account (C/S/Fixed for 1 year(F)/Fixed for 2 years(T)/Fixed for 3 years(X))" <<"\t: ";
	cin>>type;
}



void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report()
{
	cout<<acno<<"\t\t"<<name<<"\t\t"<<address<<"\t\t"<<phono;
	int i,l=strlen(name),l1=strlen(address);
	for(i=0;i<19-l;i++)
    {
        cout<<" ";
    }
    for(int i=0;i<10-l1;i++){
    	cout<<" ";
	}
	cout<<type;
	for(i=0;i<10;i++)
    {
        cout<<" ";
    }
    cout<<deposit<<endl;
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}



void writeaccount();	//function to write record in binary file
void displaysp(int);	//function to display account details given by user
void modifyaccount(int);	//function to modify record of file
void deleteaccount(int);	//function to delete record of file
void displayall();		//function to display all account details
void depositwithdraw(int, int); // function to desposit/withdraw amount for given account




int main()
{
	char ch;
	char pass[10],password[15]="Admin@bank";
	int num,i=0,main_exit;
	cout<<"\n\n\t\t\t\t Enter the password to login:";
	cin>>pass;
	
if (strcmp(pass,password)==0)
       {
	printf("\n\nPassword Match!\nLOADING");
       for(i=0;i<=6;i++)
       {
  		   usleep(100000);
           printf(".");
       }
        
		do
  		{   
		  system("cls");
	    cout<<"\n\n\t\t\t\t  ******Bank Management System******";
	    cout<<"\n\t\t\t\t======================================";
	     cout<<"\n\n\t\t\t****Developed by Capgemini Trainees of ERDSYS-1 Batch****";
	    cout<<"\n\t\t\t==========================================================";
		cout<<"\n\n\t\t\t\t\t**MAIN MENU**";
		cout<<"\n\n\t\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\n\t\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\n\t\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\n\t\t\t\t\t4. ACCOUNT DETAILS";
		cout<<"\n\n\t\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t\t\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\n\t\t\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\n\t\t\t\t\t8. EXIT";
		cout<<"\n\n\t\t\t\t==>>Enter Your Choice: ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			writeaccount();
			break;
		case '2':
			cout<<"\n\n\t\t\t\tEnter The account No. : "; cin>>num;
			depositwithdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\t\t\t\tEnter The account No. : "; cin>>num;
			depositwithdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\t\t\t\tEnter The account No. : "; cin>>num;
			displaysp(num);
			break;
		case '5':
			displayall();
			break;
		case '6':
			cout<<"\n\n\t\t\t\tEnter The account No. : "; cin>>num;
			deleteaccount(num);
			break;
		 case '7':
			cout<<"\n\n\t\t\t\tEnter The account No. : ";
			cin>>num;
			modifyaccount(num);
			break;
		 case '8':
		     system("cls");
		     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n       \t\t\t\t\t      Thank You For Using Automatic Banking System";
			getch();
			system("cls");
			exit(0);

		 default :cout<<"wrong choice";
		}
		getch();
    }while(ch!='8');
}
else
{
	cout<<"\n\n Wrong Password!!\n\n\a";
	
	
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    void close();
					}
            else
                    {
					printf("\nInvalid!\n\n\n\t\t\t");
					system("pause");
                    system("cls");
                    main();
					}
}
	
	return 0;
}



void writeaccount()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}


void displaysp(int n)
{
	account ac;
	int flag=0;
	ifstream inFile;
    inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
    while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
    inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}



void modifyaccount(int n)
{
	int found=0;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n==>>Enter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
		    File.write((char *) &ac, sizeof(account));
		    system("cls");
		    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
		    found=1;
		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}




void deleteaccount(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Account Deleted..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
}



void displayall()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

	cout<<"A/c no.\t\tNAME\t\tAddress\t\tPhno\t\t\t\tType\t   Balance\n\n";

	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


void depositwithdraw(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
	    system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited:";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw:";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
				{
				cout<<"Insufficience balance\n\n\n\t";
				system("pause");
				}
				else if(ac.rettype() =='F' || ac.rettype()=='T' || ac.rettype()=='X')
				{
					cout<<"!!!You Cannot withdraw money from Fixed Accounts!!!\n\n\n\t";
					system("pause");
				}
				else                                                                                                                                                           
					ac.draw(amt);                            
			}
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                   \t\t\t\t\t      Record Updated..\n\n     \t\t\t\t\t                     ==>>Press Enter<<==";
			found=1;
	       }
	 }
    File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}