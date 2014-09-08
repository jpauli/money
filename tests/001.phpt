--TEST--
Check for money basics
--SKIPIF--
<?php if (!extension_loaded("money")) print "skip"; ?>
--FILE--
<?php 
$m  = new Money(42, 'foo');
$m1 = new Money(42, new Currency('foo'));

try { $m2 = new Money(42, new stdclass); } catch (InvalidArgumentException $e) { }
try { $m3 = new Money(42, []); } catch (InvalidArgumentException $e) { }

var_dump($m, $m1);
--EXPECTF--
object(Money)#%d (2) {
  ["amount":"Money":private]=>
  int(42)
  ["currency":"Money":private]=>
  object(Currency)#%d (1) {
    ["currencyCode":"Currency":private]=>
    string(3) "foo"
  }
}
object(Money)#%d (2) {
  ["amount":"Money":private]=>
  int(42)
  ["currency":"Money":private]=>
  object(Currency)#%d (1) {
    ["currencyCode":"Currency":private]=>
    string(3) "foo"
  }
}