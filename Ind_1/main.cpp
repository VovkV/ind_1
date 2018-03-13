#include "Container.h"
#include "Test.h"
#include <iostream>

void main()
{
	Container<Test> t = *new Container<Test>();

	for (int i = 0; i < 100; i++)
		t[i] = *new Test(i);

	for (int i = 0; i < t.Size(); i++)
		std::cout << t[i].data<< "\n";

	system("Pause");
}