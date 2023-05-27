char	*ft_itoa_base(int n, char *base)
{
	int		i;
	int		len;
	int		tmp;
	char	*res;

	if (n == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	len = 0;
	tmp = n;
	while (tmp != 0)
	{
		len++;
		tmp /= ft_strlen(base);
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		tmp = n % ft_strlen(base);
		if (res[i]
		
	}
}
