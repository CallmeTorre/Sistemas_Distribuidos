#include "SocketDatagrama.h"
#include <chrono>

using namespace std;

int main(int argc, char const *argv[]){
	SocketDatagrama socket = SocketDatagrama(0);
    int nums[2];
    nums[0] = 5;
    nums[1] = 3;

    PaqueteDatagrama datagramaEnvia = PaqueteDatagrama((char *) nums, 2 * sizeof(int),"10.100.95.255", 7300);
    auto ini = chrono::high_resolution_clock::now();

    socket.envia(datagramaEnvia);
    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
    while(socket.recibe(datagramaRecibe) > 0){
        auto fin = chrono::high_resolution_clock::now();
        int * res = (int * ) datagramaRecibe.obtieneDatos();
        cout << "Cliente: " << datagramaRecibe.obtieneDireccion() << endl;
        cout << "Puerto: " << datagramaRecibe.obtienePuerto() << endl;
        cout << nums[0] << " + " << nums[1] << " = " << *res <<endl;
        cout << "Latencia: " << chrono::duration_cast<chrono::nanoseconds>(fin- ini).count() << " ms" <<endl;
    }
    return 0;
}