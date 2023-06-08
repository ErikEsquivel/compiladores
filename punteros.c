#include <stdio.h>

int main(void)
{
    int u = 3;
    int v;
    int *pu;    /* puntero a un entero */
    int *pv;    /* puntero a un entero */
    pu = &u;    /* asigna dirección de u a pu */
    v = *pu;    /* asigna valor de u a v */
    pv = &v;    /* asigna dirección de v a pv */
    printf("\n\nu=%d    &u=%p    pu=%p  *pu=%d", u, &u, pu, *pu);
    printf("\n\nv=%d    &v=%p    pv=%p  *pv=%d\n", v, &v, pv, *pv);
}