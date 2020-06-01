#include <windows.h>
#include <stdio.h>
#include "lab3.h"
#include <iostream>
#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h> 
#else
#include <unistd.h> 
#endif


#define THREADCOUNT 13
#define count_value 3

unsigned int lab3_thread_graph_id()
{
	return 15;
}

const char* lab3_unsynchronized_threads()
{
	return "bcdgh";
}

const char* lab3_sequential_threads()
{
	return "emn";
}


HANDLE Threads[THREADCOUNT];
HANDLE mutexxx, semaphore_1, semaphore_2, semaphore_3, semaphore_4, semaphore_5, semaphore_6;// mutex it's like Constitution, u know


DWORD WINAPI thread_a(LPVOID thread_name);// thread it's like president(Putin for ex).  
DWORD WINAPI thread_b(LPVOID thread_name);//One position - one Putin.
DWORD WINAPI thread_c(LPVOID thread_name);//And constitution protect president pos from other people while Putin is president
DWORD WINAPI thread_d(LPVOID thread_name);
DWORD WINAPI thread_e(LPVOID thread_name);
DWORD WINAPI thread_g(LPVOID thread_name);
DWORD WINAPI thread_f(LPVOID thread_name);
DWORD WINAPI thread_h(LPVOID thread_name);
DWORD WINAPI thread_k(LPVOID thread_name);
DWORD WINAPI thread_m(LPVOID thread_name);
DWORD WINAPI thread_n(LPVOID thread_name);
DWORD WINAPI thread_p(LPVOID thread_name);
DWORD WINAPI thread_i(LPVOID thread_name);


DWORD thread_id;


DWORD WINAPI thread_a(LPVOID thread_name)
{

	UINT my_count = 0;

	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_2, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'a' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_1, 1, NULL))
		{
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return TRUE;



};


DWORD WINAPI thread_c(LPVOID thread_name)
{

	for (size_t i = 0; i < count_value; ++i)
	{
		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'c' << std::flush;
		ReleaseMutex(mutexxx);
		computation();
	}

	return TRUE;

};

DWORD WINAPI thread_b(LPVOID thread_name)
{

	for (size_t i = 0; i < count_value; ++i)
	{
		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'b' << std::flush;
		ReleaseMutex(mutexxx);
		computation();
	}

	return TRUE;
};


DWORD WINAPI thread_g(LPVOID thread_name)
{

	for (size_t i = 0; i < count_value; ++i)
	{
		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'g' << std::flush;
		ReleaseMutex(mutexxx);
		computation();
	}

	return TRUE;
};


DWORD WINAPI thread_d(LPVOID thread_name)
{
	UINT my_count = 0;

	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_1, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'd' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_2, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}

	WaitForSingleObject(Threads[0], INFINITE);

	Threads[2] = CreateThread(NULL, 0, thread_c, NULL, 0, &thread_id);
	Threads[3] = CreateThread(NULL, 0, thread_b, NULL, 0, &thread_id);
	Threads[4] = CreateThread(NULL, 0, thread_g, NULL, 0, &thread_id);
	Threads[5] = CreateThread(NULL, 0, thread_h, NULL, 0, &thread_id);

	for (size_t i = 0; i < count_value; ++i)
	{
		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'd' << std::flush;
		ReleaseMutex(mutexxx);
		computation();
	}

	WaitForSingleObject(Threads[2], INFINITE);
	WaitForSingleObject(Threads[3], INFINITE);
	WaitForSingleObject(Threads[4], INFINITE);
	Threads[6] = CreateThread(NULL, 0, thread_e, NULL, 0, &thread_id);
	Threads[7] = CreateThread(NULL, 0, thread_f, NULL, 0, &thread_id);
	Threads[8] = CreateThread(NULL, 0, thread_i, NULL, 0, &thread_id);
	Threads[9] = CreateThread(NULL, 0, thread_k, NULL, 0, &thread_id);

	my_count = 0;
	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_1, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());
		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'd' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_2, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}

	}

	return 0;
};

DWORD WINAPI thread_h(LPVOID thread_name)
{

	for (size_t i = 0; i < count_value; ++i)
	{
		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'h' << std::flush;
		ReleaseMutex(mutexxx);
		computation();
	}

	UINT my_count = 0;

	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_6, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'h' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_1, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return TRUE;
};

DWORD WINAPI thread_k(LPVOID thread_name)
{
	UINT my_count = 0;

	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_5, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'k' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_6, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}

	}
	return TRUE;
};

