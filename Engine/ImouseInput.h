#pragma once
#include <iostream>


class ImouseInput {

	public:
		virtual ~ImouseInput(){};

		virtual void inputMouse(int tecla, int X, int Y) = 0;
};
