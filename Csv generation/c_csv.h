#include<iostream>
#include<stdlib.h>
#include<sys/time.h>
#include<fstream>
#include<string.h>
#include<unistd.h>
using namespace std;
class C
{
	int i;
	public:
		C();
		void CreateCsv(void);
		long GetMtime(void);
		~C(){}
};
