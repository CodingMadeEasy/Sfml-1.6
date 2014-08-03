// C++ SFML MADE EASY TUTORIAL 4 - MUTEXES
// CODINGMADEEASY [SFML 1.6]

#include<iostream> 

void ThreadFunction (void *UserData)
{
	for(int i = 0; i < 10; i++)
		std::cout << "Thread" << std:::endl;
}

int main()
{
	sf::Mutex Mutex;
	sf::Thread Threads (&ThreadFunction);
	Threads.Launch(); 
	
	Mutex.Lock();
	for(int i = 0; i < 10; i++)
		std::cout << "Main" << std::endl;
		
	Mutex.Unlock();
		
	return 0;
}