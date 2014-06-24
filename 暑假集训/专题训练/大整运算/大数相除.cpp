#include<iostream>
#include<string>
using namespace std;

void work(string &dividend1,string &divisor1)//除数整数化
{
	int i,sorlen,dendlen,time=0;
	char temp;
	bool pot=false;
	sorlen=divisor1.size();
	dendlen=dividend1.size();
	for(i=0;i<=sorlen-1;i++)
	{
		if (divisor1[i]=='.') break;
	}
	if (i!=sorlen) divisor1.erase(i,1);
	i++;
	for(;i<=sorlen-1;i++)
	{
		time++;
	}
	i=0;
	while(divisor1[i]=='0')
	{
		divisor1.erase(0,1);
		i++;
	}
	for(i=0;i<=dendlen-1;i++)
	{
		if (dividend1[i]=='.') 
		{	
			pot=true;

			break;

		}
	}
	for(;i<dendlen-1&&time;i++)
	{
		temp=dividend1[i];
		dividend1[i]=dividend1[i+1];
		dividend1[i+1]=temp;
		time--;
	}
	if (pot) 
	{
		//if (0==time&&i!=dendlen-1) dividend1[i+1]='.';
		if (i==dendlen-1) dividend1.erase(i,1);
	}
	while(time>0)
	{
		dividend1.insert(dividend1.end(),'0');
		time--;
	}
	/*i=dividend1.size()-1;
	while((dividend1[i]=='0')||dividend1[i]=='.')
	{
		
		if (dividend1[i]=='.')
		{
			dividend1.erase(i,1); 
			break;
		}
		dividend1.erase(i,1);
		i--;
	}*/
}

void minu(string &end,string divisior)
{
	int i,j,l;
	int k,endlen=end.size(),sorlen=divisior.size();
	for(i=endlen-1,j=sorlen-1;i>=0&&j>=0;i--,j--)
	{
		if(end[i]>=divisior[j]) end[i]=end[i]-divisior[j]+'0';
		else 
		{
			k=i;
			while(end[k-1]-1<'0')
			{
				k--;
			} 
			for(l=k;l<=i-1;l++)
				end[l]+=9;
			end[k-1]--;

			end[i]+=10;
			end[i]=end[i]-divisior[j]+'0';
		}
	}
	for(i=0;i<=endlen-1;i++)
	{
		if (end[0]!='0') break;
		end.erase(0,1);
	}
}


