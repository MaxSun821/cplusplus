dy-lib=libmymethod.so 
lib=libmymath.a

.PHONY:all
all:$(lib) $(dy-lib)

$(lib):my_math.o
	ar -rc $@ $^

$(dy-lib):myprint.o mylog.o
	gcc -shared -o $@ $^

my_math.o:my_math.c
	gcc -c $^

myprint.o:myprint.c
	gcc -fPIC -c $^

mylog.o:mylog.c
	gcc -fPIC -c $^

.PHONY:clean
clean:
	rm -rf *.o libmymethod.so libmymath.a lib/

.PHONY:output
output:
	mkdir -p lib/include/
	mkdir -p lib/libmymath/
	mkdir -p lib/mymethod/
	mv *.h lib/include/
	mv *.a lib/libmymath/
	mv *.so lib/mymethod/
