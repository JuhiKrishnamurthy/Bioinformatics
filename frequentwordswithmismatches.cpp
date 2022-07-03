#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int fact(int a)
{
	int res =1;
	for(int i=1;i<=a;i++)
	{
		res*=i;
	}
	return res;
}
int memalloc(int k, int d)
{
	int res=1;
	for(int i=1;i<d;i++)
	{
		res+=fact(k)/(fact(k-d)*fact(d));
	}
	return res;
}
int hammingdist(string g1, string g2)
{
	int hd=0;
	for(int i=0;i<g1.size();i++)
	{
		if(g1[i]!=g2[i])
			hd++;
	}
	return hd;
}
string* get_all_substrs(string g, int k)
{
	int TSIZE;
	TSIZE = (g.size() -k +1);
	string* allsubstrs = new string[TSIZE];
	for(int i=0;i<TSIZE;i++)
	{
		allsubstrs[i] = g.substr(i,k);
	}
	return allsubstrs;
}
string* get_all_perms(string gene , int k, int d )
{
	//allocate memory with the relation summation(k choose d times 3^d) d going from 0 to k
	//nCr = n!/(n-r)!r!(make another function to do this.)
	//loop to find all permutations.
	//return.
	int memory = memalloc(k,d);
	string* allperms = new string[memory];
	return allperms;

}
int main(int argc, char* argv[])
{
	int k;
	int d;
	string genome;
	ifstream ifile(argv[1]);
	getline(ifile,genome);
	ifile>>k;
	ifile>>d;
	int TSIZE;
	TSIZE = (genome.size() -k +1);
	string* allsubstrs;
	allsubstrs=get_all_substrs(genome,k);
	string** allperms;
	for(int i=0;i<TSIZE;i++)
	{
		allperms[i]= get_all_perms(allsubstrs[i],k,d);
	}
	delete [] allsubstrs;
	delete [] allperms;
	return 0;
}