void division1(string &dividend1,string &divisor1,string &result)
{
	char fh;
	int sorlen,i,weishu=0,max,sorlen1,last;
	int dendlen,dendlen1,count;
	bool pot=true;
	string end;
	sorlen=divisor1.size();
	dendlen=dividend1.size();
	sorlen1=sorlen;
	dendlen1=dendlen;
	for(i=0;i<=sorlen-1;i++)
	{
		if (divisor1[i]=='.') {sorlen1--;break;}
	}
	for(i=0;i<=dendlen-1;i++)
	{
		if (dividend1[i]=='.') {dendlen1--;break;}
	}
	result="";
	fh=0;
	if (dividend1[0]=='-') 
	{
		fh='-';
		dividend1.erase(0,1);
		dendlen1--;
	}
	if (divisor1[0]=='-')
	{
		if (fh=='-') fh=0;
		else fh='-';
		divisor1.erase(0,1);
		sorlen1--;
	}
	for(i=0;i<=divisor1.size();i++)
	{
       if (divisor1[i]=='0') sorlen1--;
	   else break;
	}
	for(i=0;i<=dividend1.size();i++)
	{
		if (dividend1[i]=='0') dendlen1--;
		else break;
	}
	
	max=sorlen1;
	if (max<dendlen1) max=dendlen1;

	work(dividend1,divisor1);


	sorlen=divisor1.size();
	dendlen=dividend1.size();

	i=0;
	while((((int)end.size()==sorlen&&end<divisor1)||end.size()<sorlen)&&i<=dendlen-1)
	{
		if (dividend1[i]=='.') 
		{
			i++;
			result.append("0.");
			pot=false;
		}
		end.insert(end.end(),dividend1[i]);
		i++;
	}
	while(end[0]=='0')
	{
		end.erase(0,1);
	}
	if(((int)end.size()==sorlen&&end<divisor1)||end.size()<sorlen) 
	{
		if  (pot) result.append("0.");
		
		
		else {

			result.insert(result.end(),'0');
			if (!pot) weishu++;
		      }
		pot=false;
	}
	count=0;
	while(((int)end.size()==sorlen&&end<divisor1)||end.size()<sorlen)
	{
      end.insert(end.end(),'0');
	  if (count>0) {result.insert(result.end(),'0');if (!pot) weishu++;}
	  count++;
	}
	i--;
	dendlen1=(int)end.size();
	for(;i<=dendlen-1;i++)
	{
		
		//dendlen1=(int)end.size();
		if ((dendlen1==sorlen&&end>=divisor1)||dendlen1>sorlen)  
		{
			count=0;
			while((dendlen1==sorlen&&end>=divisor1)||dendlen1>sorlen)
			{
				minu(end,divisor1);
				count++;
				dendlen1=end.size();
			}
			result.insert(result.end(),count+'0');
			if (!pot) weishu++;
			if (weishu>max) 
			{
				last=result.size()-1;
				result.erase(last,1);
				if (count>=5) 
				{
					count=result.size()-1;

					while(result[count]=='9')
					{
						count--;
						result.erase(count,1);
					}
					result[count]++;

				}
				return;
			}
		}
		if (i==dendlen-1) break;
		if(dividend1[i+1]=='.')  
		{
			result.insert(result.end(),'.');
			pot=false;
			i++;
		}
		end.insert(end.end(),dividend1[i+1]);
		dendlen1=end.size();
		if(dendlen1==sorlen&&end<divisor1||dendlen1<sorlen) {result.insert(result.end(),'0');if (!pot) weishu++;}
		if (end[0]=='0') end.erase(0,1);
	}
	i++;
	if (pot) {result.insert(result.end(),'.');pot=false;}
	while(end!="" && weishu<=max)
	{
		end.insert(end.end(),'0'); 
		dendlen1=(int)end.size();
		if ((dendlen1==sorlen&&end<divisor1)||dendlen1<sorlen) 
		{
		result.insert(result.end(),'0');
		weishu++;
		count=result.size()-1;
		if (weishu>max) 
		{
			result.erase(count,1);
			return;
		}
		}
		if ((dendlen1==sorlen&&end>=divisor1)||dendlen1>sorlen)  
		{
			count=0;
			while((dendlen1==sorlen&&end>=divisor1)||dendlen1>sorlen)
			{
				minu(end,divisor1);
				count++;
				dendlen1=end.size();
			}
			result.insert(result.end(),count+'0');
			if (!pot) weishu++;
			if (weishu>max) 
			{
				last=result.size()-1;
				result.erase(last,1);
				if (count>=5) 
				{
					count=result.size()-1;

					while(result[count]=='9')
					{
						count--;
						result.erase(count,1);
					}
					result[count]++;

				}
				return;
			}
			
		}
		if(end[0]=='0') {end.erase(0,1);result.insert(result.end(),'0');}

	}
	if (pot) result.insert(result.end(),'.');
	if (fh=='-') cout<<fh;
	while(weishu<max)
	{
		result.insert(result.end(),'0');
		weishu++;
	}
	i=result.size()-1;
	while((result[i]=='0'||result[i]=='.'))
	{
		
		if (result[i]=='.')
		{
			result.erase(i,1); 
			break;
		}
		result.erase(i,1);
		i--;
	}
}

int main()
{

	string s,t,result;
	while(cin>>s>>t)
	{
		if (s=="0") cout<<"0"<<endl;
		else
		{
		division1(s,t,result);
		cout<<result<<endl;
		}
	}
	return 0;
}