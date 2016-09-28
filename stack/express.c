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
	int i=0,j,k,point=0;
	double d,df,a,b;
	char o;
	while(op[i]!='#'||GetTopC(pstac)!='#'){
		if(op[i]>='0'&&op[i]<='9'||'.'==op[i]){
			k=i;
			j=0;
			while(op[i]>='0'&&op[i]<='9'||'.'==op[i]){
				if('.'==op[i]){
					j=i;
					point=1;
				}
				++i;
			}
			d=0.0;
			if(point){
				for(;k<j;++k){
					d=d*10+op[k]-'0';
				}
				point=0;
				df=0.0;
				for(k=i-1;j<k;--k){
					df=df/10+(op[k]-'0');
				}
				df/=10;
				d+=df;
			}else{
				for(;k<i;++k){
					d=d*10+op[k]-'0';
				}
			}
			PushD(pstad,d);
		}else{
			switch(Precede(GetTopC(pstac),op[i])){
				case '<':
					PushC(pstac,op[i]);
					++i;
					break;
				case '=':
					PopC(pstac);
					++i;
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
	char ops[128];
	pStackC pstac=(pStackC)malloc(sizeof(StackC));
	pStackD pstad=(pStackD)malloc(sizeof(StackD));
	while(1){
		gets(ops);
		if('#'==ops[0]){
			break;
		}
		if(JudgeFlag(ops)){
			printf("expression parentheses error!\n");
			return -1;
		}
		InitStackC(pstac);
		InitStackD(pstad);
		printf("result=%lf\n",EvaluateExpression(ops,pstac,pstad));
	}
	return 0;
}
