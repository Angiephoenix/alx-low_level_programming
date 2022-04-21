#include "main.h"
<<<<<<< HEAD

#include <stdlib.h>

#include <stdio.h>

#include <ctype.h>



/**
 *
 *  * _is_zero - determines if any number is zero
 *
 *   * @argv: argument vector.
 *
 *    *
 *
 *     * Return: no return.
 *
 *      */

void _is_zero(char *argv[])

{

		int i, isn1 = 1, isn2 = 1;



			for (i = 0; argv[1][i]; i++)

						if (argv[1][i] != '0')

									{

													isn1 = 0;

																break;

																		}



				for (i = 0; argv[2][i]; i++)

							if (argv[2][i] != '0')

										{

														isn2 = 0;

																	break;

																			}



					if (isn1 == 1 || isn2 == 1)

							{

										printf("0\n");

												exit(0);

													}

}



/**
 *
 *  * _initialize_array - set memery to zero in a new array
 *
 *   * @ar: char array.
 *
 *    * @lar: length of the char array.
 *
 *     *
 *
 *      * Return: pointer of a char array.
 *
 *       */

char *_initialize_array(char *ar, int lar)

{

		int i = 0;



			for (i = 0; i < lar; i++)

						ar[i] = '0';

				ar[lar] = '\0';

					return (ar);

}



/**
 *
 *  * _checknum - determines length of the number
 *
 *   * and checks if number is in base 10.
 *
 *    * @argv: arguments vector.
 *
 *     * @n: row of the array.
 *
 *      *
 *
 *       * Return: length of the number.
 *
 *        */

int _checknum(char *argv[], int n)

{

		int ln;



			for (ln = 0; argv[n][ln]; ln++)

						if (!isdigit(argv[n][ln]))

									{

													printf("Error\n");

																exit(98);

																		}



				return (ln);

}



/**
 *
 *  * main - Entry point.
 *
 *   * program that multiplies two positive numbers.
 *
 *    * @argc: number of arguments.
 *
 *     * @argv: arguments vector.
 *
 *      *
 *
 *       * Return: 0 - success.
 *
 *        */

int main(int argc, char *argv[])

{

		int ln1, ln2, lnout, add, addl, i, j, k, ca;

			char *nout;



				if (argc != 3)

							printf("Error\n"), exit(98);

					ln1 = _checknum(argv, 1), ln2 = _checknum(argv, 2);

						_is_zero(argv), lnout = ln1 + ln2, nout = malloc(lnout + 1);

							if (nout == NULL)

										printf("Error\n"), exit(98);

								nout = _initialize_array(nout, lnout);

									k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;

										for (; k >= 0; k--, i--)

												{

															if (i < 0)

																		{

																						if (addl > 0)

																										{

																															add = (nout[k] - '0') + addl;

																																			if (add > 9)

																																									nout[k - 1] = (add / 10) + '0';

																										
=======
#include <stdlib.h>
#include <stdio.h>

int find_len(char *str);
char *create_xarray(int size);
char *iterate_zeroes(char *str);
void get_prod(char *prod, char *mult, int digit, int zeroes);
void add_nums(char *final_prod, char *next_prod, int next_len);

/**
 * find_len - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int find_len(char *str)
{
int len = 0;

while (*str++)
len++;

return (len);
}

/**
 * create_xarray - Creates an array of chars and initializes it with
 *                 the character 'x'. Adds a terminating null byte.
 * @size: The size of the array to be initialized.
 *
 * Description: If there is insufficient space, the
 *              function exits with a status of 98.
 * Return: A pointer to the array.
 */
char *create_xarray(int size)
{
char *array;
int index;

array = malloc(sizeof(char) * size);

if (array == NULL)
exit(98);

for (index = 0; index < (size - 1); index++)
array[index] = 'x';

array[index] = '\0';

return (array);
}

/**
 * iterate_zeroes - Iterates through a string of numbers containing
 *                  leading zeroes until it hits a non-zero number.
 * @str: The string of numbers to be iterate through.
 *
 * Return: A pointer to the next non-zero element.
 */
char *iterate_zeroes(char *str)
{
while (*str && *str == '0')
str++;

return (str);
}

/**
 * get_digit - Converts a digit character to a corresponding int.
 * @c: The character to be converted.
 *
 * Description: If c is a non-digit, the function
 *              exits with a status of 98.
 * Return: The converted int.
 */
int get_digit(char c)
{
int digit = c - '0';

if (digit < 0 || digit > 9)
{
printf("Error\n");
exit(98);
}

return (digit);
}

/**
 * get_prod - Multiplies a string of numbers by a single digit.
 * @prod: The buffer to store the result.
 * @mult: The string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 *
 * Description: If mult contains a non-digit, the function
 *              exits with a status value of 98.
 */
void get_prod(char *prod, char *mult, int digit, int zeroes)
{
int mult_len, num, tens = 0;

mult_len = find_len(mult) - 1;
mult += mult_len;

while (*prod)
{
*prod = 'x';
prod++;
}

prod--;

while (zeroes--)
{
*prod = '0';
prod--;
}

for (; mult_len >= 0; mult_len--, mult--, prod--)
{
if (*mult < '0' || *mult > '9')
{
printf("Error\n");
exit(98);
}

num = (*mult - '0') * digit;
num += tens;
*prod = (num % 10) + '0';
tens = num / 10;
}

if (tens)
*prod = (tens % 10) + '0';
}

/**
 * add_nums - Adds the numbers stored in two strings.
 * @final_prod: The buffer storing the running final product.
 * @next_prod: The next product to be added.
 * @next_len: The length of next_prod.
 */
void add_nums(char *final_prod, char *next_prod, int next_len)
{
int num, tens = 0;

while (*(final_prod + 1))
final_prod++;

while (*(next_prod + 1))
next_prod++;

for (; *final_prod != 'x'; final_prod--)
{
num = (*final_prod - '0') + (*next_prod - '0');
num += tens;
*final_prod = (num % 10) + '0';
tens = num / 10;

next_prod--;
next_len--;
}

for (; next_len >= 0 && *next_prod != 'x'; next_len--)
{
num = (*next_prod - '0');
num += tens;
*final_prod = (num % 10) + '0';
tens = num / 10;

final_prod--;
next_prod--;
}

if (tens)
*final_prod = (tens % 10) + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argv: The number of arguments passed to the program.
 * @argc: An array of pointers to the arguments.
 *
 * Description: If the number of arguments is incorrect or one number
 *              contains non-digits, the function exits with a status of 98.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
char *final_prod, *next_prod;
int size, index, digit, zeroes = 0;

if (argc != 3)
{
printf("Error\n");
exit(98);
}

if (*(argv[1]) == '0')
argv[1] = iterate_zeroes(argv[1]);
if (*(argv[2]) == '0')
argv[2] = iterate_zeroes(argv[2]);
if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
{
printf("0\n");
return (0);
}

size = find_len(argv[1]) + find_len(argv[2]);
final_prod = create_xarray(size + 1);
next_prod = create_xarray(size + 1);

for (index = find_len(argv[2]) - 1; index >= 0; index--)
{
digit = get_digit(*(argv[2] + index));
get_prod(next_prod, argv[1], digit, zeroes++);
add_nums(final_prod, next_prod, size - 1);
}
for (index = 0; final_prod[index]; index++)
{
if (final_prod[index] != 'x')
putchar(final_prod[index]);
}
putchar('\n');

free(next_prod);
free(final_prod);

return (0);
}
>>>>>>> ed7781d7a8ae3db26f7f176d963b60466aaa21cf
