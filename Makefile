DESTDIR=

LIBPD_DIR:=lib/libpd
LIBPD_CFLAGS=-O3
LIBPD:=$(LIBPD_DIR)/libs/libpd.so

all: $(LIBPD)

$(LIBPD):
	make -C $(LIBPD_DIR) OPT_CFLAGS="$(LIBPD_CFLAGS)" UTIL=true EXTRA=true
