/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:50:23 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:42:30 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

/*
Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f.
use ; malloc
return: The string created from the successive applications
of ’f’.Returns NULL if the allocation fails
*/

//sample ft
// char	ft_toupper(unsigned int a, char b)
// {
// 		if (a >= 0)
// 		{
// 			if (b >= 'a' && b <= 'z')
// 				b = b - 32;
// 		}
// 		return (b);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*new;
	char	result;

	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result = f(i, s[i]);
		new[i] = result;
		i++;
	}
	new[i] = '\0';
	return (new);
}

// int	main(void)
// {
// 	char * string = "Hello";
// 	char * new = ft_strmapi(string, ft_toupper);
// 	printf("og: %s\n", string);
// 	printf("new: %s\n", new);
// }