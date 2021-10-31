typedef struct vector_t
{
    int x;
    int y;
    int z;
} vector_t;

typedef enum operations {
    sum = 0,
    sub,
    dot,
    cross,
    wrong_operatoin
} operations;

static const struct {
    operations operation;
    const char *str_operation;
} string_to_operations[] = {
    {sum,"sum"},
    {sub, "sub"},
    {dot, "dot"},
    {cross, "cross"},
};