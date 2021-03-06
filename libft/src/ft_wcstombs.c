#include "libft.h"

size_t	ft_wcstombs(char *s, const wchar_t *old_ws, size_t len)
{
	size_t	src;
	size_t	dest;

	src = 0;
	dest = 0;
	while (dest < len - 1)
		dest += (ft_wctomb(&s[dest], old_ws[src++]));
	s[dest] = '\0';
	return (dest);
}
