all:
	$(MAKE) -C src/pi
#	pack build pi-os.ipkg -- for later use
#	cc -Werror build/exec/pi-os.o -lidris2_refc -Lsupport/refc -- for later use
clean:
	$(MAKE) clean -C src/pi
#	pack build pi-os.ipkg -- fo
