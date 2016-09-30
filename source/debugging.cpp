#include <string>
#include "socket/socket.hpp"

int log(std::string msg)
{
	Socket s;
	s.open("127.0.0.1", 25555);
	s.write("test message");
	s.close();
}