
struct message_buffer {
  char head;
  char * body;
  char tail;
};

int open_socket(int * socket_fd);
int send_message(int * socket_fd, struct message_buffer msg_buf);
int get_message(int * socket_fd, struct message_buffer msg_buf);
int close_socket(int * socket_fd);
