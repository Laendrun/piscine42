#include <stdio.h>

char *ft_strcapitalize(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		int uppercase;
		if (str[i]
	}	

	/* this will not work...
	if str[i-1] >= ' ' && str[i -1] <= '/'{
		str[i] = str[i] + 32
	}
	if str[i-1] >= ':' && str[i-1] <= '@' 
	{	
	str[i] = capitalize
	}	
	if str[i-1] >= '[' && str[i-1] <= '`'
	{	
	str[i] = capitalize
	}	
	if str[i-1] >= '{' && str[i-1] <= '~' 
	{}
	*/
}

int main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+1";
	char expected_output[] = "Salut, Comment tu vas ? 42mots Quarante-Deux; Cinquante+Et+Un";
	printf("%s", ft_strcapitalize(str);
}
