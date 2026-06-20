//Group members:
//Nurul Ika Syafiny Binti Azhar (A23CS0164)
//Nuraisyah Binti Mohd Zikre (A23CS0160)
//Anis Safiyya Binti Janai (A23CS9049)
//Date: 18/1/2024

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void readFile(fstream& infile, int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[], string store[]);
float grandTotalSales(int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[]);
float totalpermonth(int sales[]);
void highestSale(int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[], float &highestsale, string store[],string &highestbranch, string &highestmonth);
void lowestSale(int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[], float &lowestsale, string store[],string &lowestbranch, string &lowestmonth);

int main()
{
	fstream infile("sales2014.txt", ios::in);
	fstream outfile("salesreport.txt", ios::out);
	const int a = 12;
	int salesJan[a],salesFeb[a], salesMar[a],salesApr[a],salesMay[a];
	int salesJun[a], salesJul[a],salesAug[a],salesSept[a],salesOct[a],salesNov[a],salesDec[a];
	string store[5];
	float grandtotal, totalJan, totalFeb, totalMar, totalApr, totalMay, totalJun, totalJul, totalAug, totalSept, totalOct, totalNov, totalDec;
	float totalavg, highestsale = 0, lowestsale = 94000, totalsalesbranch[5];
	string highestbranch, highestmonth, lowestbranch, lowestmonth;
	
	if(!infile)
	{
		cout<<"error when opening files";
		exit(1);
	}
	readFile(infile,salesJan,salesFeb,salesMar,salesApr,salesMay,salesJun,salesJul,salesAug,salesSept,salesOct,salesNov,salesDec,store);
	grandtotal = grandTotalSales(salesJan,salesFeb,salesMar,salesApr,salesMay,salesJun,salesJul,salesAug,salesSept,salesOct,salesNov,salesDec);
	totalJan = totalpermonth(salesJan);
	totalFeb = totalpermonth(salesFeb);
	totalMar = totalpermonth(salesMar);
	totalApr = totalpermonth(salesApr);
	totalMay = totalpermonth(salesMay);
	totalJun = totalpermonth(salesJun);
	totalJul = totalpermonth(salesJul);
	totalAug = totalpermonth(salesAug);
	totalSept = totalpermonth(salesSept);
	totalOct = totalpermonth(salesOct);
	totalNov = totalpermonth(salesNov);
	totalDec = totalpermonth(salesDec);
	
	totalavg = grandtotal / 12;
	
	highestSale( salesJan, salesFeb, salesMar, salesApr,salesMay, salesJun, salesJul, salesAug,salesSept,salesOct,salesNov,salesDec,highestsale,store,highestbranch,highestmonth);
	lowestSale(salesJan, salesFeb, salesMar,salesApr,salesMay, salesJun, salesJul,salesAug,salesSept,salesOct,salesNov,salesDec,lowestsale,store,lowestbranch, lowestmonth);
	
	for(int i=0;i<5;i++)
	{
		totalsalesbranch[i]= (salesJan[i]+salesFeb[i]+salesMar[i]+salesApr[i]+salesMay[i]+salesJun[i]+salesJul[i]+salesAug[i]+salesSept[i]+salesOct[i]+salesNov[i]+salesDec[i])*1000; 	
	}
	
	outfile<<fixed<<setprecision(2);	
	outfile<<"Total of sales over all stores: RM "<<right<<setw(10)<<grandtotal<<endl;
	outfile<<"Average sales per month: RM"<<right<<setw(10)<<totalavg<<endl;
	outfile<<"\nThe highest sales:\n------------------\nStore:"<<highestbranch<<"\nMonth: "<<highestmonth<<"\nSales: RM"<<right<<setw(10)<<highestsale;
	outfile<<"\n\nThe lowest sales:\n------------------\nStore:"<<lowestbranch<<"\nMonth: "<<lowestmonth<<"\nSales: RM"<<right<<setw(10)<<lowestsale;
	outfile<<"\n\n\nTotal sales by month:\nMonth\tSales\n-----\t-----";
	outfile<<"\nJan\tRM"<<right<<setw(10)<<totalJan;
	outfile<<"\nFeb\tRM"<<right<<setw(10)<<totalFeb;
	outfile<<"\nMar\tRM"<<right<<setw(10)<<totalMar;
	outfile<<"\nApr\tRM"<<right<<setw(10)<<totalApr;
	outfile<<"\nMay\tRM"<<right<<setw(10)<<totalMay;
	outfile<<"\nJun\tRM"<<right<<setw(10)<<totalJun;
	outfile<<"\nJul\tRM"<<right<<setw(10)<<totalJul;
	outfile<<"\nAug\tRM"<<right<<setw(10)<<totalAug;
	outfile<<"\nSep\tRM"<<right<<setw(10)<<totalSept;
	outfile<<"\nOct\tRM"<<right<<setw(10)<<totalOct;
	outfile<<"\nNov\tRM"<<right<<setw(10)<<totalNov;
	outfile<<"\nDec\tRM"<<right<<setw(10)<<totalDec;
	outfile << "\n\nTotal Sales by store: " << endl;
	outfile << "Store \t\tTotal Sales" << endl;
	outfile << "----- \t\t-----------" << endl;
	for(int i=0;i<5;i++)
	{
		outfile<<left<<setw(15)<<store[i]<<" RM "<<right<<setw(10)<<totalsalesbranch[i]<<endl;
	}
	outfile<<"\n\nProfitable stores:\n-----------------";
	for(int i=0;i<5;i++)
	{
		if(totalsalesbranch[i]>=600000)
			outfile<<endl<<store[i];
	}
	
	infile.close();
	return 0;
}

