/*
 *	a simple test for 2 road sort
 *	
 * */
#include<stdio.h>
#define N 100
void init(int * r,int* n){
	/*
	 *	n length
	 *	r address of the array
	 * */
	int i=1;
	scanf("%d",n);
	while(scanf("%d",r+i),i++<*n);
	for(;i<N+1;++i){
		r[i]=0;
	}
}
void show(int *r,int n){
	int i=1;
	for(;i<n+1;++i){
		printf("%d ",r[i]);
	}
	printf("\n");
}
void sort(int* r,int n){
	int d[n+1];
	int i=2,j=0,k=0;
	int *first,*final,*cur;
	d[1]=r[1];
	final=first=d+1;
	for(i=2;i<n+1;++i){
		d[0]=r[i];
		if(d[0]<d[1]){
			if(d+1==first){
				first=d+n;
				*first=d[0];
			}else{
				for(j=0;j+first<=d+n;++j){
					if(*(first+j)>d[0]){
						break;
					}
				}
						--first;
				for(k=0;k<j;++k){
					*(first+k)=*(first+k+1);
				}
				*(first+j)=d[0];
			}
		}else{
			for(j=0;j+d+1<=final;++j){
				if(*(j+d+1)>d[0]){
					break;
				}
			}
					++final;
			for(k=0;k<final-d-1-j;++k){
				*(final-k)=*(final-k-1);
			}
			*(final-k)=d[0];
		}
	}
	//assign 
	for(i=0;i<n;++i){
		if(first+i>d+n){
			printf("%d ",*(first+i-n));
		}else{
			printf("%d ",*(first+i));
		}
	}
	printf("\n");
	cur=first;
	for(i=0;i<n;++i){
		if(first+i>d+n){
			r[i+1]=*(first+i-n);
		}else{
			r[i+1]=*(first+i);
		}
	}
}
int main(void){
	int n;
	int r[N+1];
	init(r,&n);
	sort(r,n);
	show(r,n);
	return 0;
}
