#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct _stackC{
	char* top;
	char* bottom;
	char* stack;
}StackC,*pStackC;
typedef struct _stackD{
	double* top;
	double* bottom;
	double* stack;
}StackD,*pStackD;
char op[7]={'+','-','*','/','(',')','#'};
char order[7][7]={
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=',' '},
	{'>','>','>','>',' ','>','>'},
	{'<','<','<','<','<',' ','='},
};
void InitStackC(pStackC psta){
	int i=1;
	psta->stack=(char*)malloc(N);
	psta->stack[0]='#';
	for(i=1;i<N;++i){
		psta->stack[i]=0;
	}
	psta->bottom=psta->top=psta->stack;
}
char PopC(pStackC psta){
	--psta->top;
	return *(psta->top+1);
}
void PushC(pStackC psta,char c){
	++psta->top;
	*psta->top=c;
}
char GetTopC(pStackC psta){
	return *psta->top;
}
void InitStackD(pStackD psta){
	int i=0;
	psta->stack=(double*)malloc(N*sizeof(double));
	for(i=0;i<N;++i){
		psta->stack[i]=0.0;
	}
	psta->bottom=psta->top=psta->stack;
}
double PopD(pStackD psta){
	--psta->top;
	return *(psta->top+1);
}
void PushD(pStackD psta,double c){	
	++psta->top;
	*psta->top=c;
}
double GetTopD(pStackD psta){
	return *psta->top;
}
int Find(char c){
	int i=0;
	for(;i<7;++i){
		if(op[i]==c){
			return i;
		}
	}
	return -1;
}
char Precede(char a,char b){
	int i=Find(a);	
	int j=Find(b);	
	return order[i][j];
}
int JudgeFlag(char* op){
	int i=0,flag=0;
	for(;op[i]!='#';++i){
		if('('==op[i]){
			++flag;
		}else if(')'==op[i]){
			--flag;
		}
	}
	return flag;
}
double Calculate(double a,char o,double b){
	switch(o){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
	return 0.0;
}
double EvaluateExpression(char* op,pStackC pstac,pStackD pstad){
	double a,b;
	char o,c=getchar();
	while(c!='#'||GetTopC(pstac)!='#'){
		if(c>='0'&&c<='9'||'.'==c){				
			PushD(pstad,c-'0');
			c=getchar();
		}else{
			switch(Precede(GetTopC(pstac),c)){
				case '<':
					PushC(pstac,c);
					c=getchar();
					break;
				case '=':
					PopC(pstac);
					c=getchar();
					break;
				case '>':
					o=PopC(pstac);
					a=PopD(pstad);
					b=PopD(pstad);
					PushD(pstad,Calculate(b,o,a));
					break;
				}
		}
	}
	return GetTopD(pstad);
}
int main(){
//	char op[128];
	pStackC pstac=(pStackC)malloc(sizeof(StackC));
	pStackD pstad=(pStackD)malloc(sizeof(StackD));
//	gets(op);
//	if(JudgeFlag(op)){
//		return -1;
//	}
	InitStackC(pstac);
	InitStackD(pstad);
//	PushD(pstad,2);	
//	PushD(pstad,4);
//	printf("%lf\n",GetTopD(pstad));
	printf("\n\n%lf\n",EvaluateExpression(op,pstac,pstad));
	return 0;
}
