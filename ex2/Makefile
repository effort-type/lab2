OBJECTS = main.o add.o subtract.o multiply.o divide.o
CC = gcc 
IN = ./code/

TARGET = cal

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)
	
add.o : $(IN)add.c
	$(CC) -c $(IN)add.c
subtract.o : $(IN)subtract.c
	$(CC) -c $(IN)subtract.c
multiply.o : $(IN)multiply.c
	$(CC) -c $(IN)multiply.c
divide.o : $(IN)divide.c
	$(CC) -c $(IN)divide.c

clean :
	rm -f $(TARGET) $(OBJECTS)