#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"


char rec_buf[512];


static void rec_Analaze(void *para){
	sleep(1);
	while(1){
		if(strlen(rec_buf) != 0){
			printf("rec_Analaze rec_buf : %s rec_buf len : %d\r\n",rec_buf,strlen(rec_buf));
			memset(rec_buf,0x0,512);
		}
		
	}
	
}

//Http_Post_RawJson_Data()
//可替代“AT+QHTTPPOST”所需执行的操作
//使用方法：cjon为需要发送的json数据
//char *str = cJSON_PrintUnformatted(cjson);
//Http_Post_RawJson_Data(str,80,80);


int main(int argc, char **argv) {

	if(gDevice_Uart_Init(tty_port,115200,rec_buf) == 0){
		
		printf("gDevice_Uart_Init success\r\n");
	}
	
	memset(rec_buf,0x0,512);
	printf("rec_buf size if %d\r\n",strlen(rec_buf));
	pthread_t rec_id;
    pthread_create(&rec_id, NULL, rec_Analaze, NULL);
    
    while (1) {
		printf("post_to_ec20 post\r\n");
		post_to_ec20("AT\r\n");	
		sleep(2);
		post_to_ec20("AT+CSQ\r\n");	
		sleep(2);
		post_to_ec20("AT+CGATT?\r\n");	
		sleep(2);
    }
    return 0;
}
