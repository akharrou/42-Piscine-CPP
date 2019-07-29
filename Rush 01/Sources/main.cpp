
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "../Includes/GKrellM.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

# include "../Includes/GKrellM_Shell.hpp"
# include "../Includes/GKrellM_Graphical.hpp"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int	main(int ac, char **av) {

	if (ac != 2) {

		EXIT(usage());

	} else {

		if (strcmp(av[1], "--shell") == 0) {

			GKrellM_Shell().run();

		} else if (strcmp(av[1], "--graphical") == 0) {

			GKrellM_Graphical().run();

		} else {

			EXIT(usage());

		}
	}

	return (0);
}
