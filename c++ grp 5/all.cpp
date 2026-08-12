#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#define Name "qwert"
#define Pass "abc1234"
#define shipping 5.00

struct Genre { string name; };

struct user
{
	char name[50],pass[50],conf_pass[50];
};

struct Book
{
	string title;
	string author;
	double price;

};

struct Genre genre[10] = {
    { "Romance" },
    { "Science Fiction" },
    { "Thriller" },
    { "Baking" },
    { "Business" }
};

struct Book cart[100];
int cartCount = 0;

void wel();
void loginorsignup();
void again();
void again1();
void agian2();
void login();
void signup();
void mainlogin();
void MainDashboard();
int GenreList();
void BookList(string FileName, int genreIndex);
void Checkout();
void Payment(double FinalTotal);
void Cart();
void RemoveItem();
void Exit();
void addbook();
void admin();

main()
{
	mainlogin();
	MainDashboard();

}

void mainlogin()
{
	int choice; 
	wel();
	do
	{
		loginorsignup();
		cin>>choice;
		
		if(choice==1)
			login();
		else if (choice==2)
			signup();
		else if (choice ==3)
			admin();
		else 
			again();
	} while(choice!=1 && choice !=2 && choice !=3);
}

void MainDashboard()
{
	int choice; 
	
	do {
		cout<<endl;
        cout<<"\t---------------------------------------------------------------------------------"<<endl;
        cout<<"\t|\t\t\t\tBookstore Dashboard\t\t\t\t|"<<endl;
        cout<<"\t---------------------------------------------------------------------------------"<<endl;
        cout<<"\t|\t\t\t1. Browse book by genre\t\t\t\t\t|"<<endl;
        cout<<"\t|\t\t\t2. View cart\t\t\t\t\t\t|"<<endl;
        cout<<"\t|\t\t\t3. Checkout\t\t\t\t\t\t|"<<endl;
        cout<<"\t|\t\t\t4. Quit program\t\t\t\t\t\t|"<<endl;
        cout<<"\t---------------------------------------------------------------------------------"<<endl;
        cout<<"\tEnter your choice: ";  
        cin>>choice;
        cout<<endl;
        switch(choice) 
		{
            case 1: 
            	while (true)
				{
					int genreChoice = GenreList();
		
					if (genreChoice == 0)
					{
						cout<<endl;
						cout<<endl;
						cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
						cout<<"\t|\t\t\tDirecting to main dashboard...\t\t\t\t|\n";
						cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
						cout<<endl;
						MainDashboard();
						break;
					}
					else if (genreChoice >= 1 && genreChoice <=5)
					{
						string filenames[10] = {
							"romance.txt",
							"scifi.txt",
							"thriller.txt",
							"baking.txt",
							"business.txt"
							};
						
						BookList(filenames[genreChoice - 1], genreChoice - 1);
					}
					else
						again();
				}
                break;
            
            case 2: 
                Cart();
                break;
            
            case 3:
				Checkout();               
                break;
                
            case 4:
            	Exit();
                break; 
                
            default: 
                again();
                break;
        }
    } while (choice < 1 || choice > 4);
 }

void wel()
{
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t|\t\t\t\tWelcome to BookXcess!\t\t\t\t|"<<endl;
	cout<<"\t|\t\t\t\t\t\t\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
}

void loginorsignup()
{
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t|\t\t\t\t|\t\t\t|"<<endl;
	cout<<"\t|\t  1. Login      |\t   2. Sign Up    \t|\t3.Admin\t\t|"<<endl;
	cout<<"\t|\t\t\t|\t\t\t\t|\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;

	cout<<"\t\t\tEnter 1 to Login. Enter 2 to Sign Up. Enter 3 to Admin.\t\t"<<endl;
	cout <<"\t Enter your choice : ";
}

void again()
{
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t  Invalid Option. Reenter again\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
}

void again1()
{
	int choice;

	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|\t\t1. Try Again \t\t|\t\t2. Quit \t\t|"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t\t\t    Enter 1 to Try Again. Enter 2 to Quit.\t\t\t"<<endl;
	cout <<"\t\t\t    Enter your choice : ";
	cin >> choice;
	
	if(choice == 1){
		login();
	}
	else if(choice == 2){
		mainlogin();
	}
}

void again2()
{
	int choice;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|\t\t1. Try Again \t\t|\t\t2. Quit \t\t|"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t\t\t    Enter 1 to Try Again. Enter 2 to Quit.\t\t\t"<<endl;
	cout <<"\t\t\t    Enter your choice : ";
	cin >> choice;
	
	if(choice == 1){
		signup();
	}
	else if(choice == 2){
		mainlogin();
	}
}

