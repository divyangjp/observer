########################################################
# command	output
# -------   	-----------------------------------
# make		Makes executable without debug info
# make debug	Makes executable with debug info
# make clean	Cleans executable, object files and core
#######################################################

#------------------------------------------------------------------------------

SOURCEDIR=.

SOURCE=\
	$(SOURCEDIR)/005_observ_application.cpp \
	$(SOURCEDIR)/005_observ_client.cpp \
	$(SOURCEDIR)/005_use_observ.cpp

OBJECTS=\
	005_observ_application.o \
	005_observ_client.o \
	005_use_observ.o

MYPROGRAM=a.out
MYINCLUDES=\
	-I./
#	-I../smart-ptr/hdr

MYLIBRARIES=

CFLAGS= -Wall
CDEBUGFLAGS= -g -DDEBUG

CC=g++

#------------------------------------------------------------------------------


all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)
	$(CC) $(CFLAGS) $(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM) 

debug: $(OBJECTS)
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) $(MYINCLUDES) $(OBJECTS) -o$(MYPROGRAM)


.cpp.o:
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) $(MYINCLUDES) -c $<

clean:
	rm -f $(MYPROGRAM) *.o core
