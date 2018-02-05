obj-m := lettre.o

ifeq ($(KERNELRELEASE),)
    PWD := $(shell pwd)
modules:
	$(MAKE) -C '$(LINUX_DIR)' M='$(PWD)' modules
clean:
	$(MAKE) -C '$(LINUX_DIR)' M='$(PWD)' clean
endif
