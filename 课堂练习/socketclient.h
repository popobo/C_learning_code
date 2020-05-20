#ifndef _SOCKETCLIENT_H_
#define _SOCKETCLIENT_H_

#ifdef __cplusplus//���������ʹ��C++�淶���밴��C���Եķ�ʽ�����º������е���
extern "C" {
#endif
	//��һ��api
	//socket�ͻ��˳�ʼ��
	int socketclient_init(void** handle);

	//socket�ͻ��˱��ķ���
	int socketclient_send(void* handle, unsigned char* buf, int buflen);

	//socket�ͻ��˱��Ľ���
	int socketclient_recv(void* handle, unsigned char* buf, int buflen);

	//socket�ͻ��˻����ͷ�
	int socketclient_destroy(void* handle);


	//�ڶ���api
	int socketclient_init2(void** handle);

	//socket�ͻ��˱��ķ���
	int socketclient_send2(void* handle, unsigned char* buf, int buflen);

	//socket�ͻ��˱��Ľ���
	int socketclient_recv2(void* handle, unsigned char** buf, int buflen);
	int socketclient_Free(unsigned char **buf);

	//socket�ͻ��˻����ͷ�
	int socketclient_destroy2(void** handle);

	//���������
	//һ��ָ��
	//����ָ��
	//void** handle���ͷ�װ�ĸ���

#ifdef __cplusplus
}
#endif

#endif