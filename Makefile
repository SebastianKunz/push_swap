CHECKER = checker_dir

PUSH_SWAP = push_swap_dir

all:
	@make -C $(CHECKER) all
	@mv $(CHECKER)/checker .
	@make -C $(PUSH_SWAP) all
	@mv $(PUSH_SWAP)/push_swap .

clean:
	@make -C $(CHECKER) clean
	@make -C  $(PUSH_SWAP) clean

fclean: clean
	@/bin/rm checker
	@/bin/rm push_swap

re:
	@make -C $(CHECKER) re
	@mv $(CHECKER)/checker .
	@make -C $(PUSH_SWAP) re
	@mv $(PUSH_SWAP)/push_swap .