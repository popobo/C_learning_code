#ifndef _SOCKETCLIENT_H_
#define _SOCKETCLIENT_H_

#ifdef __cplusplus//如果编译器使用C++规范，请按照C语言的方式对以下函数进行调用
extern "C" {
#endif
	//第一套api
	//socket客户端初始化
	int socketclient_init(void** handle);

	//socket客户端报文发送
	int socketclient_send(void* handle, unsigned char* buf, int buflen);

	//socket客户端报文接收
	int socketclient_recv(void* handle, unsigned char* buf, int buflen);

	//socket客户端环境释放
	int socketclient_destroy(void* handle);


	//第二套api
	int socketclient_init2(void** handle);

	//socket客户端报文发送
	int socketclient_send2(void* handle, unsigned char* buf, int buflen);

	//socket客户端报文接收
	int socketclient_recv2(void* handle, unsigned char** buf, int buflen);
	int socketclient_Free(unsigned char **buf);

	//socket客户端环境释放
	int socketclient_destroy2(void** handle);

	//技术点分析
	//一级指针
	//二级指针
	//void** handle类型封装的概念

#ifdef __cplusplus
}
#endif

#endif