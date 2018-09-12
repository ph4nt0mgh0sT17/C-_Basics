/*********************************************
*   Using global, local and own namespaces   *
**********************************************/

#include <iostream>

// global constant
const char *id = "file scope_names.cpp";

namespace CPP_for_dummies
{
	// constant in namespace CPP_for_dummies
	const char *id = "ph4nt0m. C++ for Dummies.";
}

int main()
{
	// local constant in function main()
	const char *id = "body of function main";

	// used local constant
	std::cout << id << std::endl;

	// used global constant
	std::cout << ::id << std::endl;

	// used constant from CPP_for_dummies namespace
	std::cout << "Great book: " << CPP_for_dummies::id << std::endl;

	system("pause");

	return 0;

	
}