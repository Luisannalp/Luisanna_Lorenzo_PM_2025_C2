#include <stdio.h>
#include <string.h>

/* Vendedores.
   El programa maneja información sobre las ventas de artículos domésticos. */

typedef struct
{
    char noba[10];   // Nombre del banco
    char nucu[10];   // Número de cuenta
} banco;

typedef union
{
    banco che;       // Cheque
    banco nomi;      // Nómina
    char venta;      // Ventanilla
} fpago;

typedef struct
{
    char cnu[20];    // Calle y número
    char col[20];    // Colonia
    char cp[5];      // Código postal
    char ciu[15];    // Ciudad
} domicilio;

typedef struct
{
    int num;               // Número de vendedor
    char nom[20];          // Nombre
    float ven[12];         // Ventas por mes
    domicilio domi;        // Domicilio
    float sal;             // Salario
    fpago pago;            // Forma de pago
    int cla;               // Clave forma de pago (1,2,3)
} vendedor;

/* Prototipos */
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

int main(void)
{
    vendedor VENDEDORES[100];
    int TAM;

    do
    {
        printf("Ingrese el número de vendedores: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA\n");
    return 0;
}

void Lectura(vendedor A[], int T)
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        printf("\n\tIngrese datos del vendedor %d\n", I + 1);
        printf("Número de vendedor: ");
        scanf("%d", &A[I].num);
        fflush(stdin);
        printf("Nombre del vendedor: ");
        gets(A[I].nom);

        printf("Ventas del año:\n");
        for (J = 0; J < 12; J++)
        {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }

        printf("Domicilio del vendedor:\n");
        fflush(stdin);
        printf("\tCalle y número: ");
        gets(A[I].domi.cnu);
        printf("\tColonia: ");
        gets(A[I].domi.col);
        printf("\tCódigo Postal: ");
        gets(A[I].domi.cp);
        printf("\tCiudad: ");
        gets(A[I].domi.ciu);

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);

        printf("Forma de Pago (Banco-1 Nómina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        fflush(stdin);

        switch (A[I].cla)
        {
        case 1:
            printf("\tNombre del banco: ");
            gets(A[I].pago.che.noba);
            printf("\tNúmero de cuenta: ");
            gets(A[I].pago.che.nucu);
            break;
        case 2:
            printf("\tNombre del banco: ");
            gets(A[I].pago.nomi.noba);
            printf("\tNúmero de cuenta: ");
            gets(A[I].pago.nomi.nucu);
            break;
        case 3:
            A[I].pago.venta = 'S';
            break;
        }
    }
}

void F1(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\n\t\tVentas Totales de los Vendedores\n");
    for (I = 0; I < T; I++)
    {
        printf("\nVendedor: %d", A[I].num);
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        printf("\nVentas: %.2f\n", SUM);
    }
}

void F2(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$\n");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM > 1500000.00)
        {
            A[I].sal = A[I].sal * 1.05;
            printf("\nNúmero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f\n",
                   A[I].num, SUM, A[I].sal);
        }
    }
}

void F3(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\n\t\tVendedores con Ventas < 300,000\n");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM < 300000.00)
            printf("\nNúmero de empleado: %d\nNombre: %s\nVentas: %.2f\n",
                   A[I].num, A[I].nom, SUM);
    }
}

void F4(vendedor A[], int T)
{
    int I;
    printf("\n\t\tVendedores con Cuenta en el Banco\n");
    for (I = 0; I < T; I++)
    {
        if (A[I].cla == 1)
        {
            printf("\nNúmero de vendedor: %d\nBanco: %s\nCuenta: %s\n",
                   A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
        }
    }
}
