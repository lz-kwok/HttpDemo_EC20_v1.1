PROJECT_DIR := $(shell pwd)

DIR_INC = ./src
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin
DIR_LIB = ./lib

SRC = $(wildcard ${DIR_SRC}/*.c)  
OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC})) 

CC = /home/guoliangzhi/dev_Lamp/prebuilts/gcc/linux-x86/arm/gcc-linaro-6.3.1-2017.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc

#CFLAGS = -std=c99
CFLAGS += -I$(DIR_INC)

#LIBS   += -Wl,-Bdynamic -lpthread -ldl -L$(PROJECT_DIR)/src/-lskyiotservice
LIBS   += -lpthread -ldl -L$(DIR_LIB) -lgMyuartlzHttp




TARGET = uart

BIN_TARGET = ${DIR_BIN}/${TARGET}


${BIN_TARGET}:$(DIR_OBJ)
	$(CC) -o $(BIN_TARGET) $(SRC) $(CFLAGS) $(LIBS) -lpthread 
	
${DIR_OBJ}/%.o:$(DIR_SRC)/%.c
	$(CC) -o $@ $< $(CFLAGS)

.PHONY:clean
clean:
	echo  $(PROJECT_DIR)
	$(RM) -rf edit  ${DIR_OBJ}/*.o
	$(RM) -rf edit  ${DIR_BIN}/*

