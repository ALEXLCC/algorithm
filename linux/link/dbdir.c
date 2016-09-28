#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int data;
	struct _node* prev;
	struct _node* next;
}Node,*pNode;
typedef struct {
	pNode head;
	pNode tail;
}DBlink,*pDBlink;
void Create(pDBlink link){
	int da;
	pNode cur,h,head;
	if(scanf("%d",&da),da){
		head=h=cur=(pNode)malloc(sizeof(Node));
		cur->data=da;
		head->next=cur;
		cur->prev=NULL;
		cur->next=NULL;
		link->head=head;
	}else{
		return ;
	}
	while(scanf("%d",&da),da){
		cur=(pNode)malloc(sizeof(Node));
		cur->data=da;
		h->next=cur;
		cur->prev=h;
		cur->next=NULL;
		h=cur;
	}
	link->tail=h;
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
void Insert(pDBlink link){
	int da;
	pNode in;
	while(scanf("%d",&da),da){
		in=(pNode)malloc(sizeof(Node));
		link->tail->next=in;
		in->data=da;
		in->prev=link->tail;
		link->tail=in;
	}

}
pNode Find(pDBlink link,int n){
	pNode cur=link->head;
//	int n;
//	scanf("%d",&n);
	while(cur){
		if(cur->data==n){
			printf("find Yes!\n");
			return cur;
		}
		cur=cur->next;
	}
	printf("No! not find!\n");
	return NULL;
}
void Delete(pDBlink link){
	int n;
	pNode pos;
	scanf("%d",&n);
	if(pos=Find(link,n)){
		pos->prev->next=pos->next;
		pos->next->prev=pos->prev;
		free(pos);
	}else{
		printf("Not Found!\n");
	}
}
void showR(pNode tail){
	pNode h=tail;
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
	pDBlink link=(pDBlink)malloc(sizeof(DBlink));
	Create(link);
	show(link->head);
	Insert(link);
//	Find(link);
	Delete(link);
	showR(link->tail);
	return 0;
}
