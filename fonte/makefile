##### MAKEFILE ####

##### Compiler
COMPILER = g++
##### Remove directories
RMDIR = rm -rdf
##### Remove files
RM = rm -f

##### Automatic dependency creation
DEP_FLAGS = -M -MT $@ -MT $(BIN_PATH)/$(*F).o -MP -MF $@
##### Linked libraries
LIBS =
##### Include path
INC_PATHS = -I$(INC_PATH)

##### Compile directives
FLAGS = -std=c++17 -Wall -pedantic -Wextra -Werror=init-self -g
##### Extra debugging directives
DFLAGS = -ggdb -O0 -DDEBUG
##### Extra release directives
RFLAGS = -O3 -mtune=native

INC_PATH = include
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep

##### File list by type
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
INC_FILES = $(wildcard $(INC_PATH)/*.h)
FILE_NAMES = $(sort $(notdir $(CPP_FILES:.cpp=)) $(notdir $(INC_FILES:.h=)))
DEP_FILES = $(addprefix $(DEP_PATH)/,$(addsuffix .d,$(FILE_NAMES)))
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))

##### Executable name
EXEC = main.exe

.PRECIOUS: $(DEP_FILES)
.PHONY: release debug cppcheck valgrind limpa pastas ajuda executa

##### General rule
all: $(EXEC)

##### Generates executable
$(EXEC): $(OBJ_FILES)
	$(COMPILER) -o $@ $^ $(LINK_PATH) $(LIBS) $(FLAGS)

##### Generates object files
$(BIN_PATH)/%.o: $(DEP_PATH)/%.d | pastas
	$(COMPILER) $(INC_PATHS) $(addprefix $(SRC_PATH)/,$(notdir $(<:.d=.cpp))) -c $(FLAGS) -o $@

##### Generates dependency files
$(DEP_PATH)/%.d: $(SRC_PATH)/%.cpp | pastas
	$(COMPILER) $(INC_PATHS) $< $(DEP_FLAGS) $(FLAGS)

limpa:
	-$(RMDIR) $(DEP_PATH)
	-$(RMDIR) $(BIN_PATH)
	-$(RM) $(EXEC)

executa:
	./main.exe

##### Call for cppcheck
cppcheck:
	cppcheck --enable=all . -I./include --suppress=missingIncludeSystem

##### Call for valgrind coverage
valgrind:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes --dsymutil=yes ./$(EXEC)

build: FLAGS += $(RFLAGS)
build: $(EXEC)

debug: FLAGS += $(DFLAGS)
debug: $(EXEC)

pastas:
ifeq ($(OS), Windows_NT)
	@if NOT exist $(DEP_PATH) ( mkdir $(DEP_PATH) )
	@if NOT exist $(BIN_PATH) ( mkdir $(BIN_PATH) )
	@if NOT exist $(INC_PATH) ( mkdir $(INC_PATH) )
	@if NOT exist $(SRC_PATH) ( mkdir $(SRC_PATH) )
else
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(INC_PATH) $(SRC_PATH)
endif

##### Debugging rules
print-% : ; @echo $* = $($*)

ajuda:

ifeq ($(OS), Windows_NT)
	@echo.
endif
	@echo `tput bold`build:`tput sgr0`      Compila os arquivos binários
	@echo `tput bold`debug:`tput sgr0`      Compila versão de debug do projeto
	@echo `tput bold`executa:`tput sgr0`    Executa o programa compilado
	@echo `tput bold`limpa:`tput sgr0`      Deleta os arquivos gerados
	@echo `tput bold`cppcheck:`tput sgr0`   Roda o cppcheck nos arquivos
	@echo `tput bold`ajuda:`tput sgr0`      Mostra uma lista dos comandos disponíveis
	@echo `tput bold`pastas:`tput sgr0`     Cria as pastas do projeto caso não existem ainda.
	@echo
	@echo Esse makefile deve rodar em sistema Linux. Pode haver problemas em outros sistemas.
ifeq ($(OS), Windows_NT)
	@echo.
endif

.SECONDEXPANSION:
-include $$(DEP_FILES)