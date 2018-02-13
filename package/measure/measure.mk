MEASURE_MODULE_VERSION = 1.0
MEASURE_SITE = $(TOPDIR)/package/measure/src
MEASURE_SITE_METHOD = local
MEASURE_LICENSE = GPLv2
#MEASURE_LICENSE_FILES = COPYING

define MEASURE_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D) all
endef

define MEASURE_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/measure $(TARGET_DIR)/bin/measure
endef

$(eval $(generic-package))
