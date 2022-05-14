#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void findpat(const string &gnome, vector<int> &patposarr, const string &pat)
{
	bool flag = false;
	for (int i = 0; i < gnome.length(); i++)
	 {
		if (gnome.substr(i, pat.length()) == pat)
		 {
			//cout << i << " ";
			patposarr.push_back(i);
			flag = true;
		}
	}

	if (flag == false)
	{
		return;
		//cout << "NONE";
	}
	return;
}

int main(int argc, char* argv[])
{
	string gnome;
	string buf;
	ifstream ifile(argv[1]);
	while(!ifile.eof())
	{
		getline(ifile,buf,'\n');
		gnome+=buf;
	}
	//cout <<"the gennome is " << gnome <<"\n";
	cout <<"the length of gnome is " <<gnome.size() <<"\n";
	vector<int> patarr;
	//string revgnome=revcomp(gnome);
	findpat(gnome, patarr, argv[2]);
	//cout<<revgnome<<"\n";
	cout<<"number of occurances of the pattern was = "<<patarr.size();
	cout<<"the positions are: ";
	for(auto i=patarr.begin(); i !=patarr.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<"\n";
	ifile.close();
	return 0;
}

