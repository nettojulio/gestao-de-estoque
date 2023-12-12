gef:
	@gcc -c source/main.c -o build/main.o
	@gcc -c source/menu/menu.c -o build/menu.o
	@gcc build/main.o build/menu.o -o estoque
	@rm build/*.o
run:
	@make gef
	@./estoque
