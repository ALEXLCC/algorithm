#include<stdio.h>
#define N 100
#define MAX_INDEX 50
#define BASE 10		/*base number*/
typedef struct{
	int index[MAX_INDEX];
	int next;
}Bucket;
void init(int* arr,int* len){
	int i=0;
	scanf("%d",len);
	while(scanf("%d",arr+i),++i<*len);
}
void show(int* arr,int len){
	int i=0;
	for(i=0;i<len;++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void sort(int* arr,int len){
	int i,max=arr[0],j=0;
	int exp=1;
	for(i=1;i<len;++i){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	while(max/exp){
		int f[N]={0};//
		int bucket[BASE]={0};
		bucket[-1]=0;
		for(i=0;i<len;j=0,++i){
			++bucket[arr[i]/exp%BASE];
		}
		for(i=1;i<BASE;++i){
			bucket[i]+=bucket[i-1];
		}
		for(i=0;i<len;++i){
	/*		if(0==arr[i]/exp%BASE){
				for(j=0;j<bucket[0];++j){
					if(!f[j]){
					f[j]=arr[i];
					break;
					}
				}
			}else{	*/
				for(j=bucket[arr[i]/exp%BASE-1];
				j<bucket[arr[i]/exp%BASE];++j){
				if(!f[j]){
				f[j]=arr[i];
				break;
				}
				}
		//	}
		}
		for(i=0;i<len;++i){
			arr[i]=f[i];
		}
		show(arr,len);
		exp*=10;
	}
}
int main(){
//	int arr[10]={278,109,63,930,589,184,505,269,8,83};
	int arr[N],len;
	init(arr,&len);
	sort(arr,len);
	printf("\n");
	show(arr,10);
	return 0;
}
