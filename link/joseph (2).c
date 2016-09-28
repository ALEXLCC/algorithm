#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int ord;//order 
	int key;//key
	struct _node* next;
}Node,*pNode;
pNode Create(){
	int k,o=1;
	pNode head,cur,h;
	if(scanf("%d",&k),k){
		head=h=cur=(pNode)malloc(sizeof(Node));
		h->ord=o++;
		h->key=k;
		h->next=NULL;
	}else{
		return NULL;
	}
	while(scanf("%d",&k),k){
		cur=(pNode)malloc(sizeof(Node));
		cur->ord=o++;
		cur->key=k;
		cur->next=NULL;
		h->next=cur;
		h=cur;
	}
	h->next=head;
	return head;
}
void joh(pNode head,int start,int m){
	pNode h=head,tem;
	int count=1;
	while(h->next->ord!=start){
		h=h->next;
	}
	while(h->next){
		while(count<m){
			h=h->next;
			++count;
		}
		if(count==m){
			m=h->next->key;
			printf("ord=%d,key=%d\n",h->next->ord,h->next->key);
			tem=h->next;
			h->next=h->next->next;
			free(tem);
			count=1;
		}
		if(h==h->next){
			printf("ord=%d,key=%d\n",h->next->ord,h->next->key);
			free(h);
			break;
		}

	}
}
void show(pNode head){
	pNode h=head;
	while(h){
		printf("ord=%d,key=%d\n",h->ord,h->key);
		h=h->next;
		if(h==head){
			break;
		}
	}
}
int main(){
	pNode head=Create();
	show(head);
	printf("\n\n");
	joh(head,3,3);
	return 0;
}
