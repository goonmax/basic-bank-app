
//          yoooooooo


#include <iostream>
#include <cstdlib>
#include <ostream>
#include <string>
#include <cctype>
#include <iomanip> 
#include <fstream>      

class account
{
    int accnumber;
    char name [50];
    int deposit;
    char type;
public:
void create_account();	
	void show_account() const;	
	void modify();	
	void dep(int);	
	void draw(int);
	void report() const;	
	int retacno() const;	
	int retdeposit() const;	
	char rettype() const;	
};


void account::show_account() const
{
	std::cout<<"\nAccount No. : "<<accnumber;
	std::cout<<"\nAccount Holder Name : ";
	std::cout<<name;
	std::cout<<"\nType of Account : "<<type;
	std::cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
	std::cout<<"\nAccount No. : "<<accnumber;
	std::cout<<"\nModify Account Holder Name : ";
	std::cin.ignore();
	std::cin.getline(name,50);
	std::cout<<"\nModify Type of Account : ";
	std::cin>>type;
	type=toupper(type);
	std::cout<<"\nModify Balance amount : ";
	std::cin>>deposit;
}


void account::create_account()
{
	std::cout<<"\nEnter The account No. :"<< std::endl;
	std::cin>>accnumber;
	std::cout<<"\n\nEnter The Name of The account Holder : "<< std::endl;
	std::cin.ignore();
	std::cin.getline(name,50);
	std::cout<<"\nEnter Type of The account (C/S) : "<< std::endl;
	std::cin>>type;
	type=toupper(type);
	std::cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : "<< std::endl;
	std::cin>>deposit;
	std::cout<<"\n\n\nAccount Created.."<< std::endl;
}

  void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	std::cout<<accnumber<<std::endl<<" "<<name<<std::endl<<" "<<type<<deposit<<std::endl;
}

	
int account::retacno() const
{
	return accnumber;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}


void intro()
{
    char name[50];
    std::cout << "***********************" << std::endl;
    std::cout << "welcome****************" << std::endl;
    std::cout << "***********************" << std::endl;
    std::cout << "Please enter a name.....\n" << std::endl;
    std::cin.ignore();
	std::cin.getline(name,50);
    system("ls -l");
}
void cardchecker ()
{
     int num;



const int n = 16; 
int card[n]; //this sotres the card 
int sum = 0;
int evensum, oddsum = 0;
std::string input = "";
std::cout << "please enter card number to check is vaild chhhheeeehoooo" << std::endl;
std::cin >> input;

for (int i = 0; i < input.size(); i++) card[i] = input[i] - '0';


for (int i = n - 1; i >= 0; i--)
{
int p;
int num = card[i];
if (i % 2 == 0)
    {
        p = num * 2;
        if (p > 9) 
        p = p - 9;
        evensum += p;
    }
    else
        {
            p = num;
            oddsum += p;
        }

}
sum = evensum + oddsum;
std::cout << "even sum is: " << evensum;
std::cout << "odd sum is: " << oddsum;
std::cout << "total sum is: " << sum <<std::endl;

if (sum % 10 == 0) std::cout << "Card is Valid!" << std::endl;
else std::cout << "Card is invalid!!" << std::endl;
}





void write_account();	
void display_sp(int);	
void modify_account(int);	
void delete_account(int);	
void display_all();		
void deposit_withdraw(int, int); 

int main(int argc, char *argv[])
{
char ch;
int num;
intro();
cardchecker();
 
do
	{
		
        std::cout<<"*************************************"<<std::endl;
		std::cout<<"\nMAIN MENU"<<std::endl;
        std::cout<<"*************************************"<<std::endl;
		std::cout<<"\n01. NEW ACCOUNT"<<std::endl;
		std::cout<<"\n02. DEPOSIT AMOUNT"<<std::endl;
		std::cout<<"\n03. WITHDRAW AMOUNT"<<std::endl;
		std::cout<<"\n04. BALANCE ENQUIRY"<<std::endl;
		std::cout<<"\n05. ALL ACCOUNT HOLDER LIST"<<std::endl;
		std::cout<<"\n06. CLOSE AN ACCOUNT"<<std::endl;
		std::cout<<"\n07. MODIFY AN ACCOUNT"<<std::endl;
		std::cout<<"\n08. EXIT"<<std::endl;
		std::cout<<"\nSelect Your Option (1-8) "<<std::endl;
        std::cout<<"*************************************"<<std::endl;

		std::cin>>ch;
		system("clear");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			std::cout<<"\n\n\tEnter The account No. : "; std::cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			std::cout<<"\n\n\tEnter The account No. : "; std::cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			std::cout<<"\n\n\tEnter The account No. : "; std::cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			std::cout<<"\n\n\tEnter The account No. : "; std::cin>>num;
			delete_account(num);
			break;
		 case '7':
			std::cout<<"\n\n\tEnter The account No. : "; std::cin>>num;
			modify_account(num);
			break;
		 case '8':
			std::cout<<"\n\n\tThanks for using bank managemnt system";
			break;
		 default :std::cout<<"\a";
		}
		std::cin.ignore();
		std::cin.get();
	}while(ch!='8');
	return 0;
}

void write_account()
{
	account ac;
	std::ofstream outFile;
	outFile.open("account.dat",std::ios::binary|std::ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	std::ifstream inFile;
	inFile.open("account.dat",std::ios::binary);
	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
		return;
	}
	std::cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		std::cout<<"\n\nAccount number does not exist";
}

void modify_account(int n)
{
	bool found=false;
	account ac;
	std::fstream File;
	File.open("account.dat",std::ios::binary|std::ios::in|std::ios::out);
	if(!File)
	{
		std::cout<<"File could not be open rip";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			std::cout<<"\n\nEnter The New Details of account"<<std::endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,std::ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			std::cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		std::cout<<"\n\n Record Not Found ";
}


void delete_account(int n)
{
	account ac;
	std::ifstream inFile;
	std::ofstream outFile;
	inFile.open("account.dat",std::ios::binary);
	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",std::ios::binary);
	inFile.seekg(0,std::ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	std::cout<<"\n\n\tRecord Deleted ..";
}


void display_all()
{
	account ac;
	std::ifstream inFile;
	inFile.open("account.dat",std::ios::binary);
	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
		return;
	}
	std::cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	std::cout<<"====================================================\n";
	std::cout<<"A/c no.      NAME           Type  Balance\n";
	std::cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	std::fstream File;
	File.open("account.dat", std::ios::binary|std::ios::in|std::ios::out);
	if(!File)
	{
		std::cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				std::cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				std::cout<<"\n\nEnter The amount to be deposited";
				std::cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				std::cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				std::cout<<"\n\nEnter The amount to be withdraw";
				std::cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					std::cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,std::ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			std::cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		std::cout<<"\n\n Record Not Found ";
}