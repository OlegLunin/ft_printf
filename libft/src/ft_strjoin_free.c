#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	if (s1 && s2)
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcat(str, s1);
			ft_strcat(&str[ft_strlen(s1)], s2);
			free(s1);
			free(s2);
			return (str);
		}
	return (0);
}
