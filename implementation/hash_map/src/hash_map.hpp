#pragma once

template <typename T>
struct SomeType {
	SomeType(const T& a): _a(a) {}
	T _a;
};
