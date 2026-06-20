#include<iostream>
using namespace std;    //name: Nurul Ika Syafiny Binti Azhar
						//matrics num: A23CS0164
int main()				//date: 1/11/2023
{
	int n, sum=0, m, even, four, five;
	
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
	
	even = sum%2;
	four = sum%4;
	five = sum%5;
	
	if(even == 0)
	{
		cout<<sum<<" is even number";
	}
	else
	{
		cout<<sum<<" is odd number";
	}
	
	if(four == 0 && five == 0)
	{
		cout<<" & is multiples of 4 and 5";
	}
	if(four == 0 && five != 0)
	{
		cout<<" & is multiples of 4";
	}
	if(four != 0 && five == 0)
	{
		cout<<" & is multiples of 5";
	}
	
	return 0;
}
