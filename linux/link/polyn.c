#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int coe;
	int exp;
	struct _node* next;
}Node,*pNode;
pNode Create(){
	pNode head,h,cur;
	int c,e;
	if(scanf("%d%d",&c,&e),e!=-1){
		head=h=cur=(pNode)malloc(sizeof(Node));
		cur->coe=c;
		cur->exp=e;
		h->next=NULL;
	}else{
		return NULL;
	}
	while(scanf("%d%d",&c,&e),e!=-1){
		cur=(pNode)malloc(sizeof(Node));
		cur->coe=c;
		cur->exp=e;
		h->next=cur;
		h=cur;
	}
	return head;
}
void show(pNode head){
	pNode h=head;
	while(h){
		if(!h->exp){
			if(h->coe>=0){
				printf("+%d",h->coe);
			}else{
				printf("%d",h->coe);
			}
		}else{
			if(h->coe>=0){
				printf("+%dX%d",h->coe,h->exp);
			}else{
				printf("%dX%d",h->coe,h->exp);
			}
		}
		h=h->next;
	}
	printf("\n");
}
void Calculate(pNode expr1,pNode expr2){
	
}
int main(){
	pNode head=Create();
	show(head);
	return 0;
}
