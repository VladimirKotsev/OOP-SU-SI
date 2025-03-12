#pragma once
#include "Command.h"

class CommandContainer
{
private:
	Command** data;
	size_t size;
	size_t capacity;

	void free();
	void moveFrom(CommandContainer&& other);
	void copyFrom(const CommandContainer& other);
	void resize(size_t newCap);

public:
	CommandContainer();

	CommandContainer(const CommandContainer& other);
	CommandContainer& operator=(const CommandContainer& other);

	CommandContainer(CommandContainer&& other) noexcept;
	CommandContainer& operator=(CommandContainer&& other) noexcept;

	~CommandContainer() noexcept;

	void add(Command* command);
	void remove();

	void removeAt(size_t index);

	size_t getSize() const;
	size_t getCapacity() const;

	Command* operator[](size_t index);
	const Command* operator[](size_t index) const;
};

