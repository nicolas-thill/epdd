DESTDIR=

LIBPD_DIR:=lib/libpd
LIBPD_CFLAGS=-O3
LIBPD:=$(LIBPD_DIR)/libs/libpd.so

PDTEST:=src/pdtest

all: $(PDTEST)

clean:
	make -C $(LIBPD_DIR) clean
	rm -f $(LIBPD)
	make -C src clean

$(LIBPD):
	make -C $(LIBPD_DIR) OPT_CFLAGS="$(LIBPD_CFLAGS)" UTIL=true EXTRA=true

$(PDTEST): $(LIBPD)
	make -C src
