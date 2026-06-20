#include<iostream>
using namespace std;
void monthly_installement(int Price);

int main()
{
	int name, type, region, Price;
	char repeat;
	
	do
	{
		cout<<"Proton Car Loan Calculator\n";
		do
		{
			cout<<"\nModel [1-50, 2-Exora, 3-Persona]: ";
			cin>>name;
		
			if(name>3)
			{
				cout<<"\nInvalid code. Please enter again\n";
			}
		}while(name>3);
	
		do
		{
			cout<<"\nVariants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
			cin>>type;
		
			if(type>2)
			{
				cout<<"\nInvalid code. Please enter again\n";
			}
		}while(type>2);
	
		do
		{
			cout<<"\nRegion [1-Peninsular Malaysia, 2-East Malaysia]: ";
			cin>>region;
		
			if(region>2)
			{
				cout<<"\nInvalid code. Please enter again\n";
			}
		}while(region>2);
	
		cout<<"\nCar Info";
	
		if(name == 1)
		{
			cout<<"\nModel: X50";
		}
		else if(name == 2)
		{
			cout<<"\nModel: Exora";
		}
		else
		{
			cout<<"\nModel: Persona";
		}
		
		if(type == 1)
		{
			cout<<"\nVariant: 1.6L Standard CVT";
		}
		else
		{
			cout<<"\nVariant: 1.6L Premium CVT";
		}
	
		if(region == 1)
		{
			cout<<"\nRegion: Peninsular Malaysia";
		}
		else
		{
			cout<<"\nRegion: East Malaysia";
		}
	
		cout<<"\nPaint Type: Metalic";
	
		if(name == 1 && type == 1)
		{
			cout<<"\nPrice: RM 86300";
			Price= 86300;
		}
		else if(name == 1 && type == 2)
		{
			cout<<"\nPrice: RM 101800";
			Price= 101800;
		}
		else if(name == 2 && type == 1)
		{
			cout<<"\nPrice: RM59800";
			Price= 59800;
		}
		else if(name == 2 && type == 2)
		{
			cout<<"\nPrice: RM 66800";
			Price= 66800;
		}
		else if(name == 3 && type == 1)
		{
			cout<<"\nPrice: RM 47800";
			Price= 47800;
		}
		else
		{
			cout<<"\nPrice: RM 58300";
			Price= 58300;
		}
	
		monthly_installement(Price);
	
		cout<<"\nDo you want to enter other data? [Y @ N]: ";
		cin>>repeat;
		
	}while(repeat == 'Y' || repeat == 'y');
	
	cout<<"\nThank you :)";
	return 0;
}

void monthly_installement(int Price)
{
	int downpay, period, leftprice;
	float total, interest, interestrate, monthlypayment;
	
	cout<<"\n\nDown Payment (MYR): ";
	cin>>downpay;
	cout<<"\nInterest Rate (%):";
	cin>>interestrate;
	cout<<"\nRepayment Period (in years):";
	cin>>period;
	
	leftprice = Price - downpay;
	interest = (interestrate/100) * leftprice * period;
	total = leftprice + interest;
	monthlypayment = total / (period * 12); 
	
	cout<<"\nMONTHLY INSTALLMENT (MYR):"<<monthlypayment;
}



