#pragma once

/*
	Thread-based timer class
    SharktasticA 2020
	https://sharktastica.co.uk
    https://github.com/SharktallicA
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

/*
    Thread-based timer mechanism for running a function
    at a specific rate.
*/
class Timer
{
private:
    /*
        Frequency (in hertz) that the task should be
        called.
    */
	int updFreq;

    /*
        Task function that the timer will run on loop.
    */
    function<void(void)> task;

    /*
        The thread this timer will manage.
    */
	thread th;

    /*
        Flags if the timer should be updating.
    */
	bool running = false;

public:
    /*
        Default constructor.
        Parametres:
            hertz - update frequency
            func - function in wrapper
    */
	Timer(int hertz, function<void(void)> func)
	{
		updFreq = hertz;
		task = func;
		Start();
	}

    /*
        Creates the thread update loop.
    */
	void Start()
	{
		running = true;

		th = thread([=]()
		{
			while (running)
			{
				this_thread::sleep_for(chrono::milliseconds(1000 / updFreq));
				task();
			}
		});
	}

    /*
        Stops the thread update loop.
    */
	void Stop()
	{
		running = false;
		th.join();
	}
};