

#include "../Includes/Socket.hpp"

#include <iostream>
#include <thread>

int	main(int ac, char **argv) {

	if (ac != 3)
		return (0);

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	Socket Client;

	try {

		Client.connect( argv[1] , argv[2] );

	} catch ( Socket::SocketError & e ) {
		std::cout << "~ Failed to connect : " << e.what() << " ~";
		return (1);
	}

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	std::thread inputer([ &Client ]() -> void {

		std::string userInput;

		while (1) {

			std::getline( std::cin , userInput , '\n' );
			Client.send( userInput );
		}

	});

	std::thread receiver([ &Client ]() -> void {

		std::string chat;

		while ( Client.recv_into( chat ) )
			std::cout << chat << std::endl;

	});

	receiver.join();

	/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

	return (0);
}
