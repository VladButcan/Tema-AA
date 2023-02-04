build: generareTeste timSort introSort verify
	./cleaning.sh
	./script.sh

generareTeste: GenerareTeste.o
	gcc -o generareTeste GenerareTeste.o

GenerareTeste.o: GenerareTeste.c
	gcc -c GenerareTeste.c

timSort: TimSort.o
	gcc -o timSort TimSort.o

TimSort.o: TimSort.c
	gcc -c TimSort.c

introSort: IntroSort.o
	gcc -o introSort IntroSort.o -lm

IntroSort.o: IntroSort.c
	gcc -c IntroSort.c

verify: verifyProgramm.o
	gcc -o verify verifyProgramm.o

verifyProgramm.o: verifyProgramm.c
	gcc -c verifyProgramm.c

run-p1:
	./timSort > ./out/runtimeResult.txt

run-p2:
	./introSort > ./out/runtimeResult.txt

run-best:
	./timSort > ./out/runtimeResult.txt

result:
	./verify

clean:
	rm -r ./in ./out GenerareTeste.o generareTeste TimSort.o timSort IntroSort.o introSort verifyProgramm.o verify

