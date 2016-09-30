#include <string>
#include <stdlib.h>
#include "socket/socket.hpp"

void log(std::string msg)
{
	Socket s;
	s.open("127.0.0.1", 25555);
	s.write(msg + "\n");
	printf("%s\n", msg.c_str());
	s.close();
}