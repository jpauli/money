--TEST--
Check Money methods API
--SKIPIF--
<?php if (!extension_loaded("money")) print "skip"; ?>
--FILE--
<?php 
$m1 = new Money(42, 'foo');
$m2 = new Money(10, 'foo');

var_dump($m1->add($m2));
var_dump($m1->substract($m2));
var_dump($m1->negate());
var_dump($m1->multiply(2));
var_dump($m1->equals($m2));
var_dump($m1->compareTo($m2));

var_dump($m1->greaterThan($m2));
var_dump($m1->greaterThanOrEqual($m2));
var_dump($m1->lessThan($m2));
var_dump($m1->lessThanOrEqual($m2));
--EXPECTF--
object(Money)#%d (2) {
  ["amount":"Money":private]=>
  int(52)
  ["currency":"Money":private]=>
  object(Currency)#%d (1) {
    ["currencyCode":"Currency":private]=>
    string(3) "foo"
  }
}
object(Money)#%d (2) {
  ["amount":"Money":private]=>
  int(32)
  ["currency":"Money":private]=>
  object(Currency)#%d (1) {
    ["currencyCode":"Currency":private]=>
    string(3) "foo"
  }
}
object(Money)#%d (2) {
  ["amount":"Money":private]=>
  int(-42)
  ["currency":"Money":private]=>
  object(Currency)#%d (1) {
    ["currencyCode":"Currency":private]=>
    string(3) "foo"
  }
}
object(Money)#%d (2) {
  ["amount":"Money":private]=>
  int(84)
  ["currency":"Money":private]=>
  object(Currency)#%d (1) {
    ["currencyCode":"Currency":private]=>
    string(3) "foo"
  }
}
bool(false)
int(1)
bool(true)
bool(true)
bool(false)
bool(false)