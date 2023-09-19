#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<Winsock2.h>
#include<stdio.h>
#pragma comment(lib, "ws2_32.lib") 
void main()
{
	FILE	*f;
	char	szLine[MAX_PATH];
	char	buffer[MAX_PATH];

	fopen_s(&f, "E:\\info.txt", "r");
	if (f == NULL)
	{
		printf("无法打开文件\n");
		return ;
	}
	//windows操作系统下的初始化工作，加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return;
	}
	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return;
	}
	//创建套接字,因为是基于UDP的，所以用SOCK_DGRAM.
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	//对于服务器端，接着应该进行绑定
	SOCKADDR_IN addrSrv;//定义一个地址结构体的变量，
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//地址族，AF这个前缀表示地址族（address family）
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);//端口号
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	char recvBuf[100];//字符数组，用来接收信息
	char sendBuf[100];//用来发送信息
	char tempBuf[200];//用来存放中间数据
	//定义一个地址结构体的变量,在通讯的时候，
	/*我们需要获取和我们通讯的这一方的地址信息,
    这一获取是我们通过调用recvfrom来获得的，但是我们需要提供一个地址结构体的变量*/
	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	printf("服务器开启成功等待客户连接\n");


	//while循环，保证通讯过程能够不断的循环下去
	while (1)
	{
		//接收数据
		recvfrom(sockSrv, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &len);
		//判断是否结束对话，q表示结束
		if ('q' == recvBuf[0])
		{
			sendto(sockSrv, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrClient, len);
			printf("对话结束!\n");
			break;
		}

		sprintf_s(tempBuf, "%s say:%s", inet_ntoa(addrClient.sin_addr), recvBuf);
		printf("%s\n", tempBuf);
		fseek(f, 0, SEEK_SET);

		memset(szLine, 0, MAX_PATH);
		fgets(szLine, MAX_PATH, f);
		while (szLine[0] != '#')
		{
			if (szLine[0] == 'Q')
			{
				char szTemp[MAX_PATH] = { 0 };
				//复制字符串szLine + 2到缓冲区szTemp
				lstrcpyA(szTemp, szLine + 2);
				szTemp[lstrlenA(szTemp) + 1] = '\0';
				//匹配成功找到答案
				if (lstrcmpA(szTemp, recvBuf) == 0)
				{					
					memset(szLine, 0, MAX_PATH);
					fgets(szLine, MAX_PATH, f);
					sendto(sockSrv, szLine + 2, strlen(szLine) - 1, 0, (SOCKADDR*)&addrClient, len);
					printf("服务器对话框输出内容：\n");
					printf("%s", szLine + 2);
					break;
				}

			}
			memset(szLine, 0, MAX_PATH);
			fgets(szLine, MAX_PATH, f);
		}
		if (szLine[0]== '#')
		{
		    //memset(buffer, 0, MAX_PATH);
			//sprintf_s(buffer, "听不懂");
			//sendto(sockSrv, buffer + 2, strlen(buffer) - 1, 0, (SOCKADDR*)&addrClient, len);
			printf("Please input data:\n");
			//gets_s(sendBuf);
			scanf("%s",sendBuf);
            sendto(sockSrv, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrClient, len);
		}		
	}
	closesocket(sockSrv);
	WSACleanup();
	fclose(f);
}