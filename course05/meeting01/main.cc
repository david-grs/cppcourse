#include <iostream>
#include <cstdint>

int main()
{
#if 0
	// bool, char <= unsigned char <= short <= int <= unsigned
	// int >= 2 bytes
	// "data model": int / long
	// float <= double

	// "fixed width" integers: they are not guaranteed to be defined
	std::int16_t i32;
	std::int64_t i64;
	std::int8_t c8;

	int i = i64;

	//std::int_fast32_t f32;
	//std::int_least32_t l32;

	int volume = calc_volume();
	volume -= 2;

	if (volume < 0)
		throw std::runtime_error();
#endif

	// int == signed int
	// long == signed long
	// char != signed char
	int sum = 0;
	for (unsigned char c = 0; c < 200; ++c)
		sum += c;
	std::cout << sum << std::endl;

	return 0;
}
