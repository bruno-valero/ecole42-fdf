#include <stdio.h>
#include <stdlib.h>

typedef struct s_data	t_data;

struct s_data {
    int 	x;
	t_data	**self_ref;
};

void destroy_good(t_data **data) // sua primeira versão
{
    free(*data);
    *data = NULL;
}

void destroy_bad(t_data *data) // sua segunda versão
{
    t_data **ref = &data;
    free(*ref);
    *ref = NULL;
}

t_data	*new_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	(*data)->x = 0;
	(*data)->self_ref = data;
	return (*data);
}

void	handle_destroy(t_data *data)
{
	t_data	**self_ref;

	self_ref = data->self_ref;
	free(*self_ref);
	*self_ref = NULL;
}

int main(void)
{
    t_data *a;
    t_data *b;

	a = new_data(&a);
	b = new_data(&b);

    printf("Antes:\n");
    printf("a = %p\n", (void*)a);
    printf("b = %p\n", (void*)b);

    // destroy_good(&a); // boa: passa &a
    // destroy_bad(b);   // ruim: passa apenas b
	handle_destroy(a);
	handle_destroy(b);

    printf("\nDepois:\n");
    printf("a = %p\n", (void*)a);
    printf("b = %p\n", (void*)b);

    return 0;
}
