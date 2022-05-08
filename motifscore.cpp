#include<iostream>
#include<vector>
using namepsace std;
string consenstr(string* m , int n)
{
	vector <int> arr(4,0);
	for(int i=0;i<m[0].size();i++)
	{
		for(int j =0;j< n;j++)
		{
			if(m[j][i]=='a')
			{
				arr[0]++;
			}
			else if(m[j][i]=='t')
			{
				arr[1]++;
			}
			else if(m[j][i]=='g')
			{
				arr[2]++;
			}
			else if(m[j][i]=='c')
			{
				arr[3]++;
			}
			int maxe = max_element(arr.begin(),arr.end()) - arr.begin();

		}
	}
}
int motsc(string* m , int n)
{

}
int main(int argc, char* argv[])
{
	//string gnome;
	int nmotifs = 0;
	string* motifs;
	string buf;
	ifstream ifile(argv[1]);
	int nlines =0;
	while(!ifile.eof())
	{
		getline(ifile,buf,'\n');
		if(nlines == 0)
		{
			nmotifs = atoi(buf);
			motifs = new string[nmotifs];
		}
		nlines++;
	}
	ifile.close();
	delete [] motifs;
}