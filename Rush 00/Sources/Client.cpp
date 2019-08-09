

#include "../Includes/Socket.hpp"

int	main(int ac, char **argv) {

	if (ac != 2)
		return (0);

	/* STEP #2 -- CLIENT SIDE */
	Socket Client;
	Client.connect( argv[1] , argv[2] );

	// NEW_ConnectedClient.send( 911 );


	return (0);
}
