## SPDX-License-Identifier: BSD-2-Clause
# ################################################################
# LZ4 - Makefile
# Copyright (C) Yann Collet 2011-2015
# All rights reserved.
#
# You can contact the author at :
#  - LZ4 source repository : https://github.com/Cyan4973/lz4
#  - LZ4 forum froup : https://groups.google.com/forum/#!forum/lz4c
# ################################################################

# Version number
export VERSION=132
export RELEASE=r$(VERSION)

DESTDIR?=
PREFIX ?= /usr/local

LIBDIR ?= $(PREFIX)/lib
INCLUDEDIR=$(PREFIX)/include
PRGDIR  = programs
LZ4DIR  = lib


# Define nul output
ifneq (,$(filter Windows%,$(OS)))
VOID = nul
else
VOID = /dev/null
endif


.PHONY: default all lib lz4programs clean test versionsTest examples

default: lz4programs

all: lib lz4programs

lib:
	@$(MAKE) -C $(LZ4DIR) all

lz4programs:
	@$(MAKE) -C $(PRGDIR)

clean:
	@$(MAKE) -C $(PRGDIR) $@ > $(VOID)
	@$(MAKE) -C $(LZ4DIR) $@ > $(VOID)
	@$(MAKE) -C examples $@ > $(VOID)
	@$(MAKE) -C versionsTest $@ > $(VOID)
	@echo Cleaning completed


#------------------------------------------------------------------------
#make install is validated only for Linux, OSX, kFreeBSD and Hurd targets
ifneq (,$(filter $(shell uname),Linux Darwin GNU/kFreeBSD GNU))

install:
	@$(MAKE) -C $(LZ4DIR) $@
	@$(MAKE) -C $(PRGDIR) $@

uninstall:
	@$(MAKE) -C $(LZ4DIR) $@
	@$(MAKE) -C $(PRGDIR) $@

travis-install:
	sudo $(MAKE) install

test:
	$(MAKE) -C $(PRGDIR) test

cmake:
	@cd cmake_unofficial; cmake CMakeLists.txt; $(MAKE)

gpptest: clean
	$(MAKE) all CC=g++ CFLAGS="-O3 -I../lib -Wall -Wextra -Wundef -Wshadow -Wcast-align -Werror"

clangtest: clean
	CFLAGS="-O3 -Werror -Wconversion -Wno-sign-conversion" $(MAKE) all CC=clang

sanitize: clean
	CFLAGS="-O3 -g -fsanitize=undefined" $(MAKE) test CC=clang FUZZER_TIME="-T1mn" NB_LOOPS=-i1

staticAnalyze: clean
	CFLAGS=-g clang-tidy $(CLANG_TIDY_CHECKS) $(CLANG_TIDY_ARGS) $(SRCS)

armtest: clean
	CFLAGS="-O3 -Werror" $(MAKE) -C $(LZ4DIR) all CC=arm-linux-gnueabi-gcc
	CFLAGS="-O3 -Werror" $(MAKE) -C $(PRGDIR) bins CC=arm-linux-gnueabi-gcc

versionsTest: clean
	$(MAKE) -C versionsTest

examples:
	$(MAKE) -C $(LZ4DIR)
	$(MAKE) -C $(PRGDIR) lz4
	$(MAKE) -C examples test

endif
