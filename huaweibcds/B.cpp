#include<iostream>
using namespace std;

int main(){
	unsigned int num;
	unsigned int a,b,c,d;
	while(cin>>num){
		a=(num&0xff000000)>>24;
		b=(num&0x00ff0000)>>16;
		c=(num&0x0000ff00)>>8;
		d=num&0x000000ff;
		cout<<a<<"."<<b<<"."<<c<<"."<<d<<endl;
	}
	return 0;
}