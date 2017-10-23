#include "libft.h"

int		ft_wcslen(const wchar_t *s)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s[++i])
		len += ft_wclen(s[i]);
	return (len);
}
