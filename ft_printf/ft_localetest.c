

#include "libftprintf.h"

void	ft_localetest(t_printf *wip, int *i, int n)
{
	if (!(ft_strnstr(wip->strloc, "UTF-8", ft_strlen(wip->strloc))) &&
	(wip->conv == S_MIN || wip->conv == C_MIN) && ((wip->flags & L_MIN) != 0))
	{
		wip->formats[n] = '\0';
		*i = n - 1;
		wip->error = 1;
	}
}
