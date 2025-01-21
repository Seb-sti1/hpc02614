TARGET	= matvec
OBJS	= main.o

OPT	= -g -fast -Msafeptr -Minfo -acc -mp=gpu -gpu=cc90 -gpu=lineinfo -cuda
ISA	= -DSIZE=1000000
PARA	= -fopenmp
CC	= nvc

CCC	= nvc++
CXX	= nvc++

CFLAGS	= $(OPT) $(ISA) $(PARA) $(XOPT)
CXXFLAGS	= $(OPT) $(ISA) $(PARA) $(XOPT) 

F90C  	= gfortran
LIBS	= -lblas -cudalib=cublas


all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CCC) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	@/bin/rm -f *.o core

realclean: clean
	@rm -f $(TARGET)

# dependencies
main.o  : main.c