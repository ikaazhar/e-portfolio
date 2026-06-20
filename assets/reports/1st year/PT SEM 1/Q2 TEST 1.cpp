////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 2
//// Name: Nurul Ika Syafiny Binti Azhar
//// Matric No: A23CS0164
//// Date / Day: 4/1/2024 Thursday
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<iomanip>
using namespace std;

void displayMenu();             // Task 6. Function prototypes
void getUserInput(int *);
float calculateLateFees(int );
void displayLibraryInfo();
// Task 5. Main function
int main()
{
	int menuoption, daysoverdue = 0;
	float latefees;
	
	do
	{
		displayMenu();
		cout<<"Enter your choice(1-3): ";
		cin>>menuoption;
	
		switch( menuoption)
		{
			case 1:
				getUserInput(&daysoverdue);
				latefees = calculateLateFees(daysoverdue);
				cout<<"Late fees: RM"<<fixed<<setprecision(2)<<latefees<<endl;
				break;
				
			case 2:
				displayLibraryInfo();
				break;
				
			case 3:
				break;
			
			default:
				cout<<"Invalid choice. Please enter a number between 1 and 3\n";		
		}
	}while(menuoption != 3);
	
	cout<<"\nExiting the program. Thankyou!";

	return 0;
}

// Task 2. Function displayMenu 
void displayMenu()
{
	cout<<"**********Library Book Checkout System*************"<<endl;
	cout<<"1.Calculate Late Fees\n2.Display Library Information\n3.Quit"<<endl;
}
// Task 4. Function getUserInput with reference parameter
void getUserInput(int *daysoverdue)
{
	cout<<"\nEnter the number of days the book is overdue: ";
	cin>>*daysoverdue;	
}
// Task 1. Function calculateLateFees 
float calculateLateFees(int daysoverdue)
{
	float totalfees;
	
	if(daysoverdue<=7)
	{
		totalfees = 0.5*daysoverdue;
	}
	else if((daysoverdue>7) && (daysoverdue<=14))
	{
		totalfees = 0.5*7.0 + (daysoverdue - 7);
	}
	else
	{
		totalfees = 0.5*7.0 + 7.0 + (daysoverdue - 14);
	}
	return totalfees;
}
// Task 3. Function displayLibraryInfo
void displayLibraryInfo()
{
	cout<<"Library Name: UTM Library\nAddress: Skudai, Johor\nContact: (123) 456 7890\n";
}
 // Task 7. Directives, library, header, etc.








 











