#pragma once

#include <memory>

namespace nice {
	
	//template <typename T>
	//void swap(T& a, T& b) {
	//	T temp = a;
	//	a = b;
	//	b = temp;
	//}

	// for more efficiency, since c++11
	template <typename T>
	void swap(T& a, T& b) {
		T temp = std::move(a);
		a = std::move(b);
		b = std::move(temp);
	}

};