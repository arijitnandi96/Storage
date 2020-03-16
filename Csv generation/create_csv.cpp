/*#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<fstream>
#include<string.h>
#include<unistd.h>*/
#include"c_csv.h"
C :: C()
{
	i=1;
}
long C :: GetMtime(void)
{
	struct timeval currentTime;
	gettimeofday(&currentTime,NULL);
	return ((currentTime.tv_sec*1000000)+currentTime.tv_usec);
}
void C ::  CreateCsv(void)
{
	ofstream fout;
	ifstream fin;
	fin.open("read.txt");
	string line;
	int num;
	long int t,n;
	struct tm *lt,lt1;
	char buff[80];
	char *token1,*token2;
	const char *fl="/home/pi/raw/";
	time_t ts=time(0);
	lt=localtime(&ts);
	sprintf(buff,"%s%d:%d:%d.csv",fl,lt->tm_hour,lt->tm_min,lt->tm_sec);
	fout.open(buff,ios::out|ios::app);
	if(fin.is_open())
		getline(fin,line);
	else
		cout<<"failed to open file"<<endl;
	token1 = strtok(&line[0],"=");
	token2 = strtok(NULL,"=");
	num=atoi(token2);
	t=GetMtime();
 	n=t+((num*60)*1000000);
	do{
		fout<<i;
		t=GetMtime();
	}while(t<=n);
	fin.close();
	fout.close();
}

int main(void)
{
	C ob;
	while(1)
	{
		ob.CreateCsv();
		system("mv /home/pi/raw/*.csv /home/pi/rawcsv/");
	}
	return 0;
}
