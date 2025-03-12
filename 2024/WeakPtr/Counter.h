#pragma once

struct Counter
{
	unsigned useCount = 0;
	unsigned weakCount = 0;

	void removeSharedPtr()
	{
		useCount--;
		if (useCount == 0)
			weakCount--;
	}
	void removeWeakPtr()
	{
		weakCount--;
	}

	void addSharedPtr()
	{
		useCount++;
		if (useCount == 1)
			weakCount++;
	}
	void addWeakPtr()
	{
		weakCount++;
	}

};
