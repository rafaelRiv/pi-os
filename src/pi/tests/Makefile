all:
	pack build tests
	sed -i 's/#include <runtime.h>/#include "rts\/runtime.h"\n/g' build/exec/kernel-tests.c
	sed -i 's/#include <idris_support.h>//g' build/exec/kernel.c
	sed -i 's/int main(int argc, char \*argv\[\])/int kmain\(\)/g' build/exec/kernel-tests.c
	sed -i 's/idris2_setArgs(argc, argv);//g' build/exec/kernel-tests.c
	cp build/exec/kernel.c kernel-tests.c

clean:
	rm *.c
	rm -rf build
