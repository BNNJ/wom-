CC			:=	g++
SRCDIR		:=	src
BUILDDIR	:=	build
INCDIR		:=	include
TARGET		:=	wom
 
SRCEXT		:=	cpp
SOURCES		:=	$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS		:=	$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
#CPPFLAGS	:=	-lstdc++fs
CFLAGS		:=	-std=c++17 -Wall -Wextra -Werror
#LIB		:= 
INC			:=	-I $(INCDIR)
#INCLUDES	:=	$(INCDIR)/*

$(TARGET): $(OBJECTS) $(INCLUDES)
	@echo " Linking..."
	@echo " $^"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " Compiling..."
	@echo " $@ from $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
