

# include "../Includes/Socket.hpp"
# include <thread>
# include <string>

using namespace std;

int	main(int ac, const char **argv) {

	std::thread ServerThread;
	std::thread clientThread_1;
	std::thread clientThread_2;

	const char * host = "127.0.0.1";
	const char * port = "9991";

	try {

		try {

			Socket Server( host , port );
			Socket SomeClient;
			Socket Client_1;

			Server.setsockopt(SOL_SOCKET, SO_REUSEPORT, true).settimeout(2);

			cout << "Server : " << Server;
			Server.listen(5);

			Client_1.connect( host , port );

			SomeClient = Server.accept();

			cout << "New Client : " << SomeClient << endl;


			std::string msg;
			int num;

			while (1) {

				try {

					Client_1.send( std::string( "hello world") );
					Server.recv_into( SomeClient, &msg );
					cout << " : ";
					cout << msg << endl;

					// Client_1.send( 911 );
					// Server.recv_into( SomeClient.descriptor , &num );

					// cout << num << endl;

					sleep(1);

				} catch ( std::exception & e ) {
					cout << e.what() << endl;
				}
			}

			(void) num;
			(void) msg;


		} catch ( std::exception & e ) {
			cout << e.what() << endl;
		}


		cout << "Everything works.\n";

	} catch ( std::exception & e ) {

		cout << e.what() << endl;

	}

	(void) host;
	(void) port;
	(void) ac;
	(void) argv;

	return (0);
}
