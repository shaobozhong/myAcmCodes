#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string>S;
set<string>::iterator p;
int main()
{
    string str,str1,str2;
    S.clear();
    int len,i;
    while(cin>>str)
        S.insert(str);
    for(p=S.begin();p!=S.end();p++)
    {
        str=*p;
        len=str.length();
        for(i=1;i<len;i++)
        {
            str1=str.substr(0,i);
            str2=str.substr(i,len-i);
            if(S.find(str1)!=S.end()&&S.find(str2)!=S.end())
            {
                cout<<str<<endl;
                break;
            }
        }
    }
    return 0;
} 