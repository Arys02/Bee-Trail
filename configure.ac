AC_INIT([BeeTrail], [0.1], [yaiche_c@epita.fr])
AC_PREREQ([2.65])

AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])


# ----------- look for c++ compiler
AC_LANG([C++])
AC_PROG_CXX

# Warn if the C++ compiler is not known to support the required
# features.  Or course, we should rather check for features, not
# version numbers.
cxx_version=$($CXX --version |
  sed -n ['/^[^0-9]*\([0-9][0-9.]*[0-9]\).*$/{s//\1/;p;q;}'])
case $($CXX --version) in
  (*clang*)
    AS_VERSION_COMPARE([$cxx_version], [3.4],
      [AC_MSG_WARN([clang++ >= 3.4 is required, have $cxx_version])])
    ;;
  (*g++*)
    AS_VERSION_COMPARE([$cxx_version], [5.0],
      [AC_MSG_WARN([g++ >= 5.0 is required, have $cxx_version])])
    ;;
  (*)
    AC_MSG_WARN([g++ >= 5.0 or clang++ >= 3.4 is recommended, have none])
    ;;
esac

# Enable C++ 2014 support.
AC_CANONICAL_HOST

# Use good warnings.
TC_CXX_WARNINGS([[-Wall],
                 [-W],
                 [-Wcast-align],
                 [-Wcast-qual],
                 [-Wformat],
                 [-Wmissing-prototypes],
                 [-Wstrict-prototypes],
                 [-Wwrite-strings],
                 [-Wbad-function-cast],
                 [-Wmissing-declarations],
                 [-Wnested-externs]])

# Pacify g++ on Boost Variants.
TC_CXX_WARNINGS([[-Wno-shadow]])

## --------------- ##
## Configuration.  ##
## --------------- ##

# Ask for the creation of config.h.
AC_CONFIG_HEADERS([config.h])

# Ask for the creation of the Makefiles.
AC_CONFIG_FILES([Makefile])

# Instantiate the output files.
AC_OUTPUT
