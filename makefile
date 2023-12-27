gef:
	@mkdir -p build
	@gcc -c source/main.c -o build/main.o
	@gcc -c source/menu/menu.c -o build/menu.o
	@gcc -c source/produto/produto.c -o build/produto.o
	@gcc -c source/utils/utils.c -o build/utils.o
	@gcc -c source/arquivo/arquivo.c -o build/arquivo.o
	@gcc build/main.o build/menu.o build/produto.o build/utils.o build/arquivo.o -o gestao_de_estoque
	@rm build/*.o
run:
	@make gef
	@./gestao_de_estoque
