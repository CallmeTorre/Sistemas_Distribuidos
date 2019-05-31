#define MG_ENABLE_HTTP_STREAMING_MULTIPART 1
#include "mongoose.h"
#include <stdio.h>
#include <iostream>
#include "SocketDatagrama.h"
#include <chrono>
#include <string>

using namespace std;

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

static string discoverServers(char* ip){
	string result;
	SocketDatagrama socket = SocketDatagrama(0);
    int nums[2];
    nums[0] = 5;
    nums[1] = 3;

	cout << ip << endl;

    PaqueteDatagrama datagramaEnvia = PaqueteDatagrama((char *) nums, 2 * sizeof(int),ip, 7300);
    auto ini = chrono::high_resolution_clock::now();

    socket.envia(datagramaEnvia);
    PaqueteDatagrama datagramaRecibe =  PaqueteDatagrama(sizeof(int));
    while(socket.recibe(datagramaRecibe) > 0){
        auto fin = chrono::high_resolution_clock::now();
		int latencia(chrono::duration_cast<chrono::nanoseconds>(fin- ini).count());
		string cliente(datagramaRecibe.obtieneDireccion());
		result += cliente + " - " + std::to_string(latencia) + " ns. <br/>";
    }
	return result;
}

static void handle_size(struct mg_connection *nc, struct http_message *hm) {
		char query[10000];

		mg_get_http_var(&hm->body, "query", query,sizeof(query));
		strcpy(query, discoverServers(query).c_str());

		mg_send_head(nc,200,strlen(query), "Content-Type: text/plain");
		mg_printf(nc, "%s", query);
}

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
	char query[256];
 	struct http_message *hm = (struct http_message *) p;


	if (ev == MG_EV_HTTP_REQUEST) {
		if (mg_vcmp(&hm->uri, "/search") == 0) {

			mg_get_http_var(&hm->body, "query", query,sizeof(query));
			printf("IP introducida: %s\n",query);

		    handle_size(nc, hm);
		}else{
			mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
		}
	}

}

int main(void) {
	struct mg_mgr mgr;
	struct mg_connection *nc;
	mg_mgr_init(&mgr, NULL);

	printf("Starting web server on port %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		return 1;
	}
	// Set up HTTP server parameters
	mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "www"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for (;;) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);
	return 0;
}
