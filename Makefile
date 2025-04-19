CCOMPILER = gcc
PROJECT = gerenciador.c
CFLAGS = -Wall
default : all run
all :
	$(CCOMPILER) $(CFLAGS) $(PROJECT) -o run.exe
	@echo "Compilado com sucesso!"
run :
	./run.exe
	@echo "Executado com sucesso!"

clean :
	rm -f run.exe
	@echo "Arquivos temporários removidos com sucesso!"