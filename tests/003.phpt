--TEST--
Check basic Money ops
--SKIPIF--
<?php if (!extension_loaded("money")) print "skip"; ?>
--FILE--
<?php 
$m1 = new Money(42, 'foo');
$m2 = new Money(10, new Currency('foo'));

var_dump($m1 + $m2);
var_dump($m1 - $m2);
var_dump(-$m1);
var_dump($m1 + 3);

var_dump($m1 > $m2);
var_dump($m1 < $m2);
var_dump($m1 <= $m2);

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

Notice: Object of class Money could not be converted to int in %s on line %d
int(4)
bool(true)
bool(false)
bool(false)