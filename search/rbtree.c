#include<stdio.h>
#include<stdlib.h>
#define N 100
#define RED 1
#define BLACK 0
typedef struct node{
	int elem;
	int color;	//1 red 0 black
	struct node* parent;
	struct node* lchild;
	struct node* rchild;
}tree,*pTree;
pTree null;
void RBNODE(){
	null=malloc(sizeof *null);
	null->elem=0;
	null->color=BLACK;
	null->lchild=null;
	null->rchild=null;
	null->parent=null;
}
pTree NODE(pTree t,int elem){
	t=malloc(sizeof *t);
	t->elem=elem;
	t->lchild=null;
	t->rchild=null;
	t->parent=null;
	return t;
}
void left_rotate(pTree* root,pTree x){
	pTree y=(x)->rchild;
	(x)->rchild=y->lchild;
	if(y->lchild!=null){
		y->lchild->parent=(x);
	}
	y->parent=(x)->parent;
	if((x)->parent==null){
		*root=y;
	}else if((x)==(x)->parent->lchild){
		(x)->parent->lchild=y;
	}else{
		(x)->parent->rchild=y;
	}

	y->lchild=(x);
	(x)->parent=y;
}
void right_rotate(pTree* root,pTree y){
	pTree x=(y)->lchild;
	(y)->lchild=x->rchild;
	if(x->rchild!=null){
		x->rchild->parent=(y);
	}
	x->parent=(y)->parent;
	if((y)->parent==null){
		*root=x;
	}else if(y==y->parent->rchild){	//此处不知道y具体是左子树还是右子树。否则出错。
		x->parent->rchild=x;
	}else{
		x->parent->lchild=x;
	}
	x->rchild=(y);
	(y)->parent=x;
}
void rb_insert_fixup(pTree *root,pTree z){
	pTree y;
	while(RED==(z)->parent->color){
		if((z)->parent==(z)->parent->parent->lchild){
			y=(z)->parent->parent->rchild;	//uncle node
			if(y->color==RED){
				(z)->parent->color=BLACK;
				y->color=BLACK;
				(z)->parent->parent->color=RED;
				(z)=(z)->parent->parent;
			}else{
				if(z==(z)->parent->rchild){
					z=(z)->parent;
					left_rotate(root,z);
				}
				(z)->parent->color=BLACK;
				(z)->parent->parent->color=RED;
				right_rotate(root,(z)->parent->parent);
			}
		}else if((z)->parent==(z)->parent->parent->rchild){
			y=(z)->parent->parent->lchild;	//uncle node
			if(y->color==RED){
				(z)->parent->color=BLACK;
				y->color=BLACK;
				(z)->parent->parent->color=RED;
				(z)=(z)->parent->parent;
			}else{
				if(z==(z)->parent->lchild){
					z=(z)->parent;
					right_rotate(root,z);
				}

				(z)->parent->color=BLACK;
				(z)->parent->parent->color=RED;
				left_rotate(root,(z)->parent->parent);
			}
		}
	}
	(*root)->color=BLACK;
}

