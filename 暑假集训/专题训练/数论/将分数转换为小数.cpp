#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string s;
	vector<int>a;
	int i,Interzone,temp,count;
	int fenzi,fenmu;
	while(cin>>fenzi>>fenmu,fenzi||fenmu)
	{

		if (fenzi==0)
		{
			s.push_back('0');
			cout<<s<<endl;
			cout<<"This expansion terminates."<<endl;
			s.clear();
			continue;
		}

		Interzone=0;
		s.push_back('.');

		fenzi*=10;
		a.push_back(fenzi);
		while(fenzi<fenmu)
		{
			
			s.push_back(fenzi/fenmu+'0');
			fenzi*=10;
			a.push_back(fenzi);
		}
		
		while(1)
		{
			
			temp=fenzi/fenmu;
			s.push_back(temp+'0');
			if (fenzi%fenmu==0) break;
			else 
			{
				fenzi=fenzi%fenmu;
				fenzi*=10;
				for(i=0;i<(int)a.size();i++)
					if (a[i]==fenzi) break;
				if (i<(int)a.size()) 
				{
				    Interzone=a.size()-i;
				     break;
				}
				a.push_back(fenzi);
				
			}
		}
		count=0;
		for(i=0;i<s.size();i++)
		{
			if (count==50) {cout<<endl;count=0;}
			cout<<s[i];
			count++;
		}
		cout<<endl;
		if (Interzone!=0) cout<<"The last "<<Interzone<<" digits repeat forever."<<endl;
		else cout<<"This expansion terminates."<<endl;
		a.clear();
		s.clear();
	}
	return 0;
}