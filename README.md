money
=====

An example of operator overloading in PHP 5.6
This is a WIP port of https://github.com/sebastianbergmann/money with operator overloading.
Overflows are taken care of.

```php

$m1 = new Money(25, 'foo');
$m2 = new Money(42, 'foo');
$m3 = new Money(17, 'bar');

var_dump($m1 + m2); /* object money with amount = 67 */

var_dump(-$m2); /* object money with amount = -42 */

try {
	$result = $m2 - $m3;
} catch (CurrencyMismatchException $e) {
	/* currencies dont match */
	/* $result === NULL */
}

var_dump(187 + $m1); /* Unsupported operand, fall back to PHP default behavior : (int)188 */
var_dump([] - $m1); /* Unsupported operand, fall back to PHP default behavior : (int)188 */

```

Reminders :

- WIP
- PHP 5.6 only
- Linux only, Mac should be supported.

Todo :

- Implement other OPcodes (multiply, divide, etc...)
- Implement other code from original library (rounding, other methods, etc...)
- Use ICU to parse the currency, current currency is never used/checked/parsed
