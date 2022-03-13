#include <stdio.h>
/**
 * main - main block
 * Description: Print numbers of base 10, starting from 0.
 * Your are not allowed to use any variable of type char.
 * You can only use `putchar` to printt to console.
 * You can only use `putchar` twice.
 * Return: 0
 */
int main(void)
{
int i;

for (i = 0; i < 10; i++)
{
putchar(i + '0');
}
putchar('\n');

return (0);
}
