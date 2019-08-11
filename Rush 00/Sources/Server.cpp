# include "../Includes/Socket.hpp"
# include <thread>
# include <string>
# include <vector>

using namespace std;

int	main(int ac, const char **argv) {


	const char * host = "127.0.0.1";
	const char * port = "9971";

	/* DEMONSTRATES API FOR UDP - - - - - - - - - - - - - - - - - - - - - - - - */
	try {

		Socket Server( host , port , SOCK_DGRAM , UDP );
		Socket Client( AF_INET , SOCK_DGRAM , UDP );
		Socket ClientSenderInfo;

		std::string string_msg;
		char char_msg[100];
		int num;

		cout << "\n~ UDP Protocol Sockets (i.e Datagram Sockets) ~\n"
		     << "—————————————————————————————————————————————————\n"
			 << "\n"
		     << "RVALUES ; pointers & non-pointers :\n\n";

		for ( int i = 1; i < 6; ++i )
		{

			/* ~ RVALUES ; pointers & non-pointers ~ */

			// std::string
			Client.sendto( host , port , "(string) ; Hello World from UDP -- #", 37 );
			Server.recvfrom_into( string_msg );

			// char [] ; (i.e, char *)
			Client.sendto( host , port , "(char[]) ; Hello World from UDP -- #", 37 );
			Server.recvfrom_into( char_msg , sizeof( char_msg ) );

			// int
			Client.sendto( host , port , 911 );
			Server.recvfrom_into( num );

			cout << string_msg << endl;
			cout << char_msg   << endl;
			cout << "(int)    ; " << num << endl << endl;

			sleep(1);

		}

		std::cout << endl << "Server:\n" << Server << endl;
		std::cout << endl << "Client:\n" << Client << endl;
		std::cout << endl << "ClientSenderInfo:\n" << ClientSenderInfo << endl;
		sleep(2);

		cout << "\nLVALUES ; pointers & non-pointers :\n\n";
		for ( int i = 1; i < 6; ++i )
		{

			/* ~ LVALUES ; pointers & non-pointers ~ */

			std::string string_greetings = "(string) ; Hello World from UDP -- #";
			const char  char_greetings[] = "(char[]) ; Hello World from UDP -- #";
			int id = 0 + i;

			// std::string
			Client.sendto( host , port , string_greetings );
			Server.recvfrom_into( string_msg );

			// char [] ; (i.e, char *)
			Client.sendto( host , port , char_greetings, strlen(char_greetings) );
			Server.recvfrom_into( char_msg , sizeof ( char_msg ) );

			Client.sendto( host , port , id );
			Server.recvfrom_into( num );

			cout << string_msg << endl;
			cout << char_msg   << endl;
			cout << "(int)    ; "  << num << endl << endl;

			sleep(1);

		}

	} catch ( std::exception & e ) {
		cout << e.what() << endl;
	}

# define HOME            "\033[H"
# define CLEAR           "\033[2J"
# define CLEANUP { std::cout << CLEAR << HOME << std::endl; }
	CLEANUP;

	sleep(1);
		cout << "\n~ TCP Protocol Sockets (i.e Stream Sockets) ~\n"
		     << "—————————————————————————————————————————————————\n\n";
	sleep(1);

	/* DEMONSTRATES API FOR TCP - - - - - - - - - - - - - - - - - - - - - - - - */
	try
	{

		/* STEP #1 -- SERVER SIDE */
		Socket Server( host , port /* [, AF_INET , TCP , IPPROTO_TCP ] */ );

		Server.setsockopt( SOL_SOCKET , SO_REUSEPORT , true )
		      .settimeout(2)
		      .listen();


		/* STEP #2 -- CLIENT SIDE */
		Socket Client;
		Client.connect( host , port );


		/* STEP #3 -- SERVER SIDE */
		Socket NEW_ConnectedClient;
		NEW_ConnectedClient = Server.accept();

		std::cout << endl << "Server:\n" << Server << endl;
		std::cout << endl << "Client:\n" << NEW_ConnectedClient << endl;


		/* STEP #4 -- CLIENT / SERVER SIDE */
		std::string string_msg;
		char char_msg[100];
		int num;

		cout << "\nRVALUES ; pointers & non-pointers :\n\n";
		for ( int i = 1; i < 6; ++i )
		{

			/* ~ RVALUES ; pointers & non-pointers ~ */

			// std::string
			Client.send( "(char[]) ; Hello World from TCP -- #" , 36 );
			Server.recv_into( NEW_ConnectedClient , string_msg );

			// char[]
			Client.send( "(char[]) ; Hello World from TCP -- #" , 36 );
			Server.recv_into( NEW_ConnectedClient , char_msg , sizeof char_msg );

			// int
			Client.send( 911 );
			Server.recv_into( NEW_ConnectedClient , num );

			cout << string_msg << endl;
			cout << char_msg   << endl;
			cout << "(int)    ; " << num << endl;

			sleep(1);

		}

		cout << "\nLVALUES ; pointers & non-pointers :\n\n";
		for ( int i = 1; i < 6; ++i )
		{

			std::string string_greetings = "(string) ; Hello World from UDP -- #";
			const char  char_greetings[] = "(char[]) ; Hello World from UDP -- #";
			int id = i;

			/* ~ LVALUES ; pointers & non-pointers ~ */

			// std::string
			Client.send( string_greetings );
			Server.recv_into( NEW_ConnectedClient , string_msg );

			// char[]
			Client.send( char_greetings , strlen(char_greetings) );
			Server.recv_into( NEW_ConnectedClient , char_msg , sizeof char_msg );

			// int
			Client.send( id );
			Server.recv_into( NEW_ConnectedClient , num );

			cout << string_msg << endl;
			cout << char_msg   << endl;
			cout << "(int)    ; " << num << endl << endl;

			sleep(1);

		}

	} catch ( std::exception & e ) {
		cout << e.what() << endl;
	}



	/* DEMONSTRATES API FOR UDP - - - - - - - - - - - - - - - - - - - - - - - - */
	try {

		Socket Server( host , port , SOCK_DGRAM );
		Socket Client( AF_INET , SOCK_DGRAM );
		Socket ClientSenderInfo;

		std::string string_msg;
		char * char_msg;
		// int num;

		cout << "\n~ UDP Protocol Sockets (i.e Datagram Sockets) ~\n"
		     << "—————————————————————————————————————————————————\n"
			 << "\n"
		     << "RVALUES ; pointers & non-pointers :\n\n";

		for ( int i = 1; i < 6; ++i )
		{

			/* ~ RVALUES ; pointers & non-pointers ~ */

			// std::string
			Client.sendto( host , port , "(string) ; Hello World from UDP -- #", 36 );
			cout << Server.recvfrom() << endl;

			// char [] ; (i.e, char *)
			Client.sendto( host , port , "(char[]) ; Hello World from UDP -- #", 36 );
			char_msg = Server.recvfrom <char> ( 100 );
			cout << char_msg << endl;

			// int
			Client.sendto( host , port , 911 );
			cout << "(int) ; " << Server.recvfrom <int> (/* [ ClientSenderInfo , length, peerConnected, flags ] */) << endl << endl;

			delete char_msg;

			sleep(1);

		}

		cout << "\nLVALUES ; pointers & non-pointers :\n\n";
		for ( int i = 1; i < 6; ++i )
		{

			/* ~ LVALUES ; pointers & non-pointers ~ */

			std::string string_greetings = "(string) ; Hello World from UDP -- #";
			const char  char_greetings[] = "(char[]) ; Hello World from UDP -- #";
			int id = 0 + i;

			// std::string
			Client.sendto( host , port , string_greetings );
			cout << Server.recvfrom() << endl;

			// char[]
			Client.sendto( host , port , char_greetings, strlen(char_greetings) );
			char_msg = Server.recvfrom <char> ( 100 );
			cout << char_msg << endl;

			// int
			Client.sendto( host , port , id );
			cout << "(int)    ; " << Server.recvfrom <int> () << endl << endl;

			delete [] char_msg;

			sleep(1);

		}

	} catch ( std::exception & e ) {
		cout << e.what() << endl;
	}

# define HOME            "\033[H"
# define CLEAR           "\033[2J"
# define CLEANUP { std::cout << CLEAR << HOME << std::endl; }

	CLEANUP;
	sleep(1);
		cout << "\n~ TCP Protocol Sockets (i.e Stream Sockets) ~\n"
		     << "—————————————————————————————————————————————————\n\n";
	sleep(1);

	/* DEMONSTRATES API FOR TCP - - - - - - - - - - - - - - - - - - - - - - - - */
	try
	{

		/* STEP #1 -- SERVER SIDE */
		Socket Server( host , port /* [, AF_INET , TCP , IPPROTO_TCP ] */ );

		Server.setsockopt( SOL_SOCKET , SO_REUSEPORT , true )
		      .settimeout(2)
		      .listen();


		/* STEP #2 -- CLIENT SIDE */
		Socket Client;
		Client.connect( host , port );


		/* STEP #3 -- SERVER SIDE */
		Socket NEW_ConnectedClient;
		NEW_ConnectedClient = Server.accept();

		std::cout << endl << "Server:\n" << Server << endl;
		std::cout << endl << "Client:\n" << NEW_ConnectedClient << endl;

		sleep(4);

		/* STEP #4 -- CLIENT / SERVER SIDE */
		std::string string_msg;
		char * char_msg;

		cout << "\nRVALUES ; pointers & non-pointers :\n\n";
		for ( int i = 1; i < 6; ++i )
		{

			/* ~ RVALUES ; pointers & non-pointers ~ */

			// std::string
			Client.send( "(string) ; Hello World from TCP -- #" , 37 );
			std::cout << Server.recv( NEW_ConnectedClient ) << endl;

			// char[]
			Client.send( "(char[]) ; Hello World from TCP -- #" , 37 );
			char_msg = Server.recv <char> ( NEW_ConnectedClient , 100 );
			std::cout << char_msg << endl;

			// int
			Client.send( 911 );
			std::cout << "(int)    ; " << Server.recv <int> ( NEW_ConnectedClient ) << endl << endl;

			delete [] char_msg;

			sleep(1);

		}

		cout << "\nLVALUES ; pointers & non-pointers :\n\n";
		for ( int i = 1; i < 6; ++i )
		{

			std::string string_greetings = "(string) ; Hello World from TCP -- #";
			const char  char_greetings[] = "(char[]) ; Hello World from TCP -- #";
			int id = i;

			/* ~ LVALUES ; pointers & non-pointers ~ */

			// std::string
			Client.send( string_greetings );
			cout << Server.recv( NEW_ConnectedClient ) << endl;

			// char[]
			Client.send( char_greetings , strlen(char_greetings) );
			char_msg = Server.recv <char> ( NEW_ConnectedClient , 100 );
			cout << char_msg << endl;

			// int
			Client.send( id );
			cout << "(int)    ; " << Server.recv <int> ( NEW_ConnectedClient ) << endl << endl;

			delete [] char_msg;

			sleep(1);

		}

	} catch ( std::exception & e ) {
		cout << e.what() << endl;
	}


	cout << "\n\n-----------------------------------------------------------\n"
		 << "|                  ~ Memory Diagnostics ~                 |\n"
		 << "-----------------------------------------------------------\n\n";

	sleep(1);
	system("leaks tester");

	(void) host;
	(void) port;
	(void) ac;
	(void) argv;

	return (0);
}
