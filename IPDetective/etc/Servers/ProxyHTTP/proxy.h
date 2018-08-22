


int proxy_callback(char *host, char *headers, int client_sock);

extern void proxy_start(int port, char *extproxyaddr, int extproxyport, int (*callback)(), int comeback, int singlethread);

