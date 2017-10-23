#include "libft.h"

int		ft_wclen(const wchar_t c)
{
	if (!c)
		return (0);
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 0xFFFF)
		return (3);
	else
		return (4);
}
