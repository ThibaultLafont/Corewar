##
## EPITECH PROJECT, 2024
## B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
## File description:
## Makefile
##

COMPIL_ALL	=	compil_all

NAME	=	corewar

all:	$(COMPIL_ALL)

compil_lib:
	@echo "<=-=-=-=-=-> LIB COMPILATION <-=-=-=-=-=>"
	@$(MAKE) -C ./lib
	@echo "<=-=-=-=-=-> LIB COMPILATION DONE <-=-=-=-=-=>"

compil_corewar:
	@echo "<=-=-=-=-=-> COREWAR COMPILATION <-=-=-=-=-=>"
	@$(MAKE) -C ./corewar_main
	@echo "<=-=-=-=-=-> COREWAR COMPILATION DONE <-=-=-=-=-=>"

$(COMPIL_ALL):	compil_lib compil_corewar

clean:
	@echo "<=-=-=-=-=-> CLEANING OBJECT FILES <-=-=-=-=-=>"
	@$(RM) *~
	@$(MAKE) -C ./corewar_main clean
	@$(MAKE) -C ./lib clean
	@echo "<=-=-=-=-=-> CLEANING OBJECT FILES DONE <-=-=-=-=-=>"

fclean:
	@echo "<=-=-=-=-=-> CLEANING EXECUTABLES <-=-=-=-=-=>"
	@$(MAKE) -C ./corewar_main fclean
	@$(MAKE) -C ./lib fclean
	@$(RM) $(NAME)
	@echo "<=-=-=-=-=-> CLEANING EXECUTABLES DONE <-=-=-=-=-=>"

re:	fclean all
