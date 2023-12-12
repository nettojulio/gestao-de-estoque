gef:
	@mkdir -p build
	@gcc -c source/main.c -o build/main.o
	@gcc -c source/menu/menu.c -o build/menu.o
	@gcc -c source/produto/produto.c -o build/produto.o
	@gcc build/main.o build/menu.o build/produto.o -o estoque
	@rm build/*.o
run:
	@make gef
	@./estoque