void again3()
{
	int choice;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|\t  1. Continue add book \t\t|\t\t2. Quit \t\t|"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t\t\t  Enter 1 to Continue add book. Enter 2 to Quit.\t\t\t"<<endl;
	cout <<"\t\t\t  Enter your choice : ";
	cin >> choice;
	
	if(choice == 1){
		addbook();
	}
	else if(choice == 2){
		mainlogin();
	}
}

void admin()
{
	int PASS, failcount=0;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t   Admin \t\t\t\t\t|\t"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	do
	{
		cout<<"\tAdmin Code:";
		cin>>PASS;
		if(PASS == 8888)
		{
			addbook();
			break;
		}
		else
		{
			again();
			failcount++;
		}
	}while(failcount<3);
		mainlogin();
}

void login()
{
	char name[50], pass[50];
	
	int failCount = 0;
	cout<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t     Login\t\t\t\t\t|\t"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	
	do
	{
		cin.ignore();
		cout<<"\t|Username : ";cin >>name;
		cout<<"\t|Password : "; cin >>pass;
		
		
		if((strcmp(name,Name)!=0) || (strcmp(pass,Pass)!=0))
		{
			failCount++;
			cout<<"\t|Login Failed !"<<endl;
			cout<<"\t|Incorrect username or password.Re-enter again."<<endl;
		}
	}while(((strcmp(name,Name)!=0) 
	|| (strcmp(pass,Pass)!=0)) && failCount <3 );
	
	if((strcmp(name,Name)==0) && (strcmp(pass,Pass)==0))
	{
		cout<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\t|\t\t\t\tLogin successful!\t\t\t\t|\t"<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	}
	else if (failCount == 3) 
	{
		again1();
	}
}

void signup()
{
	char name[50],pass[50],conf_pass[50];
	int failCount = 0;
	cout<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t     Sign Up\t\t\t\t\t|\t"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cin.ignore();
	cout<<"\t|Username:";cin>>name;
	do
	{
		cout<<"\t|Password:";cin>>pass;
		cout<<"\t|Confirm Password:";cin>>conf_pass;
		
		if (strcmp(pass,conf_pass)!=0)
		{
			failCount++;
			cout<<"\t|Sign Up Failed !"<<endl;
			cout<<"\t|Password doesn't match. Please re-enter again."<<endl;
		}
	}while(strcmp(pass,conf_pass)!=0 && failCount <3);
	if((strcmp(pass,conf_pass)==0) )
	{
		cout<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\t|\t\t\t\tSign up complete!\t\t\t\t|\t"<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	}
	else if (failCount == 3) 
	{
		again2();
	}
}

int GenreList()
{
	int choice;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t    Genre List\t\t\t\t\t|\t"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t\t\t\t0. Dashboard\t\t\t\t\t\t"<<endl;
	for (int i=0; i<5; i++)
	{
		cout<<"\t\t\t\t"<<i+1<<". "<<genre[i].name<<"\t\t\t\t\t\t"<<endl;
	}
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\tEnter category: ";
	cin>> choice;
	
	return choice;
}

void BookList(string FileName, int genreIndex)
{
	Book books[100];
	int bookCount = 0;
	
	ifstream file(FileName);
	if (!file)
	{
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout << "\t|\t\t\tError: Cannot open file '" << FileName <<"'\t\t\t|\n";
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		return; 
	}
	
	while (getline(file, books[bookCount].title) && getline(file, books[bookCount].author) && file >> books[bookCount].price)
	{
		file.ignore();
		bookCount++;
	}
	file.close();
	
	char again = 'Y';
	while (again == 'Y' || again == 'y')
	{
		cout<<"\n";
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\t\t\t\t\t"<<genre[genreIndex].name<<"Books\t\t\t\t\n";
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		
		for(int i=0; i<bookCount; i++)
		{
			cout<< "\t\t\t\t" << i+1 << ". \t" << books[i].title << endl;
			cout<< "\t\t\t\tAuthor :  "<<books[i].author<<endl;
			cout<< "\t\t\t\tPrice  : RM  "<< books[i].price<<endl;
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		}
		cout<<"\t\t\t\t"<<bookCount + 1 <<". Go back to genre list\n";
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<endl;
		int bookChoice;
		cout<<endl;
		cout<<"\t\t\t\tEnter the book number to add to cart: ";
		cin>>bookChoice;
		cout<<endl;
		if(bookChoice == bookCount + 1)
			return;
		else if(bookChoice >=1 && bookChoice <= bookCount)
		{
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cout<<endl;
			cout<<"\t\t\t\t'"<<books[bookChoice - 1].title<<"' added to cart!\t\t\t\t\n";
			cout<<endl;
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cart[cartCount] = books[bookChoice - 1];
			cartCount++;
			cout<<endl;
			cout<<"\t\t\tAdd another book from the same genre? (Y/N): ";
			cin>>again;
			cout<<endl;
		}
		else{
		
			cout<<endl;
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cout<<"\t|\t\t\t  Invalid Option. Reenter again\t\t\t\t|"<<endl;
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cout<<endl;
		}
	}
	return;
}

void Checkout()
{
	if (cartCount == 0)
	{
		cout<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<< "\t|\t\tYour cart is empty. Cannot proceed to checkout.\t\t\t|"<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<endl;
		MainDashboard();
		return;
	}
	
	cout << "\n\tItems in your cart: \n";
	double total = 0;
	
	for (int i=0; i<cartCount; i++)
	{
		cout<<"\t"<<i+1<<". "<<cart[i].title<<" - RM "<<cart[i].price<<endl;
		total += cart[i].price;
	}
	
	double finalTotal = total + shipping;
	
	cout<<"\tShipping cost: RM" << shipping <<endl;
	cout<<"\tTotal (incl. shipping): RM" << finalTotal <<endl;
	
	int option;
	cout<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|\t    1. Proceed Payment \t\t|\t     2. Return to cart\t\t|"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\tEnter your choice : ";
	cin>>option;
	cout<<endl;
	switch (option)
	{
		case 1:
			Payment(finalTotal);
			break;
		
		case 2:
			cout<<endl;
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cout<<"\t|\t\t\t\tReturning to cart....\t\t\t\t|\t\n";
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cout<<endl;
			Cart();
			return;
			break;
			
		default:
			again();
			break;
	}
}

void Payment(double FinalTotal)
{
	string fullname, address, city;
	int phonenum, postcode,action;
	char choice;
	
	cout<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t  Checkout\t\t\t\t\t|"<<endl;
	cout<<"\t|\t\t     Please enter your delivery details below.\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t\tFull Name    : ";
	cin.ignore();
	getline(cin, fullname);
	cout<<"\t\tAddress Line : ";
	getline(cin, address);
	cout<<"\t\tCity         : ";
	getline(cin, city);
	cout<<"\t\tPostcode     : ";
	cin>>postcode;
	cout<<"\t\tPhone number(without special character): ";
	cin>>phonenum;
	cout<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\tConfirm Checkout?\t\t\t\t|\t"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|\t    1. Confirm and Pay \t\t|\t\t2. Cancel\t\t|"<<endl;
	cout<<"\t|\t\t\t\t\t|\t\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\tEnter your choice: ";
	cin>>action;
	cout<<endl;
	switch(action)
	{
		case 1:
		cout<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\t|\t\t\t\tPayment successful!\t\t\t\t|\t"<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\tDo you want back to dashboard? ( Press 'y' to Yes / Press others to No  ): ";
		cin>>choice;
		if (choice == 'Y' || choice == 'y')
		{
			MainDashboard();
			break;
		}
		else
			Exit();
			break;
		case 2:
			cout<<endl;
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cout<<"\t|\t\t\tReturning to checkout....\t\t\t\t|\t\n";
			cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
			cout<<endl;
			Checkout();
			break;
		default:
			Cart();
			break;
	}
}

void Cart()
{
	float totalPrice = 0;
	int choice;
	
	if (cartCount == 0)
	{
		cout<<endl;
		cout<<"\t+-----------------------------------------------------------------------------+"<<endl;
		cout<<"\t|\t\t\t\tYour cart is empty.\t\t\t\t|\n";
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<endl;
		MainDashboard();
		return;
	}
	
	while(true)
	{
		float totalPrice=0;
		cout<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\t|\t\t\t           Your Cart     \t\t\t\t|\n";
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<endl;
		
		for (int j=0; j<cartCount; j++)
		{
			cout<<"\t"<<j+1<<". "<<cart[j].title<<" - RM"<<cart[j].price<<endl;
			totalPrice += cart[j].price;
		}
		
		cout<<"\n\tTotal: RM"<<totalPrice<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\t|\t\t\t1.Proceed to checkout \t\t\t\t\t|"<<endl;
		cout<<"\t|\t\t\t2.Remove item \t\t\t\t\t\t|"<<endl;
		cout<<"\t|\t\t\t3.Return to dashboard \t\t\t\t\t|"<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\tEnter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				Checkout();
				break;
			case 2:
				RemoveItem();
				break;
			case 3:
				MainDashboard();
				break;
			default:
				again();
				Cart();
				break;
		}
	}
}

void RemoveItem()
{
	int index;
	cout<<"\tEnter the number of the item to remove: ";
	cin>>index;
	
	if(index < 1 || index > cartCount)
	{
		cout<<endl;
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<"\t|\t\t\tInvalid number. No item removed.\t\t\t|\n";
		cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
		cout<<endl;
		return;
	}
	double total = 0.0;
	total -= cart[index - 1].price;

	
	//Shift items left to overwrite the removed item
	for (int m = index-1; m<cartCount-1; m++)
	{
		cart[m] = cart[m+1];
	}
	
		cartCount--;
	cout<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\tItem removed successfully.\t\t\t\t|\n";
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<endl;
}


void Exit()
{
	cout<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\tExiting program....\t\t\t\t|\t"<<endl;
	cout<<"\t|\t\t\tThank you for visiting! Goodbye.\t\t\t|\t"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<endl;
	exit(0);
}

void addbook()
{
	int cat , i;
	struct Book book;
	ofstream bake;
	bake.open("baking.txt",ios_base::app); 
	ofstream biz;
	biz.open("business.txt",ios_base::app) ;
	ofstream romantic;
	romantic.open("romance.txt",ios_base::app) ;
	ofstream scifi;
	scifi.open("scifi.txt",ios_base::app) ;
	ofstream thriller;
	thriller.open("thriller.txt",ios_base::app) ;
	
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t\t CHOOSE CATEGORY\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|\t\t\t1. Baking\t\t\t\t\t\t|"<<endl;
	cout<<"\t|\t\t\t2. Business & Economics\t\t\t\t\t|"<<endl;
	cout<<"\t|\t\t\t3. Crime, Thriller & Mystery\t\t\t\t|"<<endl;
	cout<<"\t|\t\t\t4. Fantasy & Science Fiction\t\t\t\t|"<<endl;
	cout<<"\t|\t\t\t5. Romance\t\t\t\t\t\t|"<<endl;
	cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
	cout<<"\tEnter your choice: ";
	cin>>cat;
	
	if (cat<=4 && cat >=1)
	{
		switch (cat)
		{
			case 1: cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					cout<<"\t\t\t\t Book Title: ";
					cin>>book.title ;
					cout<<"\t\t\t\t Author: ";
					cin>>book.author ;
					cout<<"\t\t\t\t Price: ";
					cin>>book.price ;
					cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					bake<<book.title<<"\n";
					bake<<book.author<<"\n";
					bake<<book.price<<"\n";
					bake.close();
					break;
					
			case 2: cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					cout<<"\t\t\t\t Book Title: ";
					cin>>book.title ;
					cout<<"\t\t\t\t Author: ";
					cin>>book.author ;
					cout<<"\t\t\t\tPrice: ";
					cin>>book.price ;
					cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					biz<<book.title<<"\n";
					biz<<book.author<<"\n";
					biz<<book.price<<"\n";
					biz.close();
					break;
					
			case 3: cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					cout<<"\t\t\t\t Book Title: ";
					cin>>book.title ;
					cout<<"\t\t\t\t Author: ";
					cin>>book.author ;
					cout<<"\t\t\t\tPrice: ";
					cin>>book.price ;
					cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					thriller<<book.title<<"\n";
					thriller<<book.author<<"\n";
					thriller<<book.price<<"\n";
					thriller.close();
					break;
					
			case 4: cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					cout<<"\t\t\t\t Book Title: ";
					cin>>book.title ;
					cout<<"\t\t\t\t Author: ";
					cin>>book.author ;
					cout<<"\t\t\t\tPrice: ";
					cin>>book.price ;
					cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					scifi<<book.title<<"\n";
					scifi<<book.author<<"\n";
					scifi<<book.price<<"\n";
					scifi.close();
					break;
					
			case 5: cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					cout<<"\t\t\t\t Book Title: ";
					cin>>book.title ;
					cout<<"\t\t\t\t Author: ";
					cin>>book.author ;
					cout<<"\t\t\t\tPrice: ";
					cin>>book.price ;
					cout<<"\t+-------------------------------------------------------------------------------+"<<endl;
					romantic<<book.title<<"\n";
					romantic<<book.author<<"\n";
					romantic<<book.price<<"\n";
					romantic.close();
					break;
		}
		again3();
	}
	else
	{
		again();
		addbook();
	}
}