all:
	$(MAKE) -C src/pi
tests:
	$(MAKE) tests -C src/pi
clean:
	$(MAKE) clean -C src
