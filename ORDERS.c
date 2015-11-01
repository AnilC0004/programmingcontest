#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#ifdef ONLINE_JUDGE
#define gtc getchar_unlocked()
#define ptc putchar_unlocked 
#else 
#define gtc getchar()
#define ptc putchar 
#endif



int read_int()
{
	register int noRead=0,isneg=0;
	register char p=gtc;
	for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
	while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
	if(isneg) noRead = -noRead;
	return noRead;
}

//inline 
void fastWrite(int a)
{
	char snum[20];
	int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}while(a!=0);
	i=i-1;

	//puts(snum);
	while(i>=0)
		ptc(snum[i--]);
	ptc('\n');
}

//------------------------------------------------------------------------------------------------------------------------------------------------//
int BIT[200001],n,ar[200001];
void update(int i,int val)
{
	
	for(;i<=n;i += (i&-i)) {
		BIT[i] += val;
	}
}

int getval(int i)
{
	int sum = 0;
	for(; i>0 ; i -= i&-i) {
		sum += BIT[i];
	}
	return sum;
}
//simple binarysearch(relative position)
//	finding absolute position with the help of first occurence of relative position in BIT.  
//return pos(3) 0n 1222334 ret 5
int pos(int i)
{
	int first = 1,last  = n,mid;
	while(first<last) {
		mid = (first+last)>>1;
		if(getval(mid)>=i) 
			last = mid;
		else first = mid+1;
	}
	return first;
}

int main()
{
	int T,i,p;
	T = read_int();
	while(T-->0) {
		n = read_int();
		memset( BIT,0,4*(n+1) );
		
		
		for(i=1;i<=n;i++) {
			ar[i] = read_int();
			update(i,1);
		}

		for(i = n ;i > 0;i--) {
			p = i-ar[i];//position wrt current position
			ar[i]= pos(p);//absolute position
			update(ar[i],-1);//so as to remove element and not disturb the rel position of element remaning after that.
		}

		for(i=1;i<=n;i++) {
			printf("%d ", ar[i] );
		}
		printf("\n");
	}

	return 0;
	
	
}