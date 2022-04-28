#include<iostream>
#include<fstream>
#include <map>
using namespace std;

map <char, char> revmap;
string revcomp(const string& s)
{
	int n = s.size();
	string revcomp(n,0) ;
	for(int i=0;i<n;i++)
	{
		char temp;
		revcomp[i]=revmap[s[n-1-i]];
	}
	return revcomp;
}
int main(int argc, char*argv[])
{
	revmap.insert(pair<char, char>('A','T'));
	revmap.insert(pair<char, char>('T','A'));
	revmap.insert(pair<char, char>('G','C'));
	revmap.insert(pair<char, char>('C','G'));
	string gnome;
	ifstream ifile(argv[1]);
	//while(!ifile.eof())
	ifile>>gnome;
	string revgnome=revcomp(gnome);
	cout<<revgnome<<"\n";
	ifile.close();
	return 0;
}

