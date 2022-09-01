char *ft_strlowcase(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] + 32;
		}
		else
		{
			str[i] = str[i];
		}
	}
	return str;
}
