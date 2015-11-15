#include <winsock.h>
#include "network.h"

int open_socket(int * socket_fd)
// -
// Opens the socket into the socket_fd
// -
{
  return *socket_fd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
}

int send_message(int * socket_fd, struct message_buffer msg_buf)
// -
// If the socket is open, sends the message buffer to the socket
// -
{

}

int get_message(int * socket_fd, struct message_buffer msg_buf)
// -
// If the socket is open, receives a message and loads it
// into the message buffer
// -
{

}

int close_socket(int * socket_fd)
// -
// Closes the socket from the socket_fd
// -
{
  return closesocket(*socket_fd);
}
