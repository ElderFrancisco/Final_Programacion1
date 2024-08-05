#include <stdio.h>
#include <stdlib.h>

int precioLadrillos = 20;
int precioCemento = 100;
int precioConcreto = 30;

void saludo(){
    printf("Bienvenido al Software de empleados de Lomo Negra\n\n");
    system("PAUSE");
}

int menu(){
    system("cls");
    int opc = 0;
    printf("MENU PRINCIPAL\n\n");
    printf("1. Cargar compra\n");
    printf("2. Imprimir lista\n");
    printf("3. Salir\n");
    scanf("%d", &opc);
    return opc;
}

int insertarCantidad(){
    printf("Inserte la cantidad de materiales\n");
    int cant = 0;
    scanf("%d", &cant);
    return cant;
}

void cargar(int cantMateriales[4], int totalMateriales[4]){
    int opc = 0;
    do
    {
    system("cls");
    
    printf("Cargue la compra\n\n");
    printf("1. Ladrillos $%d.00\n", precioLadrillos);
    printf("2. Bolsa de cemento $%d.00\n", precioCemento);
    printf("3. Bloque de concreto $%d.00\n",precioConcreto);
    printf("4. Finalizar compra\n");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        {
            int cant = insertarCantidad(); 
            cantMateriales[0] += cant;
            totalMateriales[0] += (cant * precioLadrillos);
        }
        break;
    case 2:
        {
            int cant = insertarCantidad(); 
            cantMateriales[1] += cant;
            totalMateriales[1] += (cant * precioCemento);
        }
        break;
    case 3:
        {
            int cant = insertarCantidad(); 
            cantMateriales[2] += cant;
            totalMateriales[2] += (cant *precioConcreto);
        }
        break;
    default:
        break;
    }
    } while (opc != 4);
}

void listar(int cantMateriales[4], int totalMateriales[4]){
    int opc = 0;
    do
    {
        system("cls");
    printf("Imprimir lista\n\n");
    printf("1. Cantidad de materiales\n");
    printf("2. Total de materiales\n");
    printf("3. Cantidad mayor\n");
    printf("4. Total mayor\n");
    printf("5. Salir\n\n");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        {
            printf("Ladrillos: %d\n", cantMateriales[0]);
            printf("Cemento: %d\n", cantMateriales[1]);
            printf("Concreto: %d\n", cantMateriales[2]);
            printf("Total: %d\n", cantMateriales[3]);
            system("PAUSE");
        }
        break;
    case 2:
        {
            printf("Ladrillos: %d\n", totalMateriales[0]);
            printf("Cemento: %d\n", totalMateriales[1]);
            printf("Concreto: %d\n", totalMateriales[2]);
            printf("Total: %d\n", totalMateriales[3]);
            system("PAUSE");
        }
        break;
    case 3:
        {
            int i = 0;
            int aux = 0;
            for ( i = 0; i < 3; i++)
            {
                if (cantMateriales[i] > aux)
                {
                    aux = cantMateriales[i];
                }
            }
            for ( i = 0; i < 3; i++)
            {
                if (cantMateriales[i] == aux && cantMateriales[i] > 0)
                {
                   if (i == 0) 
                   {
                    printf("El material mas pedido son los ladrillos con %d pedidos\n", aux);
                   }else if (i == 1)
                   {
                    printf("El material mas pedido es la bolsa de cemento con %d pedidos\n", aux);
                   }else if (i == 2)
                   {
                    printf("El material mas pedido es el bloque de concreto con %d pedidos\n", aux);
                   }
                }
            }
            system("PAUSE");
        }
        break;
    case 4:
        {
            int i = 0;
            int aux = 0;
            for ( i = 0; i < 3; i++)
            {
                if (totalMateriales[i] > aux)
                {
                    aux = totalMateriales[i];
                }
            }
            for ( i = 0; i < 3; i++)
            {
                if (totalMateriales[i] == aux && totalMateriales[i] > 0)
                {
                   if (i == 0) 
                   {
                    printf("El material con mas recaudacion son los ladrillos con %d vendidos\n", aux);
                   }else if (i == 1)
                   {
                    printf("El material con mas recaudacion es la bolsa de cemento con %d vendidos\n", aux);
                   }else if (i == 2)
                   {
                    printf("El material con mas recaudacion es el bloque de concreto con %d vendidos\n", aux);
                   }
                }
            }
            system("PAUSE");
        }
        break;
    default:
        break;
    }
    } while (opc != 5);
}

int main(){
    int cantMateriales[4] = {0, 0, 0,0};
    int totalMateriales[4] = {0, 0, 0, 0};
    saludo();    
    int opc = 0;
    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            cargar(cantMateriales, totalMateriales); 
            break;
        case 2:
            cantMateriales[3] = cantMateriales[0] + cantMateriales[1] + cantMateriales[2];
            totalMateriales[3] = totalMateriales[0] + totalMateriales[1] + totalMateriales[2];
            listar(cantMateriales, totalMateriales);
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (opc != 3);

    return 0;
}
