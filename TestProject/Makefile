ROOT=..
PROJ_NAME = TestProject
include ${ROOT}/makedefs
SRCS += $(wildcard *.c)

$(PROJ_NAME).elf: $(OBJS)
		$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
