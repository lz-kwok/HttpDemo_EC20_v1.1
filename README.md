	 ________         __            _________          
	/ ______|        |  |          |____    _|         
	| |   _____      |  |               /  /           
	| |  |_   _|     |  |              /  /            
	| |____| |       |  |____       __/  /____         
	\________|       |_______|     |__________|        
 Copyright (C) 2013 - 2020, liangzhiGuo, <lz_kwok@163.com>, et al         
 
 HttpDemo_EC20_v1.1
=====================
1. Helper programs
### 1.1. tty_port  ###
tty_port 为系统中实际serial_id , 如"/dev/ttymxc1"，根据实际情况可在main.h中修改；

### 1.2. gDevice_Uart_Init  ###
串口初始化api，输入参数分别为serial_id、波特率和数据接收回调函数；

### 1.3. post_to_ec20  ###
发送AT指令至EC20，带参发送与printf完全相同

### 1.4. Http_Post_RawJson_Data  ###
可替代“AT+QHTTPPOST”所需执行的操作，发送原始json数据至服务器