


#include "../Includes/Socket.hpp"

#include <iostream>
#include <thread>
#include <map>

int	main( int ac, const char **argv ) {

	if (ac != 3)
		return (0);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	std::map < size_t, Socket > activeClients;
	Socket Server;

	try {

		Server.setsockopt( SOL_SOCKET , SO_REUSEPORT , true )
			  .setblocking(true)
			  .bind( argv[1] , argv[2] )
		      .listen(5);

		std::cout << "Server Status : [RUNNING]\n"
				  << "Server running at '" << argv[1] << "::" << argv[2] << "'\n";

	} catch ( Socket::SocketError & e ) {
		std::cout << "~ Failed to establish server : " << e.what() << " ~";
		return (1);
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	while (1) {

		activeClients[ activeClients.size() + 1 ] = Server.accept();
		std::cout << ("Client #" + std::to_string( activeClients.size() ) + " joined the session.\n");

		try {

			std::thread	( [ & Server , & activeClients ] ( size_t identifier ) -> void {

				std::map < size_t, Socket> ::iterator curClient;
				std::string clientMsg;
				std::string broadcastMsg;

				Socket & client = activeClients[ identifier ];

				while ( Server.recv_into( client , clientMsg ) ) {

					broadcastMsg = std::string("[Client #" + std::to_string( identifier ) + "]: " + clientMsg );

					for ( curClient = activeClients.begin(); curClient != activeClients.end(); ++curClient )
						Server.send( (*curClient).second , broadcastMsg );

				}

				std::cout << std::string("Client #" + std::to_string( identifier ) + " left the session.\n");
				activeClients.erase( identifier );

			}, activeClients.size() ).detach();

		} catch ( Socket::SocketError & ) {}

	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	return (0);
}
