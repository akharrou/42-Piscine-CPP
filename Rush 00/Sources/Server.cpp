


#include "../Includes/Socket.hpp"

#include <iostream>
#include <thread>
#include <deque>

int	main( int ac, const char **argv ) {

	if (ac != 3)
		return (0);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	std::deque<Socket> clients;
	Socket Server;

	try {

		Server.bind( argv[1] , argv[2] )
			  .setsockopt( SOL_SOCKET , SO_REUSEPORT , true )
			  .setblocking(true)
		      .listen(5);

		std::cout << "Server Status : [RUNNING]\n"
				  << "Server running at '" << argv[1] << "::" << argv[2] << "'\n";

	} catch ( Socket::SocketError & e ) {
		std::cout << "~ Failed to establish server : " << e.what() << " ~";
		return (1);
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	Socket tmpClientHolder;

	while (1) {

		Server.accept( tmpClientHolder );

		std::thread( [ &Server ] ( Socket client ) -> void {

			std::string clientMsg;
			std::string serverReply;

			while ( Server.recv_into( client , clientMsg ) ) {

				serverReply = std::string("Server heard you loud and clear : \"" + clientMsg + "\"");
				Server.send( client , serverReply );
			}

		}, tmpClientHolder ).detach();

	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	return (0);
}
