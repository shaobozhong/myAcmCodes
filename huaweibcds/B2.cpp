#include<iostream>
#include<vector>
using namespace std;


typedef struct Position{
	int x,y;
}Position;

int **arr;
int m,n;

vector<Position> getArea(const Position &p){

	vector<Position> res;
	res.push_back(p);
	for(int i=p.x+1;i<m;++i){//об
		if(arr[i][p.y]!=0){
			break;
		}
		Position tmpPos;
		tmpPos.x=i;
		tmpPos.y=p.y;
		res.push_back(tmpPos);
	}

	for(int i=p.x-1;i>=0;--i){//ио
		if(arr[i][p.y]!=0){
			break;
		}
		Position tmpPos;
		tmpPos.x=i;
		tmpPos.y=p.y;
		res.push_back(tmpPos);
	}


	for(int i=p.y-1;i>=0;--i){//вС
		if(arr[p.x][i]!=0){
			break;
		}
		Position tmpPos;
		tmpPos.x=p.x;
		tmpPos.y=i;
		res.push_back(tmpPos);
	}

	for(int i=p.y+1;i<n;++i){//ср
		if(arr[p.x][i]!=0){
			break;
		}
		Position tmpPos;
		tmpPos.x=p.x;
		tmpPos.y=i;
		res.push_back(tmpPos);
	}

	return res;

}





int find(const Position &key,const vector<Position> from){
	for(int i=0;i<from.size();++i){
		if(key.x==from[i].x&&key.y==from[i].y){
			return i;
		}
	}
	return -1;
}


int getAbs(int x,int y){
	int res;
	if (x>y) res= x-y;
	else res=y-x;
	if(res!=0) return res-1;
	return 0;
}


bool judge(const Position &a,const Position &b)
{
	int start,end;
	if (a.x==b.x)
	{
		start=a.y<b.y?a.y:b.y;
		end=a.y>b.y?a.y:b.y;
		for (int i=start+1;i<end;++i)
		{
			if (arr[a.x][i]!=0)
			{
				return false;
			}
		}
	}
	else
	{
		start=a.x<b.x?a.x:b.x;
		end=a.x>b.x?a.x:b.x;
		for (int i=start+1;i<end;++i)
		{
			if (arr[i][a.y]!=0)
			{
				return false;
			}
		}
	}
	return true;
}


int main(){


	Position A,B;
	vector<Position> aP,bP;
	int res;
	while(scanf("%d,%d",&m,&n)!=EOF){
		res=0;
		arr=new int*[m];
		for(int i=0;i<m;++i){
			arr[i]=new int[n];
		}

		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				scanf(",%d",&arr[i][j]);
			}
		}
		scanf(",%d,%d",&A.x,&A.y);
		scanf(",%d,%d",&B.x,&B.y);
		aP=getArea(A);
		bP=getArea(B);
		if(arr[A.x][A.y]!=arr[B.x][B.y]){
			printf("0\n");
			continue;
		}
		bool ok=false;

		if(A.x+1==B.x && A.y==B.y  || A.x-1==B.x && A.y==B.y || A.x==B.x && A.y+1==B.y || A.x==B.x && A.y-1==B.y){
			ok=true;
			res=2;
		}
		if (!ok){
			for (int i=0;i<aP.size();++i)
			{
				int la=find(aP[i],bP);
				if (la!=-1){
					res+=getAbs(aP[i].x,A.x);
					res+=getAbs(aP[i].y,A.y);
					res+=getAbs(aP[i].x,B.x);
					res+=getAbs(aP[i].y,B.y);
					if (aP[i].x==A.x && aP[i].y==A.y ||  aP[i].x==B.x && aP[i].y==B.y){
						res+=2;
					}else{
						res+=3;
					}
					ok=true;
					break;
				}
			}
		}

		if(!ok){
			for (int i=0;i<aP.size();++i){
				Position pb;
				if(aP[i].x==A.x){
					pb.y=aP[i].y;
					pb.x=B.x;
					
					if (!judge(aP[i],pb))
					{
						continue;
					}
					if (!judge(pb,B))
					{
						continue;
					}
					int la=find(pb,bP);
					if(la!=-1){
						ok=true;
						res+=getAbs(A.y,aP[i].y);
						res+=getAbs(aP[i].x,pb.x);
						res+=getAbs(pb.y,B.y);
						res+=4;
					}
				}else{
					
					pb.x=aP[i].x;
					pb.y=B.y;
					if (!judge(aP[i],pb))
					{
						continue;
					}
					if (!judge(pb,B))
					{
						continue;
					}
					int la=find(pb,bP);
					if(la!=-1){
						ok=true;
						res+=getAbs(A.x,aP[i].x);
						res+=getAbs(aP[i].y,pb.y);
						res+=getAbs(pb.x,B.x);
						res+=4;
					}
				}

			}
		}

		if(!ok){
			printf("0\n");
		}else{
			printf("%d\n",res);
		}
	}
	return 0;
}