void readFile(fstream& infile, int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[], string store[])
{
	for(int i=0; i<5; i++)
	{
		infile>>salesJan[i]>>salesFeb[i]>>salesMar[i]>>salesApr[i]>>salesMay[i];
		infile>>salesJun[i]>>salesJul[i]>>salesAug[i]>>salesSept[i]>>salesOct[i]>>salesNov[i]>>salesDec[i];
		getline(infile,store[i]);
	}
}

float grandTotalSales(int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[])
{
	float grandsales = 0;
	
	for(int i=0; i<5; i++)
	{
		grandsales = grandsales + salesJan[i]+salesFeb[i]+salesMar[i]+salesApr[i]+salesMay[i]+salesJun[i]+salesJul[i]+salesAug[i]+salesSept[i]+salesOct[i]+salesNov[i]+salesDec[i];
	}
	grandsales = grandsales*1000;
	return grandsales;
}

float totalpermonth(int sales[])
{
	float totalsales = 0;
	for(int i=0; i<5; i++)
	{
		totalsales = totalsales + sales[i];
	}
	totalsales = totalsales*1000;
	return totalsales;
}

void highestSale(int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[], float &highestsale, string store[],string &highestbranch, string &highestmonth)
{
	float jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec;
	
	for(int i=0; i<5; i++)
	{
		jan = salesJan[i]*1000;
		feb = salesFeb[i]*1000;
		mar = salesMar[i]*1000;
		apr = salesApr[i]*1000;
		may = salesMay[i]*1000;
		jun = salesJun[i]*1000;
		jul = salesJul[i]*1000;
		aug = salesAug[i]*1000;
		sep = salesSept[i]*1000;
		oct = salesOct[i]*1000;
		nov = salesNov[i]*1000;
		dec = salesDec[i]*1000;
		
		if(jan>highestsale)
		{
			highestsale = jan;
			highestbranch = store[i];
			highestmonth = "Jan";
			
		}
		if(feb>highestsale)
		{
			highestsale = feb;
			highestbranch = store[i];
			highestmonth = "Feb";
		}
		if(mar>highestsale)
		{
			highestsale = mar;
			highestbranch = store[i];
			highestmonth = "Mar";
		}
		if(apr>highestsale)
		{
			highestsale = apr;
			highestbranch = store[i];
			highestmonth = "Apr";
		}
		if(may>highestsale)
		{
			highestsale = may;
			highestbranch = store[i];
			highestmonth = "May";
		}
		if(jun>highestsale)
		{
			highestsale = jun;
			highestbranch = store[i];
			highestmonth = "Jun";
		}
		if(jul>highestsale)
		{
			highestsale = jul;
			highestbranch = store[i];
			highestmonth = "Jul";
		}
		if(aug>highestsale)
		{
			highestsale = aug;
			highestbranch = store[i];
			highestmonth = "Aug";
		}
		if(sep>highestsale)
		{
			highestsale = sep;
			highestbranch = store[i];
			highestmonth = "Sep";
		}
		if(oct>highestsale)
		{
			highestsale = oct;
			highestbranch = store[i];
			highestmonth = "Oct";
		}
		if(nov>highestsale)
		{
			highestsale = nov;
			highestbranch = store[i];
			highestmonth = "Nov";
		}
		if(dec>highestsale)
		{
			highestsale = dec;
			highestbranch = store[i];
			highestmonth = "Dec";
		}
	}
	
}

