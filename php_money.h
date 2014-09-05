/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_MONEY_H
#define PHP_MONEY_H

extern zend_module_entry money_module_entry;
#define phpext_money_ptr &money_module_entry

#define PHP_MONEY_VERSION "0.1.0" /* Replace with version number for your extension */

#define MONEY_PROP_AMOUNT "amount"
#define MONEY_PROP_CURRENCY "currency"
#define CURRENCY_PROP_CURRENCYCODE "currencyCode"

#define MONEY_PROP_AMOUNT_WS MONEY_PROP_AMOUNT, sizeof(MONEY_PROP_AMOUNT) -1
#define MONEY_PROP_CURRENCY_WS MONEY_PROP_CURRENCY, sizeof(MONEY_PROP_CURRENCY) -1
#define CURRENCY_PROP_CURRENCYCODE_WS CURRENCY_PROP_CURRENCYCODE, sizeof(CURRENCY_PROP_CURRENCYCODE) -1

#define TYPE_PAIR(t1,t2) (((t1) << 4) | (t2))

#ifdef PHP_WIN32
#	define PHP_MONEY_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_MONEY_API __attribute__ ((visibility("default")))
#else
#	define PHP_MONEY_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_METHOD(Money, __construct);
PHP_METHOD(Money, getAmount);
PHP_METHOD(Money, getCurrency);

PHP_METHOD(Currency, __construct);

#ifdef ZTS
#define MONEY_G(v) TSRMG(money_globals_id, zend_money_globals *, v)
#else
#define MONEY_G(v) (money_globals.v)
#endif

#endif	/* PHP_MONEY_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
