#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void readFile(fstream& infile, float farenheit[], int *total);
void computeC(float farenheit[], double celcius[], int total);
float average(double celcius[], int total);
void grade(char tempgrade[], double celcius[], int total, int *a, int *b, int *c);
void writeFile(fstream& outfile, double celcius[], float farenheit[], int total, char tempgrade[]);

int main()
{
	fstream infile("input.txt", ios::in);
	fstream outfile("output.txt", ios::out);
	float farenheit[8], avg; 
	double celcius[8];
	int total =0, a=0, b=0, c=0;
	char tempgrade[8];
	float trialcelcius[8];
	
	if(!infile)
	{
		cout<<"error when opening files";
		exit(1);
	}
	
	readFile(infile, farenheit, &total);
	
	computeC(farenheit, celcius, total);

	avg = average(celcius, total);
	
	grade(tempgrade, celcius, total, &a, &b, &c);
	
	writeFile(outfile, celcius, farenheit, total, tempgrade);
	
	infile.close();
	outfile.close();
	
	cout<<"Average of temperature in celcius: "<<avg<<endl;
	cout<<"Number of high temperature: "<<a<<endl;
	cout<<"Number of medium temperature: "<<b<<endl;
	cout<<"Number of low temperature: "<<c<<endl;
	
	return 0;
}

void readFile(fstream& infile, float farenheit[], int *total)
{
	for(int i = 0; i<8; i++)
	{
		infile>>farenheit[i];
		++*total;
	}
}

void computeC(float farenheit[], double celcius[], int total)
{
	for(int i=0; i<total; i++)
	{
		celcius[i] = (farenheit[i] - 32.0)*(5.0/ 9.0);
		
	}
}

float average(double celcius[], int total)
{
	float totaltemp=0, average;
	
	for(int i = 0; i<total; i++)
	{
		totaltemp = totaltemp + celcius[i];
	}
	average = totaltemp/total;
	cout<<fixed<<setprecision(1);
	
	return average; 
}

void grade(char tempgrade[], double celcius[], int total, int *a, int *b, int *c)
{
	for(int i=0; i<total; i++)
	{
		if(celcius[i] >= 35.0)
		{
			tempgrade[i] = 'H';
			++*a;
		}
		else if(celcius[i] < 35.0 && celcius[i] >= 20.0)
		{
			tempgrade[i] = 'M';
			++*b;
		}
		else
		{
			tempgrade[i] = 'L';
			++*c;
		}
	}
}

void writeFile(fstream& outfile, double celcius[], float farenheit[], int total, char tempgrade[])
{	
	outfile<<"C(Celcius)\t\tF(Farenheit)\t\tDescription"<<endl;
	outfile<<"==========\t\t============\t\t============"<<endl;
	for(int i=0; i<total; i++)
	{	
		outfile<<fixed<<setprecision(2)<<celcius[i]<<"\t\t\t"<<farenheit[i]<<"\t\t\t"<<tempgrade[i]<<endl;
	}
}
