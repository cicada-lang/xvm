#pragma once

#define XVM_VERSION_MAJOR 0
#define XVM_VERSION_MINOR 0
#define XVM_VERSION_PATCH 1

#define XVM_MAKE_VERSION(major, minor, patch)                                  \
    ((major)*10000 + (minor)*100 + (patch))

#define XVM_VERSION                                                            \
    XVM_MAKE_VERSION(XVM_VERSION_MAJOR, XVM_VERSION_MINOR, XVM_VERSION_PATCH)
