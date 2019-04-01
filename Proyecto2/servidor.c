#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
    int num;
    int s, res, clilen;
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
    for(;;){
        int a = 10;
        for(int i = 1; i <= 5; i++){
            recvfrom(s, (int *) &num, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
            printf("%d\n", num);
        }
        printf("%d\n", a);
        /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
        sendto(s, (int *)&a, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}