void rb_insert(pTree *root,pTree z){
	pTree y=null;	//save the parent
	pTree x=*root;
	while(x!=null){
		y=x;
		if((z)->elem<x->elem){
			x=x->lchild;
		}else{
			x=x->rchild;
		}
	}
	(z)->parent=y;
	if(y==null){
		*root=z;
	}else if((z)->elem<y->elem){
		y->lchild=z;
	}else{
		y->rchild=z;
	}
	(z)->color=RED;
	rb_insert_fixup(root,z);
}
void show(pTree root){
	if(root!=null){
		printf("%d%c\n",root->elem,root->color==RED?'+':'-');
		show(root->lchild);
		show(root->rchild);
	}
}
pTree find(pTree root,int elem){
	while(root->elem!=elem&&root!=null){
		if(root->elem<elem){
			root=root->rchild;
		}else{
			root=root->lchild;
		}
	}
	return root;
}
void rb_transplant(pTree* root,pTree u,pTree v){
	if(u->parent==null){
		*root=v;
	}else if(u==u->parent->lchild){
		u->parent->lchild=v;
	}else{
		u->parent->rchild=v;
	}
	v->parent=u->parent;
}
pTree tree_minimum(pTree p){
	while(p->lchild!=null){
		p=p->lchild;
	}
	return p;
}
void rb_delete_fixup(pTree* root,pTree x){
	//把x当成黑色节点。
	pTree w;
	while(x!=*root&&x->color==BLACK){
		if(x==x->parent->lchild){
			w=x->parent->rchild;
			if(w->color==RED){
				w->color=BLACK;	//red--->black     //case1
				x->parent->color=RED;	//
				left_rotate(root,x->parent);
				w=x->parent->rchild;
			}
			if(w->lchild->color==BLACK&&w->rchild->color==BLACK){//case2
				w->color=RED;
				x=x->parent;
			}else{
				if(w->rchild->color==BLACK){	//case3
					w->lchild->color=BLACK;
					w->color=RED;
					right_rotate(root,w);
					w=x->parent->rchild;
				}
				w->color=x->parent->color;	//case4
				x->parent->color=BLACK;
				w->rchild->color=BLACK;
				left_rotate(root,x->parent);
				x=*root;
			}
		}else{
			if(x==x->parent->rchild){
                w=x->parent->lchild;
                if(w->color==RED){
                    w->color=BLACK;	//red--->black     //case1
                    x->parent->color=RED;	//
                    right_rotate(root,x->parent);
                    w=x->parent->lchild;
                }
                if(w->lchild->color==BLACK&&w->rchild->color==BLACK){//case2
                    w->color=RED;
                    x=x->parent;
                }else{
                    if(w->lchild->color==BLACK){	//case3
                        w->rchild->color=BLACK;
                        w->color=RED;
                        left_rotate(root,w);
                        w=x->parent->lchild;
                    }
                    w->color=x->parent->color;	//case4
                    x->parent->color=BLACK;
                    w->lchild->color=BLACK;
                    right_rotate(root,x->parent);
                    x=*root;
                }
            }
        }
    }
    x->color=BLACK;
}
void rb_delete(pTree* root,int elem){
	pTree z=find(*root,elem);
	pTree x,y=z;
	int yColor=y->color;
	if(z==null){
		printf("not found!\n");
		return;
	}
	if(z->lchild==null){
		x=z->rchild;
		rb_transplant(root,z,z->rchild);
	}else if(z->rchild==null){
		x=z->lchild;
		rb_transplant(root,z,z->lchild);
	}else{
		y=tree_minimum(z->rchild);
		yColor=y->color;
		x=y->rchild;
/*		if(x!=null){
			y->parent->lchild=x;
			x->parent=y->parent;
		}
		if(null==z->parent){
			*root=y;
		}else if(z->parent->lchild==z){
			z->parent->lchild=y;
		}else{
			z->parent->rchild=y;
		}
		y->lchild=z->lchild;
		y->rchild=z->rchild;
		z->lchild->parent=y;
		z->rchild->parent=y;
		y->color=z->color;
		*/
		if(y->parent==z){
			x->parent=y;
		}else{
			rb_transplant(root,y,y->rchild);
			y->rchild=z->rchild;
			y->rchild->parent=y;
		}
		rb_transplant(root,z,y);
		y->lchild=z->lchild;
		y->lchild->parent=y;
		y->color=z->color;
	}
	if(yColor==BLACK){
		rb_delete_fixup(root,x);
	}
	free(z);
	z=null;
}
int main(){
	pTree root,node;
	int i,len;
//	int array[N]={11,2,14,15,1,7,5,8,4};
	int array[N]={41,38,31,12,19,8,76,45,89,42,53,67};
	RBNODE();
//	srand(time(0));
	root=null;
	len=12;
	for(i=0;i<len;++i){
		node=NODE(node,array[i]);
		rb_insert(&root,node);
	}
	show(root);
	while(root!=null){
		int choose=-1;
		printf("case 0:exit\ncase 1:insert\ncase 2:delete\ncase 3:show ");
		scanf("%d",&choose);
		switch(choose){
			case 0:
				goto ret;
			case 1:
				node=NODE(node,(scanf("%d",&choose),choose));
				rb_insert(&root,node);
				choose=-1;
				break;
			case 2:
				rb_delete(&root,(scanf("%d",&choose),choose));
				choose=-1;
				break;
			case 3:
				show(root);
				choose=-1;
				break;
			default:
				break;
		}
	}
ret:
	getchar();
	return 0;
}
