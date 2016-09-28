#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
int main(void){
	in_addr_t nip,i;
	char sip[16];
	inet_pton(AF_INET,"192.168.79.133",&nip);
	unsigned char* p=(unsigned char*)&nip;
	for(i=0;i<4;++i){
		printf("%02x ",*p++);
	}
	printf("\n");
	inet_ntop(AF_INET,&nip,sip,sizeof(sip));
	puts(sip);
	return 0;
}
