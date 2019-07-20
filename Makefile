DESTDIR=

LIBPD_DIR:=lib/libpd
LIBPD_CFLAGS=-O3
LIBPD:=$(LIBPD_DIR)/libs/libpd.so

PROG:=src/epdd

all: $(PROG)

clean:
	$(MAKE) -C $(LIBPD_DIR) clean
	rm -f $(LIBPD)
	$(MAKE) -C src clean

$(LIBPD):
	$(MAKE) -C $(LIBPD_DIR) OPT_CFLAGS="$(LIBPD_CFLAGS)" UTIL=true EXTRA=true

$(PROG): $(LIBPD)
	$(MAKE) -C src CFLAGS="$(PROG_CFLAGS)"
