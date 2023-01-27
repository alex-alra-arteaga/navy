/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** Sink the float simulator by terminal
*/

#include "../includes/my.h"
#include "../includes/ships.h"

bool check_parse_01(char **line)
{
    for (int i = 0; line[i]; i++) {
        if (my_strlen(line[i]) != 8) {
            return (true);
        }
        if (line[i][0] < '2' || line[i][0] > '5' || line[i][1] != ':' ||
            line[i][4] != ':' || line[i][2] < 'A' || line[i][2] > 'H' ||
            line[i][3] < '1' || line[i][3] > '8' || line[i][6] < '1' ||
            line[i][6] > '8' || line[i][5] < 'A' || line[i][5] > 'H')
            return (true);
        if (line[i][2] == line[i][5]
            && line[i][6] - line[i][3] != (int)line[i][0] - 1 - 48)
            return (true);
        if (line[i][2] != line[i][5] && line[i][6] != line[i][3])
            return (true);
        if (line[i][2] != line[i][5]
        && line[i][5] - line[i][2] != (int)line[i][0] - 1 - 48)
            return (true);
    }
    return (false);
}

bool check_parse(char **line)
{
    char ocurrance;
    bool error;
    int cnt = 0;

    for (int j = 0; line[j]; j++) {
        if (j == 4)
            return (true);
    }
    error = check_parse_01(line);
    for (int c = 0; line[c]; c++) {
        ocurrance = line[c][0];
        for (int l = 0; line[l]; l++)
            (line[l][0] == ocurrance) ? (cnt++) : (l += 0);
        if (cnt > 1)
            return (true);
        cnt = 0;
    }
    return (error);
}
