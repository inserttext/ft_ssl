CC        = gcc
LD        = gcc
CFLAGS    = -MMD -g3 -std=c11 -mavx
CERR      = -Wall -Wextra
CERR     += -Wshadow -Wdouble-promotion -Wundef -fno-common -Wconversion
LFLAGS    =
CERR     += -Werror
BUILD_DIR = build

INC     = -Iincludes -Ilibft/includes
LIBS    = -Llibft -lft

MODULES = base64 md5 sha256
SDIR    = src
SDIR   += $(addprefix src/,$(MODULES))
BDIR   = $(foreach sdir,$(SDIR),$(addprefix $(BUILD_DIR)/,$(sdir)/))
SRC     = $(foreach sdir,$(SDIR),$(wildcard $(sdir)/*.c))
OBJ     = $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP     = $(OBJ:%.o=%.d)

all: ft_ssl

%/:
	mkdir -p $@

libft.a:
	make -C libft

ft_ssl: $(OBJ) | libft.a
	$(LD) $(LFLAGS) -o $@ $^ $(LIBS)

$(BUILD_DIR)/%.o: %.c | $(BDIR)
	$(CC) $(CERR) $(CFLAGS) -c -o $@ $< $(INC)

-include $(DEP)

.PHONY: clean fclean re

clean:
	make clean -C libft
	rm -f $(OBJ)
	rm -f $(DEP)

fclean:
	make fclean -C libft
	rm -rf $(BUILD_DIR)
	rm -f $(NAME)

re: fclean all
