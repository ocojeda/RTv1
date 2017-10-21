# include "rtv1.h"

int main (int argc, char **argv)
{
    t_rt    e;

    init_rt(&e);
    parse(&e, argc, argv);
    ft_start_rt(&e);
    return 0;
}