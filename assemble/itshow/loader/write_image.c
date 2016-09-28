#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char*argv[]){
	int fd_source;
	int fd_dest;
	int read_count=0;
	char buffer[512]={0};
	fd_source=open("myloader.bin",O_RDONLY);
	if(fd_source<0){
		perror("open myloader.bin error:");
		return -1;
	}
	fd_dest=open("myboot.vfd",O_WRONLY);
	while((read_count=read(fd_source,buffer,512))>0){
		write(fd_dest,buffer,read_count);
		memset(buffer,0,512);
	}
	printf("write image ok!\n");
	return 0;
}
