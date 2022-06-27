CC							=	gcc
ASAN						:=	#-g -fsanitize=address
STDFLAGS					=	-c -Wall -Wextra -Werror -std=c11
CFLAGS						?=	$(STDFLAGS) $(ASAN)
LFLAGS						:=

RM							:= rm -f
MK							:=	mkdir -p

CAT_SRC_DIR					?=	./cat
GREP_SRC_DIR				?=	./grep

TARGET_CAT					:=	s21_cat
TARGET_GREP					:=	s21_grep

CAT_EXE						:=	$(CAT_SRC_DIR)/s21_cat
GREP_EXE					:=	$(GREP_SRC_DIR)/s21_grep

CAT_INC_DIR					:=	./cat/
GREP_INC_DIR				:=	./grep/

CAT_OBJ_DIR					?=	./cat/objs
GREP_OBJ_DIR				?=	./grep/objs

OBJS						:=	$(shell find . -name "*.o")

CAT_SRC						:=	$(shell find $(CAT_SRC_DIR)  -name "*.c")
CAT_INC						:=	$(shell find $(CAT_INC_DIR)  -name "*.h")

GREP_SRC					:=	$(shell find $(GREP_SRC_DIR) -name "*.c")
GREP_INC					:=	$(shell find $(GREP_INC_DIR) -name "*.h")

CAT_OBJS					:=	$(addprefix $(CAT_OBJ_DIR)/, $(notdir $(CAT_SRC:.c=.o)))
GREP_OBJS					:=	$(addprefix $(GREP_OBJ_DIR)/, $(notdir $(GREP_SRC:.c=.o)))

all: s21_cat s21_grep

s21_cat: $(CAT_EXE)

s21_grep: $(GREP_EXE)

$(CAT_EXE): $(CAT_OBJS)  Makefile
	$(CC) $(CAT_OBJS) $(LFLAGS)  $(ASAN) -o $(CAT_EXE)

$(GREP_EXE): $(GREP_OBJS)  Makefile
	$(CC) $(GREP_OBJS) $(LFLAGS)  $(ASAN) -o $(GREP_EXE)

$(CAT_OBJ_DIR)%.o: $(CAT_SRC_DIR)%.c $(CAT_INC)
	@$(MK) $(CAT_OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(GREP_OBJ_DIR)%.o: $(GREP_SRC_DIR)%.c $(GREP_INC)
	@$(MK) $(GREP_OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(GREP_OBJS)
	$(RM) $(CAT_OBJS)

fclean: clean
	$(RM) $(GREP_EXE)
	$(RM) $(CAT_EXE)

rebuild: fclean all

.PHONY: clean fclean rebuild