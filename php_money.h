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
  | Author: Julien Pauli <jpauli@php.net>                                |
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

#define CHECK_MONEY_PARAMS zval *other_money; if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &other_money, money_ce) == FAILURE) { return; }
#define CHECK_NO_PARAMS if (zend_parse_parameters_none() == FAILURE) { return; }

#define CREATE_NEW_MONEY_OBJ(obj, amount, currency) do { \
	object_init_ex(obj, money_ce); \
	zend_update_property_long(money_ce, obj, MONEY_PROP_AMOUNT_WS, amount); \
	zend_update_property(money_ce, obj, MONEY_PROP_CURRENCY_WS, currency); \
} while (0);

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


ZEND_BEGIN_ARG_INFO(arginfo_money__construct, dummy)
	ZEND_ARG_INFO(0, amount)
	ZEND_ARG_INFO(0, currency)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO(arginfo_money_add, dummy)
	ZEND_ARG_OBJ_INFO(0, other, Money, 0)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO(arginfo_money_extractPercentage, dummy)
	ZEND_ARG_INFO(0, percentage)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO(arginfo_money_multiply, dummy)
	ZEND_ARG_INFO(0, factor)
	ZEND_ARG_INFO(0, roundingMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_currency__construct, dummy)
	ZEND_ARG_INFO(0, currencyCode)
ZEND_END_ARG_INFO()

PHP_METHOD(Money, __construct);
PHP_METHOD(Money, getAmount);
PHP_METHOD(Money, getCurrency);
PHP_METHOD(Money, add);
PHP_METHOD(Money, substract);
PHP_METHOD(Money, negate);
PHP_METHOD(Money, compareTo);
PHP_METHOD(Money, equals);
PHP_METHOD(Money, greaterThan);
PHP_METHOD(Money, lessThan);
PHP_METHOD(Money, greaterThanOrEqual);
PHP_METHOD(Money, lessThanOrEqual);
PHP_METHOD(Money, extractPercentage);
PHP_METHOD(Money, multiply);

PHP_METHOD(Currency, __construct);

static int money_handler_do_operation(zend_uchar opcode, zval *result, zval *op1, zval *op2);
static int money_handler_compare_objects(zval *object1, zval *object2);

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
