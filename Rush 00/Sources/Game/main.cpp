
#include "../Includes/RType.class.hpp"

int	main(void)
{

	try {

		RType().run();

	} catch ( std::exception & e ) {
		std::cout << "~ Error : " << e.what() << " ~\n";
		return (1);
	}

	return (0);
}
