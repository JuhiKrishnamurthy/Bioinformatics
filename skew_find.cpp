#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
	ifstream ifile(argv[1]);
	string genome;
	ifile>>genome;
	//int countc=0;
	//int countg=0;
	int n = genome.size();
	int* skew = new int[n+1];
	skew[0]=0;
	for(int i=0;i<n;i++)
	{
		if(genome[i]=='C')
		{
			skew[i+1]=skew[i]-1;
		}
		else if(genome[i]=='G')
		{
			skew[i+1]=skew[i]+1;
		}
		else
		{
			skew[i+1]=skew[i];
		}
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	cout<<skew[i]<<" ";
	// }
	int min = skew[1];
	for(int i=2;i<=n;i++)
	{
		if(skew[i]<=min)
		{
			min = skew[i];
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(skew[i]==min)
		{
			cout<<i<<" ";
		}
	}
	cout<<"\n";
	delete [] skew;
	ifile.close();
	return 0;
}