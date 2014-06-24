#include<iostream>
using namespace std;

int main(){
	double sum;
	int a[7]={10,20,50,100,100,200,500};
	double value[7]={50,20,10,5,1,0.5,0.1};
	int res[7];
	while(cin>>sum){
		for(int i=0;i<7;++i){
			int number=(int)(sum/value[i]);
			if(number>a[i]){
				number=a[i];
			}
			sum-=number*value[i];
			res[i]=number;
		}
		if(sum>=0.1){
			cout<<"the operate is fail"<<endl;
		}else{
			for(int i=0;i<6;++i){
				cout<<res[i]<<" ";
			}
			cout<<res[6]<<endl;
		}
	}
	return 0;
}