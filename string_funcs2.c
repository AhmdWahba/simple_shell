#include "shell.h"

/**
 * AhmdWahba: my_strcpy - copies a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */
char *my_strcpy(char *destination, char *source)
{
    int i = 0;

    if (destination == source || source == NULL)
        return destination;
    
    while (source[i])
    {
        destination[i] = source[i];
        i++;
    }
    
    destination[i] = '\0';
    return destination;
}

/**
 * AhmdWahba: my_strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *my_strdup(const char *str)
{
    int length = 0;
    char *result;

    if (str == NULL)
        return NULL;

    while (*str++)
        length++;
    
    result = malloc(sizeof(char) * (length + 1));

    if (!result)
        return NULL;

    for (length++; length--;)
        result[length] = *--str;

    return result;
}

/**
 * AhmdWahba: my_puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void my_puts(char *str)
{
    int i = 0;

    if (!str)
        return;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
}

/**
 * AhmdWahba: my_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int my_putchar(char c)
{
    static int i;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buffer, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buffer[i++] = c;

    return 1;
}
