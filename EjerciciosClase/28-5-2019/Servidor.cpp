#include "SocketDatagrama.h"

using namespace std;

int main(int argc, char const *argv[]){
	SocketDatagrama socket = SocketDatagrama(7300);
    int * nums;

    while(1){
    	PaqueteDatagrama datagramaRecibe = PaqueteDatagrama( 2 * sizeof(int));
	    if(socket.recibe(datagramaRecibe) > 0){
			nums = (int *) datagramaRecibe.obtieneDatos();

			int resultado;
			resultado = nums[0] + nums[1];
			cout << "Cliente: " << datagramaRecibe.obtieneDireccion() << endl;
			cout << "Puerto: " << datagramaRecibe.obtienePuerto() << endl;
			PaqueteDatagrama datagramaEnvia =  PaqueteDatagrama((char*) &resultado, sizeof(int), datagramaRecibe.obtieneDireccion(), datagramaRecibe.obtienePuerto());
			socket.envia(datagramaEnvia);
		}
	}

	return 0;
}