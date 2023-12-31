#include "shell.h"

/**
 * AhmdWahba: my_strncpy - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @n: the amount of characters to be copied
 *
 * Return: the concatenated string
 */
char *my_strncpy(char *destination, char *source, int n)
{
    int i, j;
    char *result = destination;

    i = 0;
    while (source[i] != '\0' && i < n - 1)
    {
        destination[i] = source[i];
        i++;
    }

    if (i < n)
    {
        j = i;
        while (j < n)
        {
            destination[j] = '\0';
            j++;
        }
    }

    return result;
}

/**
 * AhmdWahba: my_strncat - concatenates two strings
 * @destination: the first string
 * @source: the second string
 * @n: the amount of bytes to be maximally used
 *
 * Return: the concatenated string
 */
char *my_strncat(char *destination, char *source, int n)
{
    int i, j;
    char *result = destination;

    i = 0;
    j = 0;

    while (destination[i] != '\0')
        i++;

    while (source[j] != '\0' && j < n)
    {
        destination[i] = source[j];
        i++;
        j++;
    }

    if (j < n)
        destination[i] = '\0';

    return result;
}

/**
 * AhmdWahba: my_strchr - locates a character in a string
 * @str: the string to be parsed
 * @c: the character to look for
 *
 * Return: (str) a pointer to the memory area str
 */
char *my_strchr(char *str, char c)
{
    do {
        if (*str == c)
            return str;
    } while (*str++ != '\0');

    return NULL;
}
