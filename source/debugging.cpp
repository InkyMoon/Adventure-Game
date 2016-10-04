#include <string>
#include <stdlib.h>
#include "../socket/socket.hpp"
#include "config.hpp"

void log(std::string msg)
{
	#ifdef LOGGING
	#ifdef NET_LOGGING
	Socket s;
	if (s.open("127.0.0.1", 25555))
		return;
	s.write(msg + "\n");
	s.close();
	#endif // NET_LOGGING

	printf("%s\n", msg.c_str());
	#endif // LOGGING
}