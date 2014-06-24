#include<iostream>
#include<queue>
//#include<vector>
#include<algorithm>
using namespace std;



int main(){
	int num,n,i,a;
 	priority_queue<int> plank; 
	/*vector <int> v;
	//make_heap(v.begin(),v.end(),cmp);//通过更改cmp   到 return a>b  就变成了最小堆
	//v.front();
	//pop_heap(v)
		v.pop_back();*/
	//__int64 mo;
	__int64 mo;
	while(scanf("%d",&n)!=EOF){
		mo=0;
		while(n--){
			scanf("%d",&num);
			plank.push(-num);
		}
		while(plank.size()!=1){
		a=plank.top();
		plank.pop();
		a+=plank.top();
		mo+=a;
		plank.pop();
		plank.push(a);
		}
		plank.pop();
		//printf("%I64d\n",-mo);
		printf("%I64d\n",-mo);
	}
    
	return 0;
}