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
    
	char  q[9]={'"','a','b','c','d','e','f','"','\0'};
	char *p = q;
		   

	post_to_ec20("AT\r\n");
	sleep(1);
	
	post_to_ec20("AT+CSQ\r\n");	    //询问信号强弱
	sleep(1);

	post_to_ec20("AT+CGATT?\r\n"); //查询附着和分离GPRS业务
	sleep(1);	

	post_to_ec20("AT+QHTTPCFG=\"contextid\",1\r\n");	//配置上下文
	sleep(1);

	post_to_ec20("AT+QIACT?\r\n");	//询问上下文状态
	sleep(1);		
	
	post_to_ec20("AT+QICSGP=1,1,\"CTNET\",\"\",\"\",1\r\n"); //配置电信网络
	sleep(1);

	post_to_ec20("AT+QIACT=1\r\n");	 //激活上下文
	sleep(1);

	post_to_ec20("AT+QIACT?\r\n");   //询问上下文状态	
	sleep(1);

	post_to_ec20("AT+QHTTPCFG=\"requestheader\",%d\r\n",1); 
	sleep(1);
//		post_to_ec20("AT+QHTTPCFG=\"contenttype\",%d\r\n",1); 
//		sleep(1);
	
	post_to_ec20("AT+QHTTPURL=41,80\r\n");	//
	sleep(1);
		
	while(1)
	{   
		post_to_ec20("http://47.111.88.91:6096/iot/data/receive\r\n");	//输入网址
		sleep(2);
		post_to_ec20("AT+QHTTPPOST=%d,80,80\r\n", strlen(p));
		sleep(2);
		post_to_ec20("POST /iot/data/receive HTTP/1.1\r\n");
		post_to_ec20("Host:47.111.88.91:6096\r\n");
		post_to_ec20("Accept:*/*\r\n");
		post_to_ec20("Content-Length:%d\r\n",strlen(p));
		post_to_ec20("Content-Type:text/html\r\n");
		post_to_ec20("Connection:Keep-Alive\r\n");
		post_to_ec20("\r\n");
		post_to_ec20("%s\r\n", p);
		sleep(1);		
	}
    return 0;
}
