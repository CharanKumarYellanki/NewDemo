#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define MAX 1000
struct MyData{
	int A[MAX];
};
int DA[MAX][MAX]={-1};
int cnt=-1;
int* convertNumToArray(int n){
	
	cnt++;
	int i=0;
	while(n>0){
		DA[cnt][i]=n%10;
		n=n/10;
		i++;
	}
	DA[cnt][i]=-1;
	
	return DA[cnt];
}
int a1[MAX]={-1};
int* multiplyTwoDigitArrays(int p[], int q[]){
	memset(a1,-1,MAX);
	int b1[MAX]={-1};
	int cnt=0;
	
	int *a=p;
	int *b=q;
	
	
	int j,n;
	for(int i=0;a[i]!=-1;i++){
		int x=0;
		for(j=0;b[j]!=-1;j++){
			n=b[j]*a[i]+x;
			b1[j]=n%10;
			x=n/10;
			
		}
		while(x>0)
		{
			b1[j++]=x%10;
			x=x/10;
		}
		b1[j]=-1;
			
			
		
		int y=0,value;
		int k,z;
		for(k=cnt,z=0;b1[z]!=-1;k++,z++)
		{
			if(cnt==0)
			a1[z]=b1[z];
			else{
				if(a1[k]==-1){
					value=b1[z]+y;
					a1[k]=value%10;
					y=value/10;
				}
				else{

						value=a1[k]+b1[z]+y;
						a1[k]=value%10;
						y=value/10; 
					}
			}
			
		}
		
		while(y>0){
		a1[k++]=y%10;
		y=y/10;
	}
		a1[k]=-1;
		cnt++;
		
	}
	
	return a1;
}
	int tempArray[MAX][MAX];
			int *temp; 
			int cnt1=0;
int* fact(int n){
		
		tempArray[cnt1][0]=1;
		tempArray[cnt1][1]=-1;
		temp=tempArray[cnt1];
	
	for(int i=2;i<=n;i++){
		
		temp=multiplyTwoDigitArrays(temp,convertNumToArray(i));
		int j;
			for(j=0;temp[j]!=-1;j++)
			tempArray[cnt1][j]=temp[j];
			tempArray[cnt1][j]=-1;
			temp=tempArray[cnt1];
	}
	temp=tempArray[cnt1];
	cnt1++;
	
	return temp;
}
long double d1=0, d2=0;
long double division(int p[],int q[]){
	d1=0,d2=0;
	int *a=new int[MAX];
	int *b=new int[MAX];
	a=p;
	b=q;
	for(int i=0;a[i]!=-1;i++){
		d1+=pow(10,i)*a[i];
	}
	//cout<<" \n\nvalue of d1 is :"<<d1;
	for(int j=0;b[j]!=-1;j++){
		d2+= pow(10,j)*b[j];
	}
	//cout<<"\n\n value of d2 is :"<< d2;
	return d1/d2;
}
long double combination(int n, int r){
	
	

	int *q=fact(n);

	
		int *x=fact(n-r);


	int *y=fact(r);
	int *p=multiplyTwoDigitArrays(x,y);
	
	return division(q, p);
}

long double probability(int n,int r, double p){
	long double sum=0;
	if(r<=n/2){
	for(int i=0;i<r;i++){
	 sum=sum+combination(n,i)*pow(p,i)*pow(1-p,n-i);
	 //cout<<"\n combination( "<<n<<", "<<i<<" ): "<<combination(n,i)<<endl;
	}
	return 1-sum;
	}
	else{
		for(int i=r;i<=n;i++){
			sum=sum+combination(n,i)*pow(p,i)*pow(1-p,n-i);
			
		}
		return sum;
	}
}


int main(){
	int n,r;
	double prob;
	double bandOfWire, bandRequired;
	
	cout<<"\n\n Enter bandwidth of the link:";
	cin>>bandOfWire;
	
	cout<<"\n Enter the bandwidth requirement of the user:";
	cin>>bandRequired;	

	cout<<"\n Enter Total number of users:\n";
	cin>>n;
	
	cout<<"\nenter probability of the idle state: ";
	cin>>prob;
	
	X:
	cout<<"\n Enter target number of users: \n";
	cin>>r;
	
	if(r>n){
		cout<<"\n please enter a number less than: "<<n<<endl;
		goto X;
		}
	
	prob=1-prob;
	
	cout<<endl<<endl;
	
	cout<<"\n probability of "<<r <<" or more users active at the same time is :"<<probability(n,r,prob)<<endl<<endl;
	return 0;
}
