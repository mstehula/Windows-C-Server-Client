#ifndef SERVER_H_
#define SERVER_H_

struct settings
{
  int debug_level;
  int stop_on_startup;
  int active_connections;
};

void default(struct * settings) {

}

int start_server(struct settings)
{

}

void stop_server(int server_id)
{

}

#endif //SERVER_H_
