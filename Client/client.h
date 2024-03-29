#ifndef CLIENT_H
#define CLIENT_H

#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <poll.h>
#include <signal.h>

#define MAX_MSG_LEN 1024

// #define DEBUG
void debug(const char *fmt, ...);

char is_valid_port(const char *str);
char is_valid_ip(const char *str);
int connect_to_server(char *ip, char *port);
int check_packet(char *str, char **startpoint, int socket_server);
int sender(int socket, char *packet, size_t length);
int receiver(int socket, char **buffer);

void handle_sigint(int sig);
#endif // CLIENT_H