DWORD WINAPI thread_i(LPVOID thread_name)
{
	UINT my_count = 0;

	while (my_count != count_value)
	{
		if (WaitForSingleObject(semaphore_4, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'i' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_5, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return TRUE;
};

DWORD WINAPI thread_f(LPVOID thread_name)
{
	UINT my_count = 0;

	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_3, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());


		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'f' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_4, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return TRUE;
};

DWORD WINAPI thread_e(LPVOID thread_name)
{
	UINT my_count = 0;
	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_2, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());


		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'e' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_3, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}


	my_count = 0;
	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_2, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'e' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_3, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return TRUE;
};

DWORD WINAPI thread_m(LPVOID thread_name)
{
	UINT my_count = 0;

	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_3, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'm' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_1, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return TRUE;
};

DWORD WINAPI thread_n(LPVOID thread_name)
{
	UINT my_count = 0;

	while (my_count != count_value)
	{
		if (WaitForSingleObject(semaphore_1, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'n' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_2, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}

	WaitForSingleObject(Threads[11], INFINITE);

	Threads[12] = CreateThread(NULL, 0, thread_p, NULL, 0, &thread_id);

	my_count = 0;
	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_1, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'n' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;
		computation();

		if (!ReleaseSemaphore(semaphore_2, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return TRUE;
};

DWORD WINAPI thread_p(LPVOID thread_name)
{
	UINT my_count = 0;

	while (my_count != count_value)
	{

		if (WaitForSingleObject(semaphore_2, INFINITE) != WAIT_OBJECT_0)
			printf("Thread %d: Putin isn't president...\n", GetCurrentThreadId());

		WaitForSingleObject(mutexxx, INFINITE);
		std::cout << 'p' << std::flush;
		ReleaseMutex(mutexxx);
		my_count += 1;

		computation();

		if (!ReleaseSemaphore(semaphore_1, 1, NULL)) {
			printf("ReleaseSemaphore error: %d\n", GetLastError());
		}
	}
	return 0;
};


int lab3_init()
{
	mutexxx = CreateMutex(NULL, FALSE, NULL);
	semaphore_1 = CreateSemaphore(NULL, 1, 1, NULL);

	if (semaphore_1 == NULL)
	{
		printf("CreateSemaphore error: %d\n", GetLastError());
		return 1;
	}

	semaphore_2 = CreateSemaphore(NULL, 0, 1, NULL);

	if (semaphore_2 == NULL)
	{
		printf("CreateSemaphore error: %d\n", GetLastError());
		return 1;
	}

	semaphore_3 = CreateSemaphore(NULL, 0, 1, NULL);
	if (semaphore_3 == NULL)
	{
		printf("CreateSemaphore error: %d\n", GetLastError());
		return 1;
	}

	semaphore_4 = CreateSemaphore(NULL, 0, 1, NULL);
	if (semaphore_4 == NULL)
	{
		printf("CreateSemaphore error: %d\n", GetLastError());
		return 1;
	}

	semaphore_5 = CreateSemaphore(NULL, 0, 1, NULL);
	if (semaphore_5 == NULL)
	{
		printf("CreateSemaphore error: %d\n", GetLastError());
		return 1;
	}

	semaphore_6 = CreateSemaphore(NULL, 0, 1, NULL);
	if (semaphore_6 == NULL)
	{
		printf("CreateSemaphore error: %d\n", GetLastError());
		return 1;
	}

	Threads[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &thread_id);
	Threads[1] = CreateThread(NULL, 0, thread_d, NULL, 0, &thread_id);

	WaitForSingleObject(Threads[1], INFINITE);

	WaitForSingleObject(Threads[5], INFINITE);


	Threads[10] = CreateThread(NULL, 0, thread_n, NULL, 0, &thread_id);
	Threads[11] = CreateThread(NULL, 0, thread_m, NULL, 0, &thread_id);
	WaitForSingleObject(Threads[10], INFINITE);

	WaitForMultipleObjects(THREADCOUNT, Threads, TRUE, INFINITE);

	for (int i = 0; i < THREADCOUNT; i++) CloseHandle(Threads[i]);

	CloseHandle(semaphore_1);
	CloseHandle(semaphore_2);
	CloseHandle(semaphore_3);
	CloseHandle(semaphore_4);
	CloseHandle(semaphore_5);
	CloseHandle(semaphore_6);
	return 0;
}