#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<Winsock2.h>
#include<stdio.h>
#pragma comment(lib, "ws2_32.lib") 
void main()
{   
	//windows操作系统下的初始化工作,加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	char	addr[20] = { 0 };
	wVersionRequested = MAKEWORD(1, 1);//第一个参数为低位字节；第二个参数为高位字节
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return;
	}
	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return;
	}
	//创建套接字

	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	//基于UDP的客户端来说，它不需要去绑定,但是要设置信息将要发送到对方机器的地址信息,也就是服务器端的地址信息
	SOCKADDR_IN addrSrv; //定义一个地址结构体的变量，
	printf("开始对话\n");
	printf("输入 q 即可结束对话\n");
	//获取服务器地址
    addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;//地址族,,代表TCP/IP协议族
	addrSrv.sin_port = htons(6000);//接收端口号
	char recvBuf[100];//接收数据
	char sendBuf[100];//发送数据
	char tempBuf[200];//临时数据存储
	int len = sizeof(SOCKADDR);//用于返回接收数据的地址结构的长度,必须先经过初始化
	while (true)
	{  
		printf("请输入:\n");
	    scanf("%s",sendBuf);
        //gets_s(sendBuf);//获取用户输入的数据
		//UDP不需要建立连接直接通过sendto（）函数发送数据
		sendto(sockClient, sendBuf, strlen(sendBuf) + 1, 0,
			(SOCKADDR*)&addrSrv, len);//发送数据
		recvfrom(sockClient, recvBuf, 100, 0,
			(SOCKADDR*)&addrSrv, &len);//接收数据
									   //判断是否结束对话
		if ('q' == recvBuf[0] )
		{
			sendto(sockClient, "q", strlen("q") + 1, 0,
				(SOCKADDR*)&addrSrv, len);
			printf_s("对话结束，还有五秒即将关闭窗口\n");
			int i;
			for (i = 5; i >= 0; i--)
			{
				printf("%d", i);
				Sleep(1000);
				printf("\b");
			}
			printf(" ");

			printf("\n");
			//程序退出
			break;
		}
		sprintf_s(tempBuf, "%s say:%s", inet_ntoa(addrSrv.sin_addr), recvBuf);
		
		printf("%s\n", tempBuf);	
	}
	closesocket(sockClient);
	WSACleanup();
}