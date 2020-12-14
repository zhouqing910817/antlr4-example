OUTPUT=output
GENERATED=generated
# runtime is where you downloaded and extracted https://www.antlr.org/download/antlr4-cpp-runtime-4.8-macos.zip
RUNTIME=./runtime-osx
CCARGS=-c -I $(RUNTIME)/antlr4-runtime/ -I $(GENERATED) -std=c++11	
LDARGS=-g
LIBS=$(RUNTIME)/lib/libantlr4-runtime.a
JAVA=/usr/bin/java
CC=g++
GRAMMAR=Expr
# This assumes you have antlr-4.7-complete.jar in the current directory.
ANTLR4=$(JAVA) -jar antlr-4.7-complete.jar
#ANTLR4=antlr4

ANTLRGEN=BaseListener Lexer Listener Parser 
OBJS=$(addsuffix .o,$(addprefix $(OUTPUT)/$(GRAMMAR),$(ANTLRGEN)))
GSOURCES=$(addsuffix .cpp,$(addprefix $(GENERATED)/$(GRAMMAR),$(ANTLRGEN)))

.precious: $(GSOURCES)

all: hello

hello: dirs antlr4 hello.cpp $(OBJS)
	$(CC) $(CCARGS) hello.cpp  -o $(OUTPUT)/hello.o 
	$(CC) $(LDARGS) $(OUTPUT)/hello.o $(OBJS) $(LIBS) -o hello

antlr4: $(GENERATED)/.generated;
 
$(GENERATED)/.generated: $(GRAMMAR).g4
	$(ANTLR4) -Dlanguage=Cpp -o $(GENERATED) $(GRAMMAR).g4
	@touch $(GENERATED)/.generated

$(OUTPUT)/%.o : $(GENERATED)/%.cpp
	$(CC) $(CCARGS) $< -o $@

$(GENERATED)/%.cpp: $(GENERATED)/.generated;

dirs:; mkdir -p $(OUTPUT) $(GENERATED) 
clean:; rm -rf $(OUTPUT) $(GENERATED)
