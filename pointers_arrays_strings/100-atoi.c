#include "main.h"
/**
* _atoi - Converts a string to an integer
* @s: Pointer to the string to be converted
*
* Return: The integer converted from the string, or 0 if no numbers
*/
int _atoi(char *s)
{
int i;
int sign;
int res;
int found;

i = 0;
sign = 1;
res = 0;
found = 0;

while (s[i] != '\0')
{
if (s[i] == '-')
{
sign *= -1;
}
else if (s[i] >= '0' && s[i] <= '9')
{
found = 1;
res = res * 10 + (s[i] - '0');
}
else if (found == 1)
{
break;
}
i++;
}

if (sign < 0)
{
res = -res;
}
return (res);
}
