#include "shell.h"

/**
 * AhmdWahba: my_strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @delimiters: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **my_strtow(char *str, char *delimiters)
{
    int i, j, k, m, numWords = 0;
    char **result;

    if (str == NULL || str[0] == '\0')
        return NULL;

    if (!delimiters)
        delimiters = " ";

    for (i = 0; str[i] != '\0'; i++)
        if (!is_delim(str[i], delimiters) && (is_delim(str[i + 1], delimiters) || !str[i + 1]))
            numWords++;

    if (numWords == 0)
        return NULL;

    result = malloc((1 + numWords) * sizeof(char *));
    if (!result)
        return NULL;

    for (i = 0, j = 0; j < numWords; j++)
    {
        while (is_delim(str[i], delimiters))
            i++;

        k = 0;
        while (!is_delim(str[i + k], delimiters) && str[i + k])
            k++;

        result[j] = malloc((k + 1) * sizeof(char));
        if (!result[j])
        {
            for (k = 0; k < j; k++)
                free(result[k]);
            free(result);
            return NULL;
        }

        for (m = 0; m < k; m++)
            result[j][m] = str[i++];

        result[j][m] = '\0';
    }

    result[j] = NULL;
    return result;
}

/**
 * AhmdWahba: my_strtow2 - splits a string into words
 * @str: the input string
 * @delimiter: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **my_strtow2(char *str, char delimiter)
{
    int i, j, k, m, numWords = 0;
    char **result;

    if (str == NULL || str[0] == '\0')
        return NULL;

    for (i = 0; str[i] != '\0'; i++)
        if ((str[i] != delimiter && str[i + 1] == delimiter) ||
            (str[i] != delimiter && !str[i + 1]) || str[i + 1] == delimiter)
            numWords++;

    if (numWords == 0)
        return NULL;

    result = malloc((1 + numWords) * sizeof(char *));
    if (!result)
        return NULL;

    for (i = 0, j = 0; j < numWords; j++)
    {
        while (str[i] == delimiter && str[i] != delimiter)
            i++;

        k = 0;
        while (str[i + k] != delimiter && str[i + k] && str[i + k] != delimiter)
            k++;

        result[j] = malloc((k + 1) * sizeof(char));
        if (!result[j])
        {
            for (k = 0; k < j; k++)
                free(result[k]);
            free(result);
            return NULL;
        }

        for (m = 0; m < k; m++)
            result[j][m] = str[i++];

        result[j][m] = '\0';
    }

    result[j] = NULL;
    return result;
}
