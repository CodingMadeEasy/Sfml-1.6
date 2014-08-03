#include<iostream> 
// C++ SFML MADE EASY TUTORIAL 3 - THREADS
// CODINGMADEEASY [SFML 1.6]

#include<SFML/Graphics.hpp> 

void ThreadFunction (void *UserData)
{
	for(int i = 0; i < 10; i++)
		std::cout << "Thread" << std:::endl;
}

int main()
{
	sf::Thread Threads (&ThreadFunction);
	Threads.Launch(); 
	for(int i = 0; i < 10; i++)
		std::cout << "Main" << std::endl;
		
	return 0;
}