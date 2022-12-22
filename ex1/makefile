CC = gcc
MAIN = tool/main
ASCII_ART_TOOL = tool/AsciiArtTool
OBJS = $(MAIN).o RLEList.o $(ASCII_ART_TOOL).o
EXEC = AsciiArtTool
DEBUG_FLAG = # assign -g for debug
CFLAGS = -std=c99 -Wall -Werror $(DEBUG_FLAG) -I/home/mtm/public/2122b/ex1 -Itool \
                                                       -pedantic-errors -DNDEBUG

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@


main.o : $(MAIN).c $(ASCII_ART_TOOL).h

RLEList.o : RLEList.c

AsciiArtTool.o : $(ASCII_ART_TOOL).c $(ASCII_ART_TOOL).h

clean :
	rm -f $(OBJS) $(EXEC)



