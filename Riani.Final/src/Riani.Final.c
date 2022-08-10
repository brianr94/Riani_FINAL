/*
 ============================================================================
 Name        : Final.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "ePokemon.h"
#include "utn_inputs.h"

int main(void) {
	setbuf(stdout,NULL);

	LinkedList* listaPokemon;
	int opcion;
	int flagCargado;
//	int flagGuardado;

	flagCargado=0;
//	flagGuardado=0;

	listaPokemon=ll_newLinkedList();

	do
	{
		pedirNumeroEnteroValidado(&opcion,
											"-------------------------\n"
											"1. cargar archivo pokemones\n"
											"2. modificar valor ataque\n"
											"3. imprimir pokemones\n"
											"4. filtrar por tipo fuego\n"
											"5. filtrar por extra grandes de tipo veneno\n"
											"6. mapear ataque cargado\n"
											"7. batalla Pokemon\n"
											"8. Salir\n"
											"---------------------------\n"
											"Ingrese una opcion: ",
											"---------------------------\n"
											"1. cargar archivo pokemones\n"
											"2. modificar valor ataque\n"
											"3. imprimir pokemones\n"
											"4. filtrar por tipo fuego\n"
											"5. filtrar por extra grandes de tipo veneno\n"
											"6. mapear ataque cargado\n"
											"7. batalla Pokemon\n"
											"8. Salir\n"
											"----------------------------\n"
											"Error. Ingrese una opcion correcta: ", 1, 8);

		switch(opcion)
		{
			case 1:
				if(flagCargado == 0)
				{
					if(riani_controller_validateLoadFromText("Data_Pokemones.csv", listaPokemon) != -1)
					{
						flagCargado=1;
					}

				}
				else
				{
					printf("\nEl arhivo ya fue cargado!!!\n");
				}

				break;
			case 2:
				if(flagCargado == 1)
				{
					riani_controller_modificarValorAtaque(listaPokemon);
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 3:
				if(flagCargado == 1)
				{
					riani_controller_listarPokemones(listaPokemon);
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 4:
				if(flagCargado == 1)
				{
					riani_controller_filtrarPorFuego(listaPokemon);
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 5:
				if(flagCargado == 1)
				{
					riani_controller_filtrarPorTamanioYVeneno(listaPokemon);
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 6:
				if(flagCargado == 1)
				{
					printf("\nNuevos valores aignados!!!\n");
					if(riani_controller_asignarNuevoValorAtaque(listaPokemon)!= -1)
					{
						riani_controller_listarPokemones(listaPokemon);
					}
				}
				else
				{
					printf("\nPrimero debe cargarse el archivo (opcion 1)!!!\n");
				}
				break;
			case 7:

				break;

			case 8:
				ll_deleteLinkedList(listaPokemon);
				printf("\nElegio salir del programa....\n");
				break;
		}

		if(opcion != 7)
		{
			system("pause");
		}

	}while(opcion != 7);


	return EXIT_SUCCESS;
}
