# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 17:02:58 by bnespoli          #+#    #+#              #
#    Updated: 2025/01/16 19:34:21 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CFLAGS	= -Wextra -Wall -Werror -Ofast
CC	:= cc
PRINTF	:= lib/printf/
LIBFT	:= lib/libft/
BUILD_DIR = objects/
MKDIR  := mkdir -p

HEADERS	:= -I ./include -I $(LIBFT) -I $(PRINTF) $(LIBS)

LIBS 	:= -lm $(LIBFT)libft.a -lreadline \
	-lm $(PRINTF)libftprintf.a

LDFLAGS	:= $(HEADERS) $(LIBS)

SRC_DIR := ./src/
SRCS := \
	ast/ast.c \
	ast/ast_utils.c \
	builtins/builtins_utils.c \
	builtins/cd.c \
	builtins/echo.c \
	builtins/env.c \
	builtins/exit.c \
	builtins/export.c \
	builtins/export_utils.c \
	builtins/pwd.c \
	builtins/unset.c \
	envp/envp.c \
	envp/pathname.c \
	error/error.c \
	error/clean.c \
	error/clean_2.c \
	exec/exec_brackets.c \
	exec/exec_pipe.c \
	exec/exec_red.c \
	exec/exec_utils.c \
	exec/exec_utils_2.c \
	exec/execution.c \
	grammar/grammar.c \
	grammar/grammar_utils.c \
	grammar/grammar_subshell.c \
	grammar/order.c \
	heredoc/heredoc.c \
	heredoc/heredoc_utils.c \
	parser/parser.c \
	parser/parser_utils.c \
	principal/main.c \
	principal/read_inputs.c \
	principal/utils.c \
	signal/signals.c \
	signal/signals_macros.c \
	tokenizer/expand.c \
	tokenizer/expand_heredoc.c \
	tokenizer/expand_heredoc_utils.c \
	tokenizer/expand_utils.c \
	tokenizer/split_expand.c \
	tokenizer/phrase.c \
	tokenizer/tokenizer.c \
	vector/vector_add.c \
	vector/vector_create.c \
	vector/vector_remove.c \
	vector/vector_return.c \
	vector/vector_split.c \

SRC := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS	+=  $(SRC:%.c=$(BUILD_DIR)%.o)

define create_dir
	$(MKDIR) $(dir $@)
endef

all: libft printf $(NAME)

val: all
	valgrind --suppressions=./local.supp --quiet --leak-check=full --show-leak-kinds=all ./$(NAME)

$(BUILD_DIR)%.o: %.c
	$(call create_dir)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

libft:
	@make -C $(LIBFT)

printf:
	@make -C $(PRINTF)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -rf $(BUILD_DIR)
	@make -C $(LIBFT) clean
	@make -C $(PRINTF) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(PRINTF) fclean

re: clean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) ./include

.PHONY: all, clean, fclean, re, libft, printf, bonus
.DEFAULT_GOAL := all
