////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 1
//// Name: Nurul Ika Syafiny Bt Azhar
//// Matric No: A23CS0164
//// Date / Day: 4/1/2024 Thursday
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include<iomanip>
using namespace std;

// function prototypes
float price_original();
char choose_Option();
void price_afterTax(float * , char); 

// start main function
int main() 
{
    float price = 0; // should > 0
    char option; // A -> Encyclopedia
                  // B -> Textbook
                  // C -> Novel
                  // D -> Magazine
	option = choose_Option(); 
    price = price_original();
    cout << "Original book price before tax = RM " << price << "\n\n";
    price_afterTax(&price, option);
    cout << "Total book price after tax = RM " <<fixed<<setprecision(2)<<price << '\n';
    return 0;
}

// start new user-defined functions
float price_original() 
{ 
    float bookPrice = 0;
    while (bookPrice <= 0) 
	{ 
        cout << "Please insert the book price (RM): ";
        cin >> bookPrice;
    }
    return bookPrice;
}

char choose_Option() 
{ 
    char category; 
    do 
	{
        cout << "Please choose the book category: \n";
        cout << "A -> Encyclopedia\n";
        cout << "B -> Textbook\n";
        cout << "C -> Novel\n";
        cout << "D -> Magazine\n";
        cout << "Book category (A,B,C,D): ";
        cin >> category;
        cout << "\n";
    } while ((category < 'A') || (category > 'D'));
    return category;
}

// tax is based on book categories as follows:
// A -> Encyclopedia => 3%
// B -> Textbook => 2%
// C -> Novel => 1%
// D -> Magazine => 0.5%
void price_afterTax(float *bookPrice, char category) 
{ 
    float tax;
    switch (category) 
	{
        case 'A': 
			tax = *bookPrice * (3.0 / 100); 
			break; 
        case 'B': 
			tax = *bookPrice * (2.0 / 100); 
			break; 
        case 'C': 
			tax = *bookPrice * (1.0 / 100);
	 		break;
		case 'D': 
			tax = *bookPrice * (0.5 / 100);
			break;
    }
    cout << "Tax price = RM " <<fixed<<setprecision(2)<< tax << "\n";
    *bookPrice += tax;
}

