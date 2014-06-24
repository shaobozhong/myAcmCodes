#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;


typedef struct Stuff
{
	string stuffID;
	vector<string> computers;
}Stuff;


vector<string> computers;
vector<Stuff> stuffs;
vector<bool> compuerLa;
int count_;


bool addComputer(const string &computerID)
{
	for (int i=0;i<computerID.size();++i)
	{
		if((computerID[i]<0 && computerID[i]>9) && (computerID[i]>'z' && computerID[i]<'a') && (computerID[i]>'Z' && computerID[i]<'A')) return false;
	}
	for (int i=0;i<computers.size();++i)
	{
		if(computers[i].compare(computerID)==0) return false;
	}
	computers.push_back(computerID);
	return true;
}


bool removeComputer(const string &comuterID)
{
	for (int i=0;i<computers.size();++i)
	{
		if (computers[i].compare(comuterID)==0)
		{
			computers.erase(computers.begin()+i,computers.begin()+i+1);
			return true;
		}
	}
	return false;
}


int findStuff(const string &stuffID)
{
	for (int i=0;i<stuffs.size();++i)
	{
		if (stuffs[i].stuffID.compare(stuffID)==0)
		{
			return i;
		}
	}
	return -1;
}

bool borrowComputer(const string &computerID,const string &stuffID)
{
	Stuff tmpStuff;
	if (stuffID.size()!=8)
	{
		return false;
	}
	for (int i=0;i<stuffID.size();++i)
	{
		if(stuffID[i]>'9' && stuffID[i] <'0') return false;
	}

	for (int i=0;i<computers.size();++i)
	{
		if (compuerLa[i]&&computers[i].compare(computerID)==0)
		{
			int stuffLa=findStuff(stuffID);
			if (stuffLa==-1)
			{
				tmpStuff.stuffID=stuffID;
				tmpStuff.computers.push_back(computerID);
				stuffs.push_back(tmpStuff);
			}
			else
			{
				(stuffs[stuffLa]).computers.push_back(computerID);
			}
			compuerLa[i]=false;

			count_+=1;
			return true;
		}
	}
	return false;
}


bool sendBackComputer(const string &computerID,const string &stuffID)
{
	Stuff tmpStuff;
	for (int i=0;i<stuffs.size();++i)
	{
		if (stuffs[i].stuffID.compare(stuffID)==0)
		{
			for (int j=0;j<stuffs[i].computers.size();++j)
			{
				if (((stuffs[i]).computers[j]).compare(computerID)==0)
				{
					((stuffs[i]).computers).erase(((stuffs[i]).computers).begin()+j,((stuffs[i]).computers).begin()+j+1);
					count_-=1;
					return true;
				}
			}
		}
	}
	return false;
}


bool cmp(const Stuff &a,const Stuff &b){
	return a.stuffID<b.stuffID;
}


bool cmpComputer(const string &a,const string &b)
{
	return a<b;
}
int main()
{
	int m,n,p,q;
	int i;
	count_ =0;
	cin>>m>>n>>p>>q;
	computers.clear();
	stuffs.clear();
	compuerLa.clear();

	string computerID,stuffID;
	for (i=0;i<m;++i)
	{
		cin>>computerID;
		if (!addComputer(computerID))
		{
			cout<<"add computer error:"+computerID<<endl;
		}
	}

	for (i=0;i<n;++i)
	{
		cin>>computerID;
		if (!removeComputer(computerID))
		{
			cout<<"remove computer error:"<<computerID<<endl;
		}
	}

	for (i=0;i<computers.size();++i)
	{
		compuerLa.push_back(true);
	}

	for (i=0;i<p;++i)
	{
		cin>>computerID>>stuffID;
		if (!borrowComputer(computerID,stuffID))
		{
			cout<<"assign new computer error:"<<computerID<<""<<stuffID<<endl;
		}
	}

	for (int i=0;i<q;++i)
	{
		cin>>computerID>>stuffID;
		if(!sendBackComputer(computerID,stuffID))
		{
			cout<<"send back computer error:"<<computerID<<""<<stuffID<<endl;
		}
	}

	sort(stuffs.begin(),stuffs.end(),cmp);
	cout<<count_<<endl;
	for (int i=0;i<stuffs.size();++i)
	{
		
		if (stuffs[i].computers.size()>1)
		{
			sort(stuffs[i].computers.begin(),stuffs[i].computers.end(),cmpComputer);
		}
		for (int j=0;j<stuffs[i].computers.size();++j)
		{
			cout<<stuffs[i].stuffID<<"_"<<stuffs[i].computers[j]<<endl;
		}
	}
	return 0;
}