#include "philo.h"

int main(int argc, char **argv)
{
    t_table table;
    
    table.args = parse_argouments(argc, argv);
    print_argouments(table.args);
    init_table(&table);
    print_table(&table);
    start_dinner(&table);
    free_table(&table);


    return 0;
}
