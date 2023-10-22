#define CVM_VERSION_MAJOR 0
#define CVM_VERSION_MINOR 0
#define CVM_VERSION_PATCH 1

#define CVM_MAKE_VERSION(major, minor, patch)                                  \
    ((major)*10000 + (minor)*100 + (patch))

#define CVM_VERSION                                                            \
    CVM_MAKE_VERSION(CVM_VERSION_MAJOR, CVM_VERSION_MINOR, CVM_VERSION_PATCH)

#include "cvm_prelude.h"
#include "dict.h"
#include "env.h"
#include "value.h"
