CLIUDP_MODULE_VERSION = 1.0
CLIUDP_SITE = $(TOPDIR)/package/cliudp/src
CLIUDP_SITE_METHOD = local
CLIUDP_LICENSE = GPLv2
#CLIUDP_LICENSE_FILES = COPYING

define CLIUDP_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D) all
endef

define CLIUDP_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/cliudp $(TARGET_DIR)/bin/cliudp
endef

$(eval $(generic-package))
