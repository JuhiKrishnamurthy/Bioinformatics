#include<iostream>
#include <map>
#include<fstream>
using namespace std;

struct count_and_flag
{
	int count;
	int flag;
	count_and_flag()
	{
		count =0;
		flag =0;
	}
	count_and_flag(int c, int f)
	{
		count = c;
		flag = f;
	}
	count_and_flag(const count_and_flag& c)
	{
		count = c.count;
		flag = c.flag;
	}

};

// unused, old class, just there to learn how to make user defined key class
struct strandflg{
	string gene;
	int flag;
	strandflg()
	{
		gene="";
		flag = 0;
	}
	strandflg (const strandflg& x)
	{
		gene = x.gene;
		flag = x.flag;
	}

	bool operator < (const strandflg& x) const
	{
		return (gene < x.gene);
	}
	bool operator == (const strandflg& x) const
	{
		return ((gene == x.gene) && (flag == x.flag));
	}
};

int doesexist(const map<string,count_and_flag>& m, const string& g)
{
    if (m.find(g) == m.end())
    {
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[])
{
	string genome;//(1000,0);
	ifstream ifile(argv[1]);
	getline(ifile,genome);
	int k;
	int L;
	int t;
	ifile>>k;
	ifile>>L;
	ifile>>t;

	//DEBUG:
	cout <<genome <<"\n";
	cout <<"genome size = " << genome.size() <<"\n";
	cout <<"k = " << k <<"\n";
	cout <<"L = " <<L <<"\n";
	cout <<"t = " <<t << "\n";

	//map<string,count_and_flag> MAP;
	map<string,bool> kmer_printed;
	for(int i=0;i<(genome.size()-L);i++)
	{
		//DEBUG
		//cout <<"i = "<< i <<"\n";
		map<string,int> MAP;
		for(int j=i;j<i+L;j++)
		{
			//DEBUG
			//cout <<" j = " <<j << " ";

			string temp = genome.substr(j,k);
			if (temp.size() != k)
			{
				//cout<<"BAD kmer " <<temp <<" i = " <<i <<" j = "<<j <<"\n";
				continue;
			}
			//if(doesexist(MAP,temp)==1)
			if(MAP.find(temp) != MAP.end())
			{
				MAP[temp]++; 
			}
			else
			{
				//count_and_flag c(1,0);
				//MAP.insert(pair<string,count_and_flag>(temp,c));
				MAP.insert(pair<string,int>(temp,1));
			}	
		}
		
		for(auto iter = MAP.begin();iter!=MAP.end();iter++)
		{
			//cout <<"i= " << i << " kmer = " <<iter->first << " count = " <<iter->second << "\n";
			if(iter->second >= t)
			{
				if (kmer_printed.find(iter->first) == kmer_printed.end() )
				{
					cout<<iter->first <<" ";
					kmer_printed.insert(pair<string,bool>(iter->first,true));
					//iter->second.flag++;
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
	}
	ifile.close();
	cout<<"\n";
	return 0;
}


	/*
	strategy: 
	1) get genome, create a flag array. set all flags = 0, make a MAP<string,int>
	2) make loop i=0;i<genome.size-L;i++
	3) look at every k-length word, add to map and increase counter
	4) if any word occurs >= t times, check(flag!=1) print it, flag it = 1
	5) iterate over next L characters.
	6)go to step 2


	3rd step elaboration:
	make loop for (j=i;j<i+L;j++)
	if(genome.substr(j,k) exists in map)
	{
		increment its counter value by 1
		MAP[genome.substr(j,k)]++;
	}
	else
	{
		MAP.insert(genome.substr(j,k) ,1);
	}

	4th step elaboration:
	if(Map[genome.substr(j,k)]>=t)
	{
		if(corresponding flag of genome.substr(j,k)==0)
		{
			cout<< genome.substr(j,k);
			corresponding flag of genome.substr(j,k)++;
		}
		else
		{
			continue;
		}
	}


	*/
