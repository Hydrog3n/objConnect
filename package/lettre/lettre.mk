LETTRE_MODULE_VERSION = 1.0
LETTRE_SITE = $(TOPDIR)/package/lettre/src
LETTRE_SITE_METHOD = local
LETTRE_LICENSE = GPLv2
#LETTRE_LICENSE_FILES = COPYING
define KERNEL_MODULE_BUILD_CMDS
	$(MAKE) -C '$(@D)' LINUX_DIR='$(LINUX_DIR)' CC='$(TARGET_CC)' LD='$(TARGET_LD)' modules
endef

$(eval $(kernel-module))
$(eval $(generic-package))
