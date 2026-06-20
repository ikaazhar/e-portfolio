#include<iostream>
#include<cstring>
using namespace std;

void dispStatus(int activecase);
void getInput(int &totalcase, int &newcase, int &totaldeath, int &recovered);
void dispOutput(int activecase);
float calcAverage(int numofstates, int totalactivecase);

int main()
{
	char statename[50], higheststate[50];
	int activecase, totalcase, newcase, totaldeath, recovered, numofstates = 0, totalactivecase = 0, highestcase =0;
	float average;
	
	do
	{
		cout<<"<<<<<<<<<<<<<<DATA>>>>>>>>>>>>>>>>\n";
		cout<<"State name     :";
		cin>>statename;
		numofstates++;
		getInput(totalcase,newcase,totaldeath,recovered);
		
		activecase = totalcase + newcase - totaldeath - recovered;
		totalactivecase = totalactivecase + activecase;
		if(highestcase < activecase)
		{
			highestcase = activecase;
			strcpy(higheststate, statename);
		}
		
		cout<<"\n\n<<<<<<<<<<<<<<SUMMARY>>>>>>>>>>>>>>>";
		dispOutput(activecase);
		
		
		cin.ignore();
		cout<<"\n\nPress <ENTER> to continue......";
	}while(cin.get() == '\n');
	
	average = calcAverage(numofstates,totalactivecase);
	
	cout<<"\n\n<<<<<<<<<<<ACTIVE CASE>>>>>>>>>>>>>";
	cout<<"\nTotal   : "<<totalactivecase;
	cout<<"\nHighest :"<<highestcase<<" ("<<higheststate<<")";
	cout<<"\nAverage for "<<numofstates<<" states:"<<average;

	return 0;	
}

void getInput(int &totalcase, int &newcase, int &totaldeath, int &recovered)
{
	cout<<"\nTotal cases    :";
	cin>>totalcase;
	cout<<"\nNew cases      :";
	cin>>newcase;
	cout<<"\nTotal death    :";
	cin>>totaldeath;
	cout<<"\nTotal recovered:";
	cin>>recovered;	
}

void dispOutput(int activecase)
{
	cout<<"\nActive cases  :"<<activecase;
	dispStatus(activecase);
}

void dispStatus(int activecase)
{
	if(activecase > 40)
	{
		cout<<"\nStatus        : Red Zone";
	}
	else if(activecase >= 21 && activecase <= 40)
	{
		cout<<"\nStatus        : Orange Zone";
	}
	else if(activecase >= 1 && activecase <= 20)
	{
		cout<<"\nStatus        : Yellow Zone";
	}
	else
	{
		cout<<"\nStatus        : Green Zone";
	}
}

float calcAverage(int numofstates, int totalactivecase)
{
	float average;
	
	average = totalactivecase/numofstates;
	return average;
}
