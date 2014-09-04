dnl $Id$
dnl config.m4 for extension money

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(money, for money support,
dnl Make sure that the comment is aligned:
dnl [  --with-money             Include money support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(money, whether to enable money support,
dnl Make sure that the comment is aligned:
[  --enable-money           Enable money support])

if test "$PHP_MONEY" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-money -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/money.h"  # you most likely want to change this
  dnl if test -r $PHP_MONEY/$SEARCH_FOR; then # path given as parameter
  dnl   MONEY_DIR=$PHP_MONEY
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for money files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MONEY_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MONEY_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the money distribution])
  dnl fi

  dnl # --with-money -> add include path
  dnl PHP_ADD_INCLUDE($MONEY_DIR/include)

  dnl # --with-money -> check for lib and symbol presence
  dnl LIBNAME=money # you may want to change this
  dnl LIBSYMBOL=money # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MONEY_DIR/lib, MONEY_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MONEYLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong money lib version or lib not found])
  dnl ],[
  dnl   -L$MONEY_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MONEY_SHARED_LIBADD)

  PHP_NEW_EXTENSION(money, money.c, $ext_shared)
fi
