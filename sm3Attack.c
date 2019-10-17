
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

	printf("输入的消息为:");
	printf("%s\n",input);
    
	//调用sm3算法 
	sm3(input, ilen, output);
	printf("哈希值为：");
	for(i=0; i<32; i++)
	{
		printf("%02x",output[i]);
	} 
	printf("\n");

	printf("第二次加长的消息为：");
	for(i=0; i < 16; i++)
		printf("bbbb");
	printf("\n");
	//对消息进行加长 
    sm3_starts( &ctx );
	for(i=0; i < 16; i++)
		sm3_update( &ctx, "bbbb", 4 );
    sm3_finish( &ctx, output );
    memset( &ctx, 0, sizeof( sm3_context ) );
	//输出第二次哈希值 
	printf("第二次对应的哈希值为：");
	for(i=0; i<32; i++)
	{
		printf("%02x",output[i]);
	}   
	printf("\n");
    
}