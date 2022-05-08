hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Order.o -c ./src/Order.c
	gcc -I ./include/ -o ./lib/Mean.o -c ./src/Mean.c
	gcc -I ./include/ -o ./bin/Test ./lib/Mean.o ./lib/Order.o ./src/Test.c
calistir:
	./bin/Test
