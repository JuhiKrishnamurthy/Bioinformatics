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
	revmap.insert(pair<char, char>('a','t'));
	revmap.insert(pair<char, char>('t','a'));
	revmap.insert(pair<char, char>('g','c'));
	revmap.insert(pair<char, char>('c','g'));
	string gnome;
	ifstream ifile(argv[1]);
	//while(!ifile.eof())
	ifile>>gnome;
	string revgnome=revcomp(gnome);
	cout<<revgnome<<"\n";
	ifile.close();
	return 0;
}

