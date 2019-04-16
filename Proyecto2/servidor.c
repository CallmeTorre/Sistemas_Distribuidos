#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
    int num, s, clilen;
    struct sockaddr_in server_addr, msg_to_client_addr;
    s = socket(AF_INET, SOCK_DGRAM, 0);

    /* se asigna una direccion al socket del servidor*/
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
    clilen = sizeof(msg_to_client_addr);
    printf("Servidor Encendido\n");
    int expected = 1;
    float failed_packages = 0;
    for(;;){
        recvfrom(s, (int *) &num, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
        if(expected == num){
            expected++;
        }else if(num == 0){
            break;
        }
        else{
            expected = num + 1;
            failed_packages++;
        }
    }
    printf("Paquetes perdidos: %f\n", failed_packages);
    printf("Porcentaje de paquetes perdidos: %f\n", 100 - (failed_packages * 100) / (expected - 1));
    /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
    sendto(s, (int *)&failed_packages, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
    return 0;
}
