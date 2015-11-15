#include <winsock.h>
#include "network.h"

int open_socket(int socket_fd)
// -
// Opens the socket into the socket_fd
// -
{
  socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
}

int send_message(int socket_fd, struct message_buffer msg_buf)
// -
// If the socket is open, sends the message buffer to the socket
// -
{

}

int get_message(int socket_fd, struct message_buffer msg_buf)
// -
// If the socket is open, receives a message and loads it
// into the message buffer
// -
{

}

int close_socket(int socket_fd)
// -
// Closes the socket from the socket_fd
// -
{

}
