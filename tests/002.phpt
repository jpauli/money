--TEST--
Check Money comparaison
--SKIPIF--
<?php if (!extension_loaded("money")) print "skip"; ?>
--FILE--
<?php 
$m1 = new Money(42, 'foo');
$m2 = new Money(10, 'bar');
$m3 = new Money(26, 'foo');

var_dump($m1 == $m3);

try { var_dump($m1 == $m2); } catch (CurrencyMismatchException $e) { }

--EXPECTF--
bool(false)