#pragma once
class Condition
{
public:
	Condition();
	~Condition();

	void BeginSynchronized();
	void EndSynchronized();
	uint32 Wait(time_t timeout);
	uint32 Wait();
	void Signal();
	void Broadcast();
private:
	int m_nLockCount; //future usage

	std::condition_variable m_condition;
	std::mutex m_lock;
};

