#include "main.h"
/**
 * isalpha check for uppercase and lowercase
 * @c: The character to check (as an integer).
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
 }
