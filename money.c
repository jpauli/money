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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_money.h"

#if ZEND_MODULE_API_NO < 20131226
#error "Please compile for PHP>=5.6"
#endif

static int le_money;
zend_class_entry *money_ce;

zend_object_handlers money_object_handlers;

ZEND_BEGIN_ARG_INFO(arginfo___construct, dummy)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

static const zend_function_entry money_functions[] = {
		PHP_ME(Money, __construct, arginfo___construct, ZEND_ACC_PUBLIC)
		PHP_FE_END
};

PHP_METHOD(Money, __construct)
{
	long value;
	zend_object *this;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &value) == FAILURE) {
		return;
	}

	zend_update_property_long(Z_OBJCE_P(getThis()), getThis(), "value", sizeof("value") -1, value);
}

static int money_handler_do_operation (zend_uchar opcode, zval *result, zval *op1, zval *op2)
{
	zval *valueobj1 = zend_read_property(Z_OBJCE_P(op1), op1, "value", sizeof("value")-1, 0);
	zval *valueobj2 = zend_read_property(Z_OBJCE_P(op2), op2, "value", sizeof("value")-1, 0);

	switch (opcode) {
	case ZEND_ADD:
		INIT_ZVAL(*result);
		object_init_ex(result, money_ce);

		zend_update_property_long(money_ce, result, "value", sizeof("value") - 1, Z_LVAL_P(valueobj1) + Z_LVAL_P(valueobj2));
		return SUCCESS;
	break;
	default:
		return FAILURE;
	break;
	}
}

static zend_object_value money_create_object(zend_class_entry *ce)
{
	zend_object_value retval;
	zend_object *obj;

	obj = emalloc(sizeof(zend_object));
	zend_object_std_init(obj, ce);
	object_properties_init(obj, ce);

	retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t) zend_objects_destroy_object, (zend_objects_free_object_storage_t)zend_objects_free_object_storage, NULL);
	retval.handlers = &money_object_handlers;

	return retval;
}

PHP_MINIT_FUNCTION(money)
{
	zend_class_entry money_tmp;
	INIT_CLASS_ENTRY(money_tmp, "Money", money_functions);

	money_ce = zend_register_internal_class(&money_tmp);
	money_ce->ce_flags |= ZEND_ACC_FINAL_CLASS;
	money_ce->create_object = money_create_object;

	zend_declare_property_long(money_ce, "value", sizeof("value") -1, 0, ZEND_ACC_PRIVATE);

	memcpy(&money_object_handlers, &std_object_handlers, sizeof(std_object_handlers));
	money_object_handlers.do_operation = money_handler_do_operation;

	return SUCCESS;
}

PHP_MINFO_FUNCTION(money)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "money support", "enabled");
	php_info_print_table_end();
}

zend_module_entry money_module_entry = {
	STANDARD_MODULE_HEADER,
	"money",
	NULL,
	PHP_MINIT(money),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(money),
	PHP_MONEY_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MONEY
ZEND_GET_MODULE(money)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
