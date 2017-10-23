#include "ft_printf.h"

/*
** Checks if current character of a given string is a complete
** multibyte character.
** If there's only part of a mb char then it returns false.
** Otherwise returns number of characters read.
** (Works with single-byte characters as well)
** 1b - 0xxx xxxx (0 < s[i])
** 2b - 110x xxxx  10xx xxxx (s[i] < -32)
** 3b - 1110 xxxx  10xx xxxx  10xx xxxx (s[i] < -16)
** 4b - 1111 0xxx  10xx xxxx  10xx xxxx  10xx xxxx (s[i] < -8)
*/

int		is_n_bytes(char *str, int n)
{
	int		indx;

	indx = 1;
	while (str[indx] && indx < n)
	{
		if (str[indx] >= -64)
			return (0);
		indx++;
	}
	if (indx == n)
		return (n);
	return (0);
}

int			is_multibyte(char *str)
{
	int		indx;

	if (!str)
		return (0);
	indx = 0;
	if (str[indx] > 0)
		return (1);
	else if (str[indx] > -64 && str[indx] < -32)
		return (is_n_bytes(str, 2));
	else if (str[indx] >= -32 && str[indx] < -16)
		return (is_n_bytes(str, 3));
	else if (str[indx] >= -16 && str[indx] < -8)
		return (is_n_bytes(str, 4));
	else
		return (0);
}
