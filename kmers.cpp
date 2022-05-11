#include<iostream>
#include<map>
#include<unordered_map>
#include<fstream>
using namespace std;
int main(int argc,char*argv [])
{
	string str;
	ifstream ifile;
	ifile.open(argv[1]);
	getline(ifile,str);
	int k = atoi(argv[2]);
	unordered_map<string,int> kmers;
	//char* tstr = str.c_str();
	int length = str.size();
	for(int i=0;i<length-k;i++)
	{
		if(kmers.find(str.substr(i,k))==kmers.end())
		{
			kmers.insert(make_pair(str.substr(i,k),0));
			//kmers[str.substr(i,k)]=0;
		}
		kmers[str.substr(i,k)]+=1;
	}
	for(auto it =kmers.begin();it!=kmers.end();it++)
	{
		cout<<it->first<<" "<<it->second<<"\n";
	}
}