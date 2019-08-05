

# include "../../Includes/Socket.hpp"

using namespace std;

int	main() {

	try {

		Socket Server( "0.0.0.0", "7523" );
		Socket Client;
		Socket Client2;

		Server.listen(2);

		Client.connect(Server);
		Client2.connect("0.0.0.0", "7523");

		cout << "Everything works.\n";

	} catch ( std::exception & e ) {
		cout << e.what() << endl;
	}

	return (0);
}
