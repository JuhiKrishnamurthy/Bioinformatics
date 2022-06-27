#include<iostream>
#include<fstream>
#include <map>
//#include <multimap>
using namespace std;


void sort(map<string, int>& M, multimap<int, string>& MM)
{
  
    
  
    // Insert every (key-value) pairs from
    // map M to multimap MM as (value-key)
    // pairs
    for (auto it=M.begin();it!=M.end();it++) 
    {
        MM.insert(make_pair(it->second, it->first));
    }
  
   
}

int main(int argc, char* argv[])
{
	map <string, int> patstore;
	string gnome;
	string buf;
	int patternlength = atoi(argv[2]);
	ifstream ifile(argv[1]);
	while(!ifile.eof())
	{
		getline(ifile,buf,'\n');
		gnome+=buf;
	}
	for(int i=0;i<gnome.size()-(gnome.size()%patternlength);i++)
	{
		string tempstore = gnome.substr(i,patternlength);
		// if (tempstore == " 1TTTTTT ")
		// {
		// 	cout <<"found 1TTT pattern at pos " << i <<endl;
		// }
		if(patstore.find(tempstore)!=patstore.end())
		{
			patstore[tempstore]= patstore[tempstore]+1;
		}
		else
		{
			patstore.insert(pair <string,int> (tempstore,1));
		}
	}
	// if ( patstore.find(string(" 1TTTTTT "))!=patstore.end())
	// {
	// 	cout <<"found 1TTT pattern in patstore" <<endl;
	// }

	multimap<int, string> MM;
	sort(patstore, MM);


	//cout<<"\n";
	for(auto i = MM.begin();i!=MM.end();i++)
	{			
			cout<<i->second<<" "<<i->first;
			cout<<"\n";	
	}
	ifile.close();
}