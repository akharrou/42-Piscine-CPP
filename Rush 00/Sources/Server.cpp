

# include "../Includes/Socket.hpp"
# include <thread>
# include <string>
# include <vector>

using namespace std;

int	main(int ac, const char **argv) {


	const char * host = "127.0.0.1";
	const char * port = "9983";

// 	/* DEMONSTRATES API FOR UDP - - - - - - - - - - - - - - - - - - - - - - - - */
// 	try {

// 		Socket Server( host , port , SOCK_DGRAM );
// 		Socket Client( AF_INET , SOCK_DGRAM );
// 		Socket ClientSenderInfo;

// 		std::string *string_msg = new std::string; /* NOTE : dunno why this shows no leaks */
// 		char char_msg[100];
// 		int num;

// 		cout << "\n~ UDP Protocol Sockets (i.e Datagram Sockets) ~\n"
// 		     << "—————————————————————————————————————————————————\n"
// 			 << "\n"
// 		     << "RVALUES ; pointers & non-pointers :\n\n";

// 		for ( int i = 1; i < 6; ++i )
// 		{

// 			/* ~ RVALUES ; pointers & non-pointers ~ */

// 			// char [] ; (i.e, char *)
// 			Client.sendto( host , port , "(char[]) ; Hello World from UDP -- #", 37 );
// 			Server.recvfrom_into( char_msg , sizeof( char_msg ) );                    /* don't save sender info */
// //			Server.recvfrom_into( ClientSenderInfo , char_msg , sizeof( char_msg ) ); /* save sender info       */

// 			Client.sendto( host , port , 911 );
// 			Server.recvfrom_into( num );

// 			cout << char_msg << num << endl;

// 			sleep(1);

// 		}

// 		cout << "\nLVALUES ; pointers & non-pointers :\n\n";
// 		for ( int i = 1; i < 6; ++i )
// 		{

// 			/* ~ LVALUES ; pointers & non-pointers ~ */

// 			std::string string_greetings = "(string) ; Hello World from UDP -- #";
// 			const char  char_greetings[] = "(char[]) ; Hello World from UDP -- #";
// 			int id = 0 + i;

// 			// std::string
// 			Client.sendto( host , port , string_greetings );
// 			Server.recvfrom_into( string_msg );

// 			// char [] ; (i.e, char *)
// 			Client.sendto( host , port , char_greetings, strlen(char_greetings) );
// 			Server.recvfrom_into( char_msg , 100 );

// 			Client.sendto( host , port , id );
// 			Server.recvfrom_into( num );

// 			cout << *string_msg << num << endl;
// 			cout << char_msg   << num << endl;

// 			sleep(1);

// 		}

// 	} catch ( std::exception & e ) {
// 		cout << e.what() << endl;
// 	}


	/* DEMONSTRATES API FOR TCP - - - - - - - - - - - - - - - - - - - - - - - - */
	try {


		/* STEP #1 -- SERVER SIDE */
		Socket Server( host , port );
		Server.setsockopt( SOL_SOCKET , SO_REUSEPORT , true );
		Server.settimeout(2);
		Server.listen();
		cout << "Server Status: [RUNNING]\n"
			 << "Server running at " << host << "::" << port
			 << endl;

		/* STEP #2 -- CLIENT SIDE */
		Socket Client;
		Client.connect( host , port );


		/* STEP #3 -- SERVER SIDE */
		Socket NEW_ConnectedClient;
		NEW_ConnectedClient = Server.accept();


		/* STEP #4 -- CLIENT / SERVER SIDE */
		std::string msg;
		int num;

		for ( int i = 1; i < 6; ++i )
		{

			// NEW_ConnectedClient.send( std::string ( "Hello World # ... from TCP !" ) );
			// Server.recv_into( NEW_ConnectedClient , &msg );

			NEW_ConnectedClient.send( 911 );
			Server.recv_into( NEW_ConnectedClient , &num );

			cout << msg << num << endl;

			sleep(1);

		}


	} catch ( std::exception & e ) {
		cout << e.what() << endl;
	}


	// cout << "\n\n-----------------------------------------------------------\n"
	// 	 << "|                  ~ Memory Diagnostics ~                 |\n"
	// 	 << "-----------------------------------------------------------\n\n";

	// sleep(1);
	// sleep(1);
	// system("leaks tester");

	(void) host;
	(void) port;
	(void) ac;
	(void) argv;

	return (0);
}
