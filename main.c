#include <stdio.h>
#include <stdlib.h>

int precioLadrillos = 20;
int precioCemento = 100;
int precioConcreto = 30;
int precioTuboPvc = 3000;
int precioMetroCable = 5;
int precioGrava = 300;
int precioArena = 400;

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
	printf("3. Vaciar compras/listas\n");
    printf("4. Salir\n");
    scanf("%d", &opc);
    return opc;
}

int insertarCantidad(){
    printf("Inserte la cantidad de materiales\n");
    int cant = 0;
    scanf("%d", &cant);
    return cant;
}

void cargar(int cantMateriales[8], int totalMateriales[8]){
    int opc = 0;
    do
    {
    system("cls");
    
    printf("Cargue la compra\n\n");
    printf("1. Ladrillos $%d.00\n", precioLadrillos);
    printf("2. Bolsa de cemento $%d.00\n", precioCemento);
    printf("3. Bloque de concreto $%d.00\n",precioConcreto);
    printf("4. Tubo PVC $%d.00\n",precioTuboPvc);
	printf("5. Metros de cable $%d.00\n",precioMetroCable);
	printf("6. Grava $%d.00\n",precioGrava);
	printf("7. Arena $%d.00\n",precioArena);
    printf("8. Finalizar compra\n");
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
	case 4:
		{
			int cant = insertarCantidad(); 
			cantMateriales[3] += cant;
			totalMateriales[3] += (cant *precioTuboPvc);
		}
		break;
	case 5:
		{
			int cant = insertarCantidad(); 
			cantMateriales[4] += cant;
			totalMateriales[4] += (cant *precioMetroCable);
		}
		break;
	case 6:
		{
			int cant = insertarCantidad(); 
			cantMateriales[5] += cant;
			totalMateriales[5] += (cant *precioGrava);
		}
		break;
	case 7:
		{
			int cant = insertarCantidad(); 
			cantMateriales[6] += cant;
			totalMateriales[6] += (cant *precioArena);
		}
		break;
    default:
        break;
    }
    } while (opc != 8);
}

void listar(int cantMateriales[8], int totalMateriales[8]){
    int opc = 0;
    do
    {
        system("cls");
    printf("Imprimir lista\n\n");
    printf("1. Cantidad de materiales\n");
    printf("2. Total de materiales\n");
    printf("3. Cantidad mayor\n");
    printf("4. Importe mayor\n");
    printf("5. Salir\n\n");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        {
			printf("\n\n");
            printf("Ladrillos: %d\n", cantMateriales[0]);
            printf("Cemento: %d\n", cantMateriales[1]);
            printf("Concreto: %d\n", cantMateriales[2]);
			printf("Tubo PVC: %d\n", cantMateriales[3]);
			printf("Metro Cable: %d\n", cantMateriales[4]);
			printf("Grava: %d\n", cantMateriales[5]);
			printf("Arena: %d\n", cantMateriales[6]);
            printf("Total: %d\n", cantMateriales[7]);
            system("PAUSE");
        }
        break;
    case 2:
        {
			printf("\n\n");
            printf("Ladrillos: $%d\n", totalMateriales[0]);
            printf("Cemento: $%d\n", totalMateriales[1]);
            printf("Concreto: $%d\n", totalMateriales[2]);
			printf("Tubo PVC: $%d\n", totalMateriales[3]);
			printf("Metro Cable: $%d\n", totalMateriales[4]);
			printf("Grava: $%d\n", totalMateriales[5]);
			printf("Arena: $%d\n", totalMateriales[6]);
            printf("Total: $%d\n", totalMateriales[7]);
            system("PAUSE");
        }
        break;
    case 3:
        {
            int i = 0;
            int aux = 0;
            for ( i = 0; i < 7; i++)
            {
                if (cantMateriales[i] > aux)
                {
                    aux = cantMateriales[i];
                }
            }
            for ( i = 0; i < 7; i++)
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
				   else if (i == 3)
				   {
				    printf("El material mas pedido es el tubo PVC con %d pedidos\n", aux);
				   }
				   else if (i == 4)
				   {
				    printf("El material mas pedido es el metro cable con %d pedidos\n", aux);
				   }
				   else if (i == 5)
				   {
				    printf("El material mas pedido es la grava con %d pedidos\n", aux);
				   }
				   else if (i == 6)
				   {
				    printf("El material mas pedido es la arena con %d pedidos\n", aux);
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
            for ( i = 0; i < 7; i++)
            {
                if (totalMateriales[i] > aux)
                {
                    aux = totalMateriales[i];
                }
            }
            for ( i = 0; i < 7; i++)
            {
                if (totalMateriales[i] == aux && totalMateriales[i] > 0)
                {
                   if (i == 0) 
                   {
                    printf("El material con mas importe son los ladrillos con $%d \n", aux);
                   }else if (i == 1)
                   {
                    printf("El material con mas importe es la bolsa de cemento con $%d \n", aux);
                   }else if (i == 2)
                   {
                    printf("El material con mas importe es el bloque de concreto con $%d \n", aux);
                   } else if (i == 3)
				   {
				    printf("El material con mas importe es el Tubo PVC con $%d \n", aux);
				   }else if (i == 4)
				   {
				    printf("El material con mas importe es el cable de metro con $%d \n", aux);
				   }else if (i == 5)
				   {
				    printf("El material con mas importe es la grava con $%d \n", aux);
				   }else if (i == 6)
				   {
				    printf("El material con mas importe es la arena con $%d\n", aux);
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

void vaciar(int cantMateriales[8], int totalMateriales[8]){
	int i = 0;
	for ( i = 0; i < 8; i++)
	{
		cantMateriales[i] = 0;
		totalMateriales[i] = 0;
	}
}

int main(){
    int cantMateriales[8] = {0, 0, 0,0,0,0,0,0};
    int totalMateriales[8] = {0, 0, 0, 0, 0, 0, 0, 0};
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
            cantMateriales[7] = cantMateriales[0] + cantMateriales[1] + cantMateriales[2] + cantMateriales[3] + cantMateriales[4] + cantMateriales[5] + cantMateriales[6];
            totalMateriales[7] = totalMateriales[0] + totalMateriales[1] + totalMateriales[2]+ totalMateriales[3] + totalMateriales[4] + totalMateriales[5] + totalMateriales[6];
            listar(cantMateriales, totalMateriales);
            break;
		case 3:
			vaciar(cantMateriales, totalMateriales);
			break;
        default:
            break;
        }
    } while (opc != 4);

    return 0;
}
