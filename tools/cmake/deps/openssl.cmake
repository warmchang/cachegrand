include(FindPkgConfig)

pkg_check_modules(OPENSSL REQUIRED openssl>=1.1)

if (OPENSSL_FOUND)
    list(APPEND DEPS_LIST_INCLUDE_DIRS ${OPENSSL_INCLUDE_DIRS})
    list(APPEND DEPS_LIST_LIBRARIES ${OPENSSL_LIBRARIES})
else()
    set(OPENSSL_FOUND "0")
endif()