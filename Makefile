SOURCE_DIR = source
OBJ_DIR = obj
INCLUDE_DIR = include
CFLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
PROGRAM_NAME = strings.out

all: obj $(PROGRAM_NAME)

obj:
	@mkdir obj

$(PROGRAM_NAME): $(OBJ_DIR)/main.o $(OBJ_DIR)/string_functions.o $(OBJ_DIR)/hash_functions.o
	@g++ $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/string_functions.o $(OBJ_DIR)/hash_functions.o -o $(PROGRAM_NAME)
	@echo "Linking object files into $(PROGRAM_NAME)"

$(OBJ_DIR)/main.o: $(SOURCE_DIR)/main.cpp $(INCLUDE_DIR)/string_functions.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	@echo "Compiling main.cpp"

$(OBJ_DIR)/string_functions.o: $(SOURCE_DIR)/string_functions.cpp $(INCLUDE_DIR)/string_functions.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/string_functions.cpp -o $(OBJ_DIR)/string_functions.o
	@echo "Compiling main.cpp"

$(OBJ_DIR)/hash_functions.o: $(SOURCE_DIR)/hash_functions.cpp $(INCLUDE_DIR)/hash_functions.h
	@g++ $(CFLAGS) -c $(SOURCE_DIR)/hash_functions.cpp -o $(OBJ_DIR)/hash_functions.o
	@echo "Compiling hash_functions.cpp"