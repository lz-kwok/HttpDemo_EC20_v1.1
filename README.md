# HttpDemo_EC20_v1.1

# 1.tty_port 为系统中实际serial_id , 如"/dev/ttymxc1"，根据实际情况可在main.h中修改；
# 2.gDevice_Uart_Init，串口初始化api，输入参数分别为serial_id、波特率和数据接收回调函数；
# 3.post_to_ec20，发送AT指令至EC20，带参发送与printf完全相同
