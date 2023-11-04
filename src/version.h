#pragma once

#define X_VERSION_MAJOR 0
#define X_VERSION_MINOR 0
#define X_VERSION_PATCH 1

#define X_MAKE_VERSION(major, minor, patch)                                  \
    ((major)*10000 + (minor)*100 + (patch))

#define X_VERSION                                                            \
    X_MAKE_VERSION(X_VERSION_MAJOR, X_VERSION_MINOR, X_VERSION_PATCH)
