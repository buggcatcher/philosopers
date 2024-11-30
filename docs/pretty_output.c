#include <stdio.h>
#include <stdlib.h>
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define GREEN   "\033[1;32m"
#define RST 	"\033[0m"

void pretty_output(int time, int max_width, int philosopher_id, const char *event)
{
    int num_digits;
    int temp;
    int num_dots;
    int i;

    if (time == 0) {
        printf(".........0      id:%d      %s\n", philosopher_id, event);
        return;
    }
    num_digits = 0;
    temp = time;
    while (temp > 0)
    {
        temp /= 10;
        num_digits++;
    }
    num_dots = max_width - num_digits;
    i = 0;
    while (i < num_dots)
    {
        printf(".");
        i++;
    }
    printf("%d      id:%d      %s\n", time, philosopher_id, event);
}

int print_state() {
    int max_width = 10;
    int philosopher_id = 1;
    const char *event = "plato is thinking";

    printf("\nhas taken a "CYAN"fork\n"RST);
    printf("is "GREEN"eating"RST" spaghetti\n");
    printf("is "MAGENTA"sleeping\n"RST);
    printf("has "RED"died\n\n"RST);

    pretty_output(0, max_width, philosopher_id, event);
    pretty_output(7, max_width, philosopher_id, event);
    pretty_output(23, max_width, philosopher_id, event);
    pretty_output(74, max_width, philosopher_id, event);
    pretty_output(197, max_width, philosopher_id, event);
    pretty_output(523, max_width, philosopher_id, event);
    pretty_output(975, max_width, philosopher_id, event);
    pretty_output(1893, max_width, philosopher_id, event);
    pretty_output(2047, max_width, philosopher_id, event);
    pretty_output(3043, max_width, philosopher_id, event);

    return 0;
}

