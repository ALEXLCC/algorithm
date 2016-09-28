#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
	int fd=-1;
	char filename[]="text.txt";
	fd=open(filename,O_RDWR);
	if(-1==fd){
		printf("can't open the file!\n");
	}else{
		printf("open the file %s success! fd=%d\n",filename,fd);
	}
	return 0;
}
