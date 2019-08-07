

#include <string>
#include <vector>
#include <iostream>

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

// template <typename T>
// T	returnDataObject ( T data, size_t length ) {

// 	const char * dataConvert = reinterpret_cast <const char *> (&data);
// 	char * dataObject = new char [ length ];

// 	for ( size_t i = 0 ; i < length ; ++i )
// 		dataObject[i] = dataConvert[i];

// 	return (
// 		* ( reinterpret_cast < T * > (dataObject) )
// 	);
// }

template <typename T>
T foo()
{
	T data;
	return ( data );
}

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

int	main()
{

	int a = foo(); /* no matching function for call to 'foo' */
	// int b = bar(); /* no matching function for call to 'bar' */
	// int c = baz(); /* no matching function for call to 'baz' */

	return (0);
}










	// std::string name = "Johnny Bruno Inc. and his friends at the market place and school";

	// std::string dupName = returnDataObject( name , sizeof name );
	// std::cout << dupName << "\n";

	// int n = 2;
	// int dupn = returnDataObject( n , sizeof(n) );
	// std::cout << dupn << "\n";

	// std::vector<int> ages = { 1, 2, 3, 4, 5, 6 };
	// std::vector<int> agesCopy = returnDataObject( ages , sizeof ages );

	// for ( size_t i = 0; agesCopy[i]; ++i )
	// 	std::cout << agesCopy[i] << "\n";

	// const char * personName = "Jackson Bernard $! Hello guys this is a string no way it works";
	// const char * personNameCopy = returnDataObject( personName , sizeof personName );

	// std::cout << personNameCopy << "\n";
