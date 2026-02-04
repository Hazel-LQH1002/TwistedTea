#include "Twist.h"

class DumbGame : public Twist::Application
{
public:
	DumbGame()
	{

	}

	~DumbGame()
	{

	}

};


Twist::Application* Twist::CreateApplication()
{
	return new DumbGame();
}