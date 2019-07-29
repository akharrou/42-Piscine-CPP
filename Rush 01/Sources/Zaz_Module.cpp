
#include "../Includes/GKrellM.hpp"
#include "../Includes/GKrellM_Modules.hpp"

/* PUBLIC MEMBER FUNCTION(S) - - - - - - - - - - - - - - - - - - - - - - - - */

void	Zaz_Module::update() {

	static int state = 0;

	unicorn = unicornFrame[state++ % 3];

	if (state == INT_MAX)
		state = INT_MAX % 3;
}

void	Zaz_Module::render() {

	std::istringstream tmpUnicorn(unicorn);
	std::string tmp;

	werase ( screen.win );

	std::string title ("|Zaz's Favorite Animal|");

	for (unsigned int i = 0; std::getline(tmpUnicorn, tmp, '\n'); ++i) {
		mvwprintw(screen.win, 2 + i, ((((screen.max.x - screen.min.x) / 2 / 2) + ((screen.max.x - screen.min.x) / 2 / 2 / 2))), "%s", tmp.c_str());
	}

	box    ( screen.win, 0, 0 );
	mvwprintw(screen.win, 0, (screen.max.x - screen.min.x - title.length()) / 2,
				"%s", title.c_str());

	wrefresh ( screen.win );
}


/* PUBLIC CONSTRUCTOR / DECONSTRUCTOR - - - - - - - - - - - - - - - - - - - - */

Zaz_Module::~Zaz_Module( void ) {}

Zaz_Module::Zaz_Module( screen_t win ) :
	AMonitorModule(win) {

	name = "Zaz Module";

	unicornFrame[0] =
        "                                 \n"
        "                                /\n"
        "                      __       //\n"
        "                      -\\~,\\=\\ //\n"
        "                    --=_\\=---//=\n"
        "                  -_ =/  \\/ //\\/\n"
        "                  _,~/   |_   _|\\,\n"
        "     __          ,/_/    \\' | `/_\n"
        "    //\\\\          /       | | |\\_\n"
        "   /(\\ _\\________/        (,_,)`\n"
        "  J(\\_/                       \\\n"
        " ,)\\/     v                \\   |\n"
        " / Y      (         Y       | /J\n"
        "(7 |       \\        |       '/ \\\n"
        "'| (       /\\_______\\_     _Y_  \\\n"
        " 'Y \\     / \\     7   \\   /   \\  \\\n"
        " ',) (   /   )   /    |  /    (  )\n"
        "   '~(  )   / __/     i J     / /\n"
        "     \\  /   \\ \\       | |   _/ /\n"
        "     | |     )_\\_     )_\\_/__\\/\n"
        "     /_\\     |___\\    |___\\\n"
        "    (___)\n";

	unicornFrame[1] =
        "                    \n"
        "                   /\n"
        "                   __       //\n"
        "                   -\\= \\=\\ //\n"
        "                 --=_\\=---//=--\n"
        "               -_==/  \\/ //\\/--\n"
        "                ==/   /O   O\\==--\n"
        "   _ _ _ _     /_/    \\  ]  /--\n"
        "  /\\ ( (- \\    /       ] ] ]==-\n"
        " (\\ _\\_\\_\\-\\__/     \\  (,_,)--\n"
        "(\\_/                 \\     \\-\n"
        "\\/      /       (   ( \\  ] /)\n"
        "/      (         \\   \\_ \\./ )\n"
        "(       \\         \\      )  \\\n"
        "(       /\\_ _ _ _ /---/ /\\_  \\\n"
        " \\     / \\     / ____/ /   \\  \\\n"
        "  (   /   )   / /  /__ )   (  )\n"
        "  (  )   / __/ '---`       / /\n"
        "  \\  /   \\ \\             _/ /\n"
        "  ] ]     )_\\_         /__\\/\n"
        "  /_\\     ]___\\\n"
        " (___)\n";

	unicornFrame[2] =
        "`\\`\\`\\`\\`,            ~|;!;!;\\!\n"
        " ~\\;\\;\\;\\|\\          (--,!!!~`!       .\n"
        "(--,\\\\\\===~\\         (--,|||~`!     ./\n"
        " (--,\\\\\\===~\\         `,-,~,=,:. _,//\n"
        "  (--,\\\\\\==~`\\        ~-=~-.---|\\;/J,\n"
        "   (--,\\\\\\((```==.    ~'`~/       a |\n"
        "     (-,.\\\\('('(`\\\\.  ~'=~|     \\_.  \\\n"
        "        (,--(,(,(,'\\\\. ~'=|       \\\\_;>\n"
        "          (,-( ,(,(,;\\\\ ~=/        \\\n"
        "          (,-/ (.(.(,;\\\\,/          )\n"
        "           (,--/,;,;,;,\\\\         ./------.\n"
        "             (==,-;-'`;'         /_,----`. \\\n"
        "     ,.--_,__.-'                    `--.  ` \\\n"
        "    (='~-_,--/        ,       ,!,___--. \\  \\_)\n"
        "   (-/~(     |         \\   ,_-         | ) /_|\n"
        "   (~/((\\    )\\._,      |-'         _,/ /\n"
        "    \\\\))))  /   ./~.    |           \\_\\;\n"
        " ,__/////  /   /    )  /\n"
        "  '===~'   |  |    (, <.\n"
        "           / /       \\. \\\n"
        "         _/ /          \\_\\\n"
        "        /_!/            >_\\\n";

}
