#include<iostream>
using namespace std;				//name: Nurul Ika Syafiny Bt Azhar
									//matrics num: A23CS0164
int main()							//date: 1/11/2023
{
	int n, sum=0, m, three, four, five;
	
	cout<<"Enter an interger number:";
	cin>>n;
	
	while(n>0)
	{
		m = n%10;
		sum = sum+m;
		cout<<m;
		n = n/10;
		if(n>0)
		{
			cout<<"+";
		}
	}
	
	cout<<"="<<sum<<"\n";
	
	three = sum%3;
	four = sum%4;
	five = sum%5;
	
	if(three == 0 && four == 0 && five == 0)
	{
		cout<<sum<<" is multiples of 3, 4 and 5";
	}
	else if(three == 0 && four == 0 && five != 0)
	{
		cout<<sum<<" is multiples of 3 and 4";
	}
	else if(three == 0 && four != 0 && five == 0)
	{
		cout<<sum<<" is multiples of 3 and 5";
	}
	else if(three != 0 && four == 0 && five == 0)
	{
		cout<<sum<<" is multiples of 4 and 5";
	}
	else if(three != 0 && four != 0 && five == 0)
	{
		cout<<sum<<" is multiples of 5";
	}
	else if(three != 0 && four == 0 && five != 0)
	{
		cout<<sum<<" is multiples of 4";
	}
	else if(three == 0 && four != 0 && five != 0)
	{
		cout<<sum<<" is multiples of 3";
	}
	else
	{
		cout<<sum<<" is not multiples of 3, 4 and 5";
	}
	
	
	
	return 0;
}
