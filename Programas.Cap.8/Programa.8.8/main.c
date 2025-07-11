#include <stdio.h>
#include <string.h>

typedef struct {
    char cal[20];  
    int num;     
    char col[20]; 
    char cp[6];  
    char ciu[20]; 
} domicilio;

typedef struct {
    char nom[20];    
    int edad;
    char sexo;
    int con;        
    domicilio dom;  
    char tel[11];   
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100]; 
    int TAM;

    do {
        printf("Ingrese el número de pacientes: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\t\tPaciente %d\n", I + 1);
        fflush(stdin);
        printf("Nombre: ");
        gets(A[I].nom);

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        fflush(stdin);
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);

        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);
        fflush(stdin);

        printf("Calle: ");
        gets(A[I].dom.cal);

        printf("Número: ");
        scanf("%d", &A[I].dom.num);
        fflush(stdin);

        printf("Colonia: ");
        gets(A[I].dom.col);

        printf("Código Postal: ");
        gets(A[I].dom.cp);

        printf("Ciudad: ");
        gets(A[I].dom.ciu);

        printf("Teléfono: ");
        gets(A[I].tel);
    }
}

void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].sexo) {
            case 'F':
            case 'f':
                FEM++;
                break;
            case 'M':
            case 'm':
                MAS++;
                break;
        }
    }

    int TOT = FEM + MAS;

    if (TOT == 0) {
        printf("\nNo hay datos suficientes para calcular porcentajes.\n");
        return;
    }

    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;

    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }

    printf("\nNúmero pacientes en condición 1: %d", C1);
    printf("\nNúmero pacientes en condición 2: %d", C2);
    printf("\nNúmero pacientes en condición 3: %d", C3);
    printf("\nNúmero pacientes en condición 4: %d", C4);
    printf("\nNúmero pacientes en condición 5: %d", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad:\n");
    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("Nombre: %s\tTeléfono: %s\n", A[I].nom, A[I].tel);
        }
    }
}
