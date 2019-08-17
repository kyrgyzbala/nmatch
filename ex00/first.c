#include <stdio.h>

int	match(char *s1, char *s2)
{
	int	i;
	int	j;
	
	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	if (s2[i] == '*' && s2[i + 1] == '\0' && s1[i] != '\0')
		return (1);
	if (s2[i] == '*' && s2[i + 1] != '\0')
	{
		j = i + 1;
		while (s1[i] != s2[j] && s1[i] != '\0')
			i++;
		if (s1[i] == '\0')
			return (0);
		while (s1[i] != '\0' || s2[j] != '\0')
		{
			if (s1[i] != s2[j])
				return (0);
			i++;
			j++;
		}
		return (1);
	}
	return (0);
}

int main(){
    char str[] = "nnnNurik";
    char nn[] = "*urik ";

    printf("%d \n", match(str,nn));
    return 0;
}
