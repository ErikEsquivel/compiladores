/* actualizar una serie de cuentas de clientes (sistema de
facturacion simplificado)*/
/*mantener las cuentas de clientes como un array externo de
estructuras*/

#include <stdio.h>

void leerentrada (int i);
void escribirsalida (int i);

struct fecha {
    int mes;
    int dia;
    int anio;
 };

struct cuenta {
    char nombre[50];
    char calle[50];
    char ciudad[50];
    int num_cuenta;     /* (entero positivo) */
    int tipo_cuenta;    /* A (Al día), R (atrasada) o D (delincuente) */

    float anteriorsaldo;    /* (cantidad no negativa) */
    float nuevosaldo;       /* (cantidad no negativa) */
    float pago;             /* (cantidad no negativa) */
    struct fecha ultimopago;
}   cliente[100];             /* mantener hasta 100 clientes */

int main(void)
{
    int i, n;
    printf (" SISTEMA DE FACTURACION DE CLIENTES\n \n" ) ;
    printf ("¿Cuantos clientes hay? ");
    scanf ("%d", &n);

    for (i = 0; i < n; ++i){
        leerentrada(i);    
        /* determinar el estado de la cuenta */

        if (cliente[i].pago > 0)
            cliente [i].tipo_cuenta =
                (cliente[i].pago < 0.1 * cliente[i].anteriorsaldo) ?
                'R' : 'A';
        else
            cliente[i].tipo_cuenta =
                (cliente[i].anteriorsaldo > 0) ? 'D' : 'A';
        
        /* ajustar el saldo de la cuenta */

        cliente [i] . nuevosaldo = cliente [i].anteriorsaldo
                                   - cliente [i].pago;
    }

    for (i = 0; i < n; ++i)
        escribirsalida(i);
}
    void leerentrada(int i)
/* leer datos de entrada y actualizar el registro para cada cliente */
{
    printf (" \nC1iente nº %d\n", i + 1);
    printf ("   Nombre: ");
    scanf (" %[^\n]", cliente[i].nombre);
    printf ("   Calle:  ");
    scanf(" %[^\n]", cliente[i].calle);
    printf ("   Ciudad: ");
    scanf (" %[^\n]", cliente [i].ciudad);
    printf ("   Número de cuenta:   ");
    scanf ("%d", &cliente[i].num_cuenta);
    printf ("   Saldo anterior:   ");
    scanf (" %f", &cliente[i].anteriorsaldo) ;
    printf ("   Pago actual:    ");
    scanf("%f", &cliente[i].pago);
    printf ("   Fecha de pago (mm/dd/aaaa):  ");
    scanf ( "%d/%d/%d", &cliente[i].ultimopago.mes,
                        &cliente[i].ultimopago.dia,
                        &cliente[i].ultimopago.anio);
    return;
}

void escribirsalida (int i)

/* escribir la información actual para cada cliente */
{
    printf("\nNombre: %s", cliente[i].nombre);
    printf("        Número de cuenta: %d\n", cliente[i].num_cuenta);
    printf("Calle: %s\n", cliente[i].calle);
    printf("Ciudad: %s\n\n", cliente [i] .ciudad);
    printf("Saldo anterior: %7.2f", cliente[i].anteriorsaldo);
    printf("        Pago actual: %7.2f", cliente[i].pago);
    printf("        Nuevo saldo: %7.2f\n\n", cliente[i].nuevosaldo);
    printf( "Estado de la cuenta: ");

    switch (cliente [i].tipo_cuenta) {
    case 'A':
                printf ("AL DIA\n\n");
                break;
    case 'R':
                printf("ATRASADA\n\n");
                break;
    case 'D':
                printf("DELINCUENTE\n\n");
                break;
    }
    return;
}