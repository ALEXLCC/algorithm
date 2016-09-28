#include<stdio.h>
#define EMP "()"
#define N 100
typedef enum{
	ATOM,
	LIST
}ElemTag;
typedef char AtomType;
typedef struct GLNode{
	ElemTag tag;
	union{
		AtomType atom;
		struct{
			struct GLNode* hp,*tp;
		}ptr;
	};
}GList,*pGList;
void substr(char* sub,char* str,int s,int t){
	int i=0;
	while(s<=t){
		sub[i++]=str[s];
		++s;
	}
}
void clearstring(char* str){
	char* pc=str;
	while(*p){
		*p++=0;
	}
}
void serve(char* str,char* hstr){
	int n=strlen(str);	
	int i=1,k=0;
	char ch=' ';
	for(;i<=n&&ch!=','||k!=0;++i){
		substr(ch,str,i,1);
		if(')'==ch){
			++k;
		}else if('('==ch){
			--k;
		}
	}
	if(i<=n){
		substr(hstr,str,1,i-2);
		substr(str,str,i,n-i+1);
	}else{
		strcpy(hstr,str);
		clearstring(str);
	}
}
void CreateList(pGList l,const char* str){
	if(!strcmp(str,EMP)){
		*l=NULL;
	}else{
		if(!(l=(pGList)malloc(sizeof(GList)))){
			printf("memory allocate failed!\n");
			exit(-1);
		}
		if(1==strlen(str)){
			l->tag=ATOM;
			l->atom=str;
		}else{
			pGList p=l,q;
			char *sub=(char*)malloc(N*sizeof(char))
			l->tag=LIST;
			substr(sub,str,2,strlen(str)-2);
			do{
				serve(sub,hsub);
				CreateGList(p->p.hp,hsub);
				q=p;
				if(strlen(sub)){
					if(!(p=(pGList)malloc(sizeof(GLNode)))){
						exit(-1);
					}
					p->tag=LIST;
					q->p.tp=p;
				}
			}while(strlen(sub));
			free(sub);
		}
	}
}
int main(){
	pGList list=(pGList)malloc(sizeof(GList));
	return 0;
}
