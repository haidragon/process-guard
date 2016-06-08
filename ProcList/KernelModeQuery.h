#ifndef KERNEL_MODE_QUERY
#define KERNEL_MODE_QUERY

#include <string>
#include <vector>

#include <Windows.h>

#include "ProcessInfo.h"

class KernelModeQuery {
public:
	inline static KernelModeQuery &getInstance();

	~KernelModeQuery() {}

	BOOLEAN reloadProcesses();

	const Processes& getProcesses() const;

	VOID mergeProcesses(Processes &newProcesses);

	const std::wstring &getLastError() const;

private:
	KernelModeQuery() : errorMsg(L"") {}

	VOID sort(Processes &processes);

	Processes processes;

	std::wstring errorMsg;
};

KernelModeQuery& KernelModeQuery::getInstance()
{
	static KernelModeQuery instance;

	return instance;
}

#endif // !KERNEL_MODE_QUERY