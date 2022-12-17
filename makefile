peta.out: main.o canvas.o peta.o
	gcc -Werror -Wall -Wextra -g -o peta.out *.o -lm

main.o: main.c canvas.o peta.o
	gcc -Werror -Wall -Wextra -g -c main.c

canvas.o: canvas.c canvas.h
	gcc -Werror -Wall -Wextra -g -c canvas.c

peta.o: peta.c peta.h canvas.o
	gcc -Werror -Wall -Wextra -g -c peta.c

clean:
	rm -rf *.o *.out
