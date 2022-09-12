#include<iostream>
#include<fstream>
#include <map>
using namespace std;

int hamdist(const string & s1, const string & s2)
{
	//write for if input is bad
	int d=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i])
			d+=1;
	}
	return d;
}

void sort(map<string, int>& M, multimap<int, string>& MM)
{
 
    for (auto& it : M)
    {
        MM.insert({ it.second, it.first });
    }
   
}

int main(int argc, char* argv[])
{
	const int DISTANCE = 2;
	map <string, int> patstore;
	string gnome;
	string buf;
	ifstream ifile(argv[1]);
	while(!ifile.eof())
	{

		getline(ifile,buf);
		if( buf[buf.size() -1] == '\r')
		{
			buf = buf.substr(0,buf.size() -1);
		}
		gnome+=buf;
	}
	for(int i=0;i<gnome.size()-(gnome.size()%9);i++)
	{
		//cout<<i<<"\n";
		string tempstore = gnome.substr(i,9);
		if ( tempstore.size() < 9)
		{
			continue;
			// cout <<" Substr smaller than 9: " << tempstore <<"\n";
			// cout << "pos = " <<i << "\n";
			// cout << "last i = " << gnome.size()-(gnome.size()%9) << "\n";
			// cout << "genome size = " << gnome.size() << "\n";
		}

		if(patstore.find(tempstore)==patstore.end())
		{
			// if (tempstore == "AATACCAA")
			// {
			// 	cout << "Ho Ho " << "\n";
			// 	cout << "loc = " << i << "\n";
			// }
			patstore.insert(pair <string,int> (tempstore,1));
		}

		for (auto& it : patstore) 
		{
        	//MM.insert({ it.second, it.first });
        	int ds = hamdist(it.first,tempstore);
        	if((ds >0) && (ds <=DISTANCE))
        	{
        		patstore[tempstore]= patstore[tempstore]+1;
        	}
    	}
  
		
	}
	multimap<int, string> MM;
	sort(patstore, MM);

	for(auto i = MM.begin();i!=MM.end();i++)
	{
			cout<<i->second<<" "<<i->first;
			cout<<"\n";
		
	}
	ifile.close();
	return 0;
}