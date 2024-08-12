#include <stdio.h>
#include "pico/stdlib.h"

/**
 * @brief Programa principal
*/
int main(void) {
	// Inicializo el USB
	stdio_init_all();
	// Demora para esperar la conexion
	sleep_ms(1000);

	// Inicializacion de GPIO con gpio_init()
	gpio_init(20);
	gpio_init(6);
	gpio_init(21);
	gpio_init(7);
	gpio_init(22);
	gpio_init(8);
	// Configuracion de entrada/salida con gpio_set_dir()
	gpio_set_dir(20, false);
	gpio_set_dir(21, false);
	gpio_set_dir(22, false);
	gpio_set_dir(6, true);
	gpio_set_dir(7, true);
	gpio_set_dir(8, true);
	//false ===> INPUT
	//true ===> OUTPUT


	while (true) {

		// Resolver logica para GPIO20 -> GPIO6

		//forma resumida
		//gpio_put(6, !gpio_get(20));

		
		//if(!gpio_get(21)) {
		//	gpio_put(7, !gpio_get(7));
		//}

		if(gpio_get(20)==1){		
			gpio_put(6, false);
		}
		else{
			gpio_put(6, true);
		}
		// Resolver logica para GPIO21 -> GPIO7
		if(gpio_get(21)==0 && gpio_get(7)==false){		
			gpio_put(7, true);
			sleep_ms(200);
		}
	    else if(gpio_get(21)==0 && gpio_get(7)==true){
			gpio_put(7, false);
			sleep_ms(200);
		}
		
		// Resolver logica para GPIO22 -> GPIO8
		if(gpio_get(22)==0 && gpio_get(8)==false){		
			gpio_put(8, true);
			sleep_ms(500);
		}
	    else if(gpio_get(22)==0 && gpio_get(8)==true){
			gpio_put(8, false);
			sleep_ms(500);

		}
	}
	return 0;
}