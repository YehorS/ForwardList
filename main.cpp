
#include "stdafx.h"
#include <iostream>
#include "ForwardList.h"


int main()
{
	setlocale(LC_ALL, "ru");
	ForwardList<int> FirstList;
	FirstList.push_front(1);
	FirstList.push_front(2);
	FirstList.push_front(3);
	FirstList.push_front(4);
	FirstList.insert(2313, 3);

	if (FirstList.empty()) {
		std::cout << "Empty" << std::endl;
	}
	else std::cout << "Not empty" << std::endl;


	return 0;
}