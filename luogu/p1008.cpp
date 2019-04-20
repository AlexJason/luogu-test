#include <iostream>

template<int n>
struct Pow10 {
	static const int result = 10 * Pow10<n - 1>::result;
};

template<>
struct Pow10<0> {
	static const int result = 1;
};

template<bool a, int v>
struct IfPrint {};

template<int v>
struct IfPrint<true, v> {
	static void print() { std::cout << v << " " << v * 2 << " " << v * 3 << std::endl; }
};

template<int v>
struct IfPrint<false, v> {
	static void print() {}
};

template<int a, int n>
struct GetDigit {
	static const int result = (a / Pow10<n>::result) % 10;
};

template<int first, int second, int ...other>
struct CheckDigit {
	static const bool result = CheckDigit<first, second>::result && CheckDigit<first, other...>::result;
};

template<int first, int second>
struct CheckDigit<first, second> {
	static const bool result = (first != second && first != 0);
};

template<int first, int second, int ...other>
struct CheckDigitAll {
	static const bool result = CheckDigit<first, second, other...>::result && CheckDigitAll<second, other...>::result;
};

template<int first, int second>
struct CheckDigitAll<first, second> {
	static const bool result = CheckDigit<first, second>::result;
};

template<int a, int b, int c>
struct Check {
	static const int v0 = a * 100 + b * 10 + c, v1 = v0 * 2, v2 = v0 * 3;
	static const bool result = CheckDigitAll<GetDigit<v0, 2>::result, GetDigit<v0, 1>::result, GetDigit<v0, 0>::result,
		GetDigit<v1, 2>::result, GetDigit<v1, 1>::result, GetDigit<v1, 0>::result,
		GetDigit<v2, 2>::result, GetDigit<v2, 1>::result, GetDigit<v2, 0>::result>::result;
};

template<int a, int b, int c>
struct NumberEach3 {
	static inline void print() {
		IfPrint<Check<a, b, c>::result, a * 100 + b * 10 + c>::print();
		NumberEach3<a, b, c + 1>::print();
	}
};

template<int a, int b>
struct NumberEach3<a, b, 9> {
	static inline void print() {
		IfPrint<Check<a, b, 9>::result, a * 100 + b * 10 + 9>::print();
	}
};

template<int a, int b>
struct NumberEach2 {
	static inline void print() {
		NumberEach3<a, b, 1>::print();
		NumberEach2<a, b + 1>::print();
	}
};

template<int a>
struct NumberEach2<a, 9> {
	static inline void print() {
		NumberEach3<a, 9, 1>::print();
	}
};

template<int a>
struct NumberEach1 {
	static inline void print() {
		NumberEach2<a, 1>::print();
		NumberEach1<a + 1>::print();
	}
};

template<>
struct NumberEach1<3> {
	static inline void print() {
		NumberEach2<3, 1>::print();
	}
};

int main() {
	NumberEach1<1>::print();
	return 0;
}
