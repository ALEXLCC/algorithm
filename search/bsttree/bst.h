/*
 	bst.h
 */
#ifndef BST_H
#define BST_H
	typedef struct node* link;
	struct node{
		unsigned char elem;
		link l,r;
	};
	link search(link t,unsigned char elem);
	link insert(link t,unsigned char elem);
	link delete(link t,unsigned char elem);
	void print_tree(link t);
#endif
