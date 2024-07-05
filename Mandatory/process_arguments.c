/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:42 by oer-refa          #+#    #+#             */
/*   Updated: 2024/07/05 09:37:39 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **process_arguments(int argc, char **argv)
{
    int total_numbers;
    char **numbers;

    if (!has_non_whitespace_arg(argc, argv))
        return NULL;

    total_numbers = count_total_numbers(argc, argv);
    if (total_numbers == 0)
        return NULL;

    numbers = allocate_and_fill_numbers(argc, argv, total_numbers);
    return numbers;
}

int count_total_numbers(int argc, char **argv)
{
    int total_numbers = 0;
    char *arg;
    int arg_len;
    int i;
    int j;

    
    i = 1;
    arg = argv[i];
    arg_len = ft_strlen(arg);
    while (i < argc)
    {
        j = 0;
        while (j < arg_len)
        {
            while (j < arg_len && ft_isspace(arg[j]))
                j++;
            if (j == arg_len)
                break;
            if (ft_isdigit(arg[j]) || ((arg[j] == '-' || arg[j] == '+') && 
                j + 1 < arg_len && ft_isdigit(arg[j+1])))
            {
                total_numbers++;
                while (j < arg_len && !ft_isspace(arg[j]))
                    j++;
            }
            else
                j++;
        }
        i++;
    }
    return total_numbers;
}

char **allocate_and_fill_numbers(int argc, char **argv, int total_numbers)
{
    char **numbers;
    char *arg;
    int arg_len;
    int start;
    int k;
    int i;
    int j;
    
    numbers = malloc(sizeof(char *) * (total_numbers + 1));
    if (!numbers)
        return NULL;
    k = 0;
    i = 1;
    while (i < argc && k < total_numbers)
    {
        arg = argv[i];
        arg_len = ft_strlen(arg);
        j = 0;
        while (j < arg_len && k < total_numbers)
        {
            while (j < arg_len && ft_isspace(arg[j]))
                j++;
            if (j == arg_len)
                break;
            if (ft_isdigit(arg[j]) || ((arg[j] == '-' || arg[j] == '+') && 
                j + 1 < arg_len && ft_isdigit(arg[j+1])))
            {
                start = j;
                while (j < arg_len && !ft_isspace(arg[j]))
                    j++;
                numbers[k] = malloc(j - start + 1);
                if (!numbers[k])
                {
                    free_numbers_array(numbers, k);
                    return NULL;
                }
                ft_strncpy(numbers[k], arg + start, j - start);
                numbers[k][j - start] = '\0';
                k++;
            }
            else
                j++;
        }
        i++;
    }
    numbers[k] = NULL;
    return numbers;
}

int has_non_whitespace_arg(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_isspace(argv[i][j]))
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

void free_numbers_array(char **numbers, int count)
{
    int i;
    
    i = 0;
    while (i < count)
    {
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
