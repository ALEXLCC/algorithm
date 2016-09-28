#include<stdio.h>
#include<stdlib.h>
#define DEBUG
typedef struct _node{
	int data;
	struct _node* prev;
	struct _node* next;
}Node,*pNode;
pNode Create(){
	int da;
	pNode cur,h,head;
	if(scanf("%d",&da),da){
		head=h=cur=(pNode)malloc(sizeof(Node));
		cur->data=da;
		head->next=cur;
		cur->prev=NULL;
		cur->next=NULL;
	}else{
		return NULL;
	}
	while(scanf("%d",&da),da){
		cur=(pNode)malloc(sizeof(Node));
		cur->data=da;
		h->next=cur;
		cur->prev=h;
		cur->next=NULL;
		h=cur;
	}
	return head;
}
void show(pNode head){
	pNode h=head;
	while(h){
		printf("%d ",h->data);
#ifdef DEBUG
		printf("prev=0x%p,cur=0x%p,next=0x%p\n",h->prev,h,h->next);
#endif
		h=h->next;
	}
	printf("\n");
}
void showR(pNode head){
	pNode h=head;
	while(h->next)
		h=h->next;
	while(h){
		printf("%d ",h->data);
#ifdef DEBUG
		printf("prev=0x%p,cur=0x%p,next=0x%p\n",h->prev,h,h->next);
#endif
		h=h->prev;
	}
	printf("\n");
}
int main(){
	pNode head=Create();
	show(head);
	showR(head);
	return 0;
}
