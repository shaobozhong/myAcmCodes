#include <iostream> 
#include <set>
using namespace std;

long long  maps[5843]={0};
int n=1;

void prepare()
{
	std::set<long long> s;
	s.insert(1);
	std::set<long long>::iterator iter;
	while (n<5843)
	{
		iter=s.begin();
		maps[n]=*iter;
		s.erase(iter);
		s.insert(maps[n]*2);
		s.insert(maps[n]*3);
		s.insert(maps[n]*5);
		s.insert(maps[n]*7);
		++n;
	}
}

int main (int argc, char* argv[]) 
{
	prepare();
	int i=0;
	while(cin>>n,n!=0)
	{
		cout<<"The ";
		switch(n%10)
		{
		case 1:
			{
				if (n%100!=11) cout<<n<<"st humble number is ";
			   else  
				   cout<<n<<"th humble number is ";
				   break;
			}
		case 2:
			{
				if (n%100!=12) cout<<n<<"nd humble number is ";
				else cout<<n<<"th humble number is ";
				break;
			}
		case 3:
			{
				if (n%100!=13) cout<<n<<"rd humble number is ";
			   else cout<<n<<"th humble number is ";
			break;
			}
		default :cout<<n<<"th humble number is ";
		}
		cout<<maps[n]<<'.'<<endl;
	}
	
	//cout<<t2-t1<<endl;
	return 0;
}