void lowestSale(int salesJan[], int salesFeb[], int salesMar[], int salesApr[], int salesMay[], int salesJun[], int salesJul[], int salesAug[], int salesSept[], int salesOct[], int salesNov[], int salesDec[], float &lowestsale, string store[],string &lowestbranch, string &lowestmonth)
{
	float jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec;
	
	for(int i=0; i<5; i++)
	{
		jan = salesJan[i]*1000;
		feb = salesFeb[i]*1000;
		mar = salesMar[i]*1000;
		apr = salesApr[i]*1000;
		may = salesMay[i]*1000;
		jun = salesJun[i]*1000;
		jul = salesJul[i]*1000;
		aug = salesAug[i]*1000;
		sep = salesSept[i]*1000;
		oct = salesOct[i]*1000;
		nov = salesNov[i]*1000;
		dec = salesDec[i]*1000;
		
		if(jan<lowestsale)
		{
			lowestsale = jan;
			lowestbranch = store[i];
			lowestmonth = "Jan";
			
		}
		if(feb<lowestsale)
		{
			lowestsale = feb;
			lowestbranch = store[i];
			lowestmonth = "Feb";
		}
		if(mar<lowestsale)
		{
			lowestsale = mar;
			lowestbranch = store[i];
			lowestmonth = "Mar";
		}
		if(apr<lowestsale)
		{
			lowestsale = apr;
			lowestbranch = store[i];
			lowestmonth = "Apr";
		}
		if(may<lowestsale)
		{
			lowestsale = may;
			lowestbranch = store[i];
			lowestmonth = "May";
		}
		if(jun<lowestsale)
		{
			lowestsale = jun;
			lowestbranch = store[i];
			lowestmonth = "Jun";
		}
		if(jul<lowestsale)
		{
			lowestsale = jul;
			lowestbranch = store[i];
			lowestmonth = "Jul";
		}
		if(aug<lowestsale)
		{
			lowestsale = aug;
			lowestbranch = store[i];
			lowestmonth = "Aug";
		}
		if(sep<lowestsale)
		{
			lowestsale = sep;
			lowestbranch = store[i];
			lowestmonth = "Sep";
		}
		if(oct<lowestsale)
		{
			lowestsale = oct;
			lowestbranch = store[i];
			lowestmonth = "Oct";
		}
		if(nov<lowestsale)
		{
			lowestsale = nov;
			lowestbranch = store[i];
			lowestmonth = "Nov";
		}
		if(dec<lowestsale)
		{
			lowestsale = dec;
			lowestbranch = store[i];
			lowestmonth = "Dec";
		}
	}
}
