#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <winsock2.h>

int main(int argc, char * argv[])
// -
// Func: This is the main thread for the server executable
// Args: Any command line arugments for the Server to observe
// Retn: Errors, if any. Else, will return a 0
// -
{
  int port_no, n, client_addr_len;
  char buffer[256];
  struct sockaddr_in server_addr, client_addr;
  int error_check;

  WSADATA wsa;
  SOCKET sock_fd = INVALID_SOCKET, new_sock_fd = INVALID_SOCKET;

  if(argc != 2) {
    fprintf(stderr, "ERROR no port provided, exiting\n");
    exit(1);
  }

  error_check = WSAStartup(MAKEWORD(2, 2), &wsa);
  if(error_check != 0) {
    fprintf(stderr, "ERROR winsock failed to initialize\n");
    exit(1);
  }

  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(sock_fd == INVALID_SOCKET) {
    fprintf(stderr, "ERROR opening socket, exiting\n");
    fprintf(stderr, "errno: %u, %s\n", WSAGetLastError(), strerror(WSAGetLastError()));
    exit(1);
  }

  fprintf(stderr, "Socket created\n");

  memset(buffer, 0, 256);

  port_no = atoi(argv[1]);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_no);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  error_check = bind(sock_fd, (struct sockaddr * ) &server_addr, sizeof(server_addr));
  if(error_check == SOCKET_ERROR) {
    fprintf(stderr, "ERROR opening bind, address already in use?\n");
    exit(1);
  }

  fprintf(stderr, "Socket Bound\n");

  error_check = listen(sock_fd, 5);
  if(error_check < 0) {
    fprintf(stderr, "ERROR failed to start listner\n");
    exit(1);
  }

  fprintf(stdout, "Server started, waiting for connection\n");

  client_addr_len = sizeof(client_addr);
  new_sock_fd = accept(sock_fd, (struct sockaddr *) &client_addr, &client_addr_len);
  fprintf(stdout, "NEW_SOCK_FD: %u\n", new_sock_fd);
  if(new_sock_fd <= 0) {
    fprintf(stderr, "ERROR failed to accept a new client\n");
    exit(1);
  }

  fprintf(stdout, "Client connected, waiting for input\n");

  n = recv(new_sock_fd, buffer, 255, 0);
  if(n == SOCKET_ERROR) {
    fprintf(stderr, "ERROR reading from socket\n");
    exit(1);
  }

  printf("Message: %s\n", buffer);

  n = send(new_sock_fd, "Message Received\n", 20, 0);
  if(n == SOCKET_ERROR) {
    fprintf(stderr, "ERROR writing to socket\n");
    exit(1);
  }

  fprintf(stdout, "Thats all folks, server shutting down\n");

  return(0);
}
