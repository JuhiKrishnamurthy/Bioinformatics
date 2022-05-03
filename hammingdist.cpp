#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
	string g1;
	string g2;
	ifstream ifile(argv[1]);
	getline(ifile,g1);
	ifile>>g2;
	int hd=0;
	for(int i=0;i<g1.size();i++)
	{
		if(g1[i]!=g2[i])
			hd++;
	}
	cout<<hd<<"\n";
	return 0;
}