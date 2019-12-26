#pragma once

struct Entity
{
	int data;

	bool operator==(const Entity &other) const 
	{
		  // Compare the values, and return a bool result.
		if (data == other.data)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Entity &other) const
	{
		return !(*this == other);
	}
};