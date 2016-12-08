OBJS = map.o


all: risk

risk: $(OBJS)
	$(CC) $(OBJS) -o risk

 
