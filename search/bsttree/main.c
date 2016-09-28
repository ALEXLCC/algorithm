#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"bst.h"
#define RANGE 100
#define N 6
void print_elem(link p){
	printf("%d",p->elem);
}
int main(){
	int i,elem;
	link root=NULL;
	srand(time(NULL));
	for(i=0;i<N;++i){
		root=insert(root,rand()%RANGE);
	}
	print_tree(root);
	printf("\n\n");
	while(root){
		elem=rand()%RANGE;
		if(search(root,elem)){
			printf("delete %d in tree\n",elem);
			root=delete(root,elem);
			printf("\t\\tree");
			print_tree(root);
			printf("\n\n");
		}
	}
	return 0;
}
