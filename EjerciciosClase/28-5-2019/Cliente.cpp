#include "SocketDatagrama.h"

using namespace std;

int main(int argc, char const *argv[]){
	SocketDatagrama socket = SocketDatagrama(0);
    int nums[2];
    nums[0] = 5;
    nums[1] = 3;

    PaqueteDatagrama datagramaEnvia = PaqueteDatagrama((char *) nums, 2 * sizeof(int),"10.100.95.255", 7300);
    socket.envia(datagramaEnvia);
    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
    for(;;){
        if(socket.recibe(datagramaRecibe) > 0){
            int * res = (int * ) datagramaRecibe.obtieneDatos();
            cout << "Cliente: " << datagramaRecibe.obtieneDireccion() << endl;
            cout << "Puerto: " << datagramaRecibe.obtienePuerto() << endl;
            cout << nums[0] << " + " << nums[1] << " = " << *res <<endl;
        }
        else{
            break;
        }
    }
    return 0;
}