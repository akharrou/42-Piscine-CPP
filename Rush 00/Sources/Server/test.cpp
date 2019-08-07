

#include <string>
#include <vector>
#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


// template <typename T>
// T foo()
// {
// 	T data = 0;

// 	return ( data );
// }

// template <typename T>
// T baz( size_t length = 0, const char * name = nullptr )
// {
// 	(void) name;
// 	(void) length;
// 	T data = foo();
// 	return ( data );
// }

// template <typename T>
// T bar( size_t length = 0 )
// {
// 	(void) length;
// 	return ( baz( length ) );
// }

template <typename T>
T	returnDataObject ( T data, size_t length ) {

	const char * dataConvert = reinterpret_cast <const char *> (&data);

	char * dataObject = new char [ length ];

	for ( size_t i = 0 ; i < length ; ++i )
		dataObject[i] = dataConvert[i];

	return (
		* ( reinterpret_cast < T * > (dataObject) )
	);
}

template <typename T>
T *	returnDataObjectPtr ( T * data, size_t length ) {

	const char * dataConvert = reinterpret_cast <const char *> (data);

	char * dataObject = new char [ length ];

	for ( size_t i = 0 ; i < length ; ++i )
		dataObject[i] = dataConvert[i];

	return (
		( reinterpret_cast < T * > (dataObject) )
	);
}

int	main()
{

	// std::string name = "Johnny Bruno Inc. and his friends at the market place and school";

	// std::string dupName = returnDataObject( name , sizeof name );
	// std::cout << dupName << "\n";

	const char * personName = "Jackson Bernard $! Hello guys this is a string no way it works";

	const char * personNameCopy = returnDataObject( personName , strlen( personName ) );
	const char * personNameCopy2 = returnDataObjectPtr( personName , strlen( personName ) );

	std::cout << personNameCopy << "\n";
	std::cout << personNameCopy2 << "\n";


	return (0);
}










	// int n = 2;
	// int dupn = returnDataObject( n , sizeof(n) );
	// std::cout << dupn << "\n";

	// std::vector<int> ages = { 1, 2, 3, 4, 5, 6 };
	// std::vector<int> agesCopy = returnDataObject( ages , sizeof ages );

	// for ( size_t i = 0; agesCopy[i]; ++i )
	// 	std::cout << agesCopy[i] << "\n";
