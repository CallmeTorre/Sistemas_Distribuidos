#include "SocketDatagrama.h"

using namespace std;

int main(int argc, char const *argv[]){
	SocketDatagrama socket = SocketDatagrama(0);
    int nums[2];
    nums[0] = 5;
    nums[1] = 3;

    PaqueteDatagrama datagramaEnvia = PaqueteDatagrama((char *) nums, 2 * sizeof(int),"127.0.0.1", 7300);
    socket.envia(datagramaEnvia);
    
    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
    socket.recibe(datagramaRecibe);
    int * res = (int * ) datagramaRecibe.obtieneDatos();
    cout << nums[0] << " + " << nums[1] << " = " << *res <<endl;
    return 0;
}