#ifndef CALC_H
#define CALC_H

/**
 * struct op - Struct op
 *
 * @op: opérateur
 * @f: la fonction associé
 *
 * Description: Structure qui associe un opérateur à sa fonction.
 */
typedef struct op
{
char *op;
int (*f)(int a, int b);
} op_t;

/* Prototype pour operations */
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/* Prototype pour menu */
int (*get_op_func(char *s))(int, int);

#endif
