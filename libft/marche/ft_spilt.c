#include "libft.h"

size_t  get_nb_word(char const *s, char c)
{
    size_t  i;

    i = 0;
    while (s)
    {
        if ((s[i] != c && s[i + 1] == c) || s[i + 1] == '\0')
        i++;
    }
    return (i);
}

char    **ft_split(char const *s, char c)
{
    char    **split;
    size_t  nb_word;
    size_t  slen;

    nb_word = get_nb_worb(s, c,);
    slen = ft_strlen(s);
    split = (char **)malloc(nb_word * sizeof(char *));
    if (split)
    {
        
    }

}