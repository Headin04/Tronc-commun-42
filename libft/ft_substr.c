char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	final_size;
	char	*dest;
	size_t	i;

	if (ft_strlen(s) - start > len)
		final_size = len;
	else
		final_size = ft_strlen(s) - start;
	dest = (char *)malloc(final_size * sizeof(char));
	if (dest == '\0')
		return (NULL);
	i = 0;
	else
		ft_strlcpy(dest, s, final_size);
       return(dest);	
}
