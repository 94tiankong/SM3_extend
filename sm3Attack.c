
#include <string.h>
#include <stdio.h>
#include "sm3.h"

int main( int argc, char *argv[] )
{
	unsigned char *input = "aaa";
	int ilen = 3;
	unsigned char output[32];
	int i;
	sm3_context ctx;

	printf("�������ϢΪ:");
	printf("%s\n",input);
    
	//����sm3�㷨 
	sm3(input, ilen, output);
	printf("��ϣֵΪ��");
	for(i=0; i<32; i++)
	{
		printf("%02x",output[i]);
	} 
	printf("\n");

	printf("�ڶ��μӳ�����ϢΪ��");
	for(i=0; i < 16; i++)
		printf("bbbb");
	printf("\n");
	//����Ϣ���мӳ� 
    sm3_starts( &ctx );
	for(i=0; i < 16; i++)
		sm3_update( &ctx, "bbbb", 4 );
    sm3_finish( &ctx, output );
    memset( &ctx, 0, sizeof( sm3_context ) );
	//����ڶ��ι�ϣֵ 
	printf("�ڶ��ζ�Ӧ�Ĺ�ϣֵΪ��");
	for(i=0; i<32; i++)
	{
		printf("%02x",output[i]);
	}   
	printf("\n");
    
}