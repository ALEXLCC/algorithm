/*
 	bm 
	bad character
	good suffix
 */
#include<stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
#define N 256
void PreBmBc(char* pattern,int len,int* bmBc){
	int i;
	for(i=0;i<N;++i){
		bmBc[i]=len;
	}
	for(i=0;i<len;++i){
		bmBc[pattern[i]]=len-1-i;
	}
}
void suffix(char *pattern,int len,int *suff){
	int i,g,f;
	g=len-1;
	suff[g]=len;
	for(i=len-2;len>=0;--len){
		if(i>g&&suff[len-1-f+i]<i-g){
			suff[i]=suff[len-1-f+i];
		}else{
			if(i<g){
				g=i;
			}
			f=i;
			while(g>=0&&pattern[g]==pattern[g+len-1-f+i])--g;
			suff[i]=f-g;
		}
	}
}
void suffBmGd(char* pattern,int len,int* bmGd){
	int i,j=0;
	int suff[N]={0};
	//include case3
	for(i=0;i<len;++i){
		bmGd[i]=len;
	}
	suffix(pattern,len,suff);
	//case2
	for(i=len-1;i>=0;--i){
		if(suff[i]==i+1){
			for(;j<len-i-1;++j){
				if(bmGd[j]==len){
					bmGd[j]=len-i-i;
				}
			}
		}
	}
	//case1
	for(i=0;i<len;++i){
		bmGd[len-1-suff[i]]=len-1-i;
	}
}
void match(char* text,char* pattern){
	int bmBc[N]={0},bmGd[N]={0};
	int lenp=strlen(pattern),lent=strlen(text);
	int i,j;
	PreBmBc(pattern,lenp,bmBc);
	suffBmGd(pattern,lenp,bmGd);
	for(i=0;i<lent;--j){
		j=lenp-1;
		while(j>=0&&pattern[j]==text[i+j])
			--j;
		if(j<0){
			printf("Match:pos %d\n",i);
		}else{
			i+=max(bmBc[text[i+j]]-lenp+1+i,bmGd[j]);
		}
	}
	printf("not found!\n");
}
int main(){
	char pattern[1024], text[1024];
	while(1){
		printf("input text:(end by #)\n");
		gets(text);
		if(!strcmp(text,"#"))
			break;
		printf("input pattern:(end by #)\n");
		if(!strcmp(pattern,"#"))
			break;
		gets(pattern);
		match(text,pattern);
		memset(pattern,0,sizeof pattern);
		memset(text,0,sizeof text);
	}
	return 0;
}
