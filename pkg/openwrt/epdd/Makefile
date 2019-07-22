#
# Copyright (C) 2019 Nicolas Thill <nicolas.thill@gmail.com
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=epdd
PKG_VERSION:=0.3
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=git@github.com:psycho-nico/epdd.git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=v$(PKG_VERSION)
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz

PKG_LICENSE:=
PKG_LICENSE_FILES:=

PKG_MAINTAINER:=Nicolas Thill <nicolas.thill@gmail.com

include $(INCLUDE_DIR)/package.mk

define Package/epdd
  SECTION:=sound
  CATEGORY:=Sound
  DEPENDS:= +alsa-lib +libpthread +libstdcpp
  TITLE:=E256 eTextile matrix sensor audio synthesis program
  URL:=https://matrix.etextile.org/
endef

define Package/epdd/description
  E256 eTextile matrix sensor audio synthesis program
endef

MAKE_FLAGS += \
	LIBPD_CFLAGS="$(TARGET_CFLAGS)" \
	PROG_CFLAGS="$(TARGET_CFLAGS)" \

define Package/epdd/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/epdd $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lib/libpd/libs/libpd.so $(1)/usr/lib/
endef

$(eval $(call BuildPackage,epdd))
