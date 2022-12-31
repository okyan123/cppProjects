#include <ranges>
#include <algorithm>
#include <numeric>
export module calculate;

/// <summary>
/// 这个一个计算求和的函数，我在这里要测试一下几种不同的写法
/// </summary>
/// <param name="bottom">这是第一个参数，是求和的范围中的下界</param>
/// <param name="top">这是第二个参数，是求和的范围中的上界</param>
/// <returns>返回求和的结果</returns>
export int calculate1(int bottom, int top)
{
	if (bottom < top)
	{
		int sum = 0;
		for (int number = bottom; number <= top; number++)
		{
			if (number % 2 == 0)
			{
				sum += number;
			}
		}
		return sum;
	}
	else
	{
		return 0;
	}
}

/// <summary>
/// 在这个写法中，使用 c++ 20 标准库中新增的 std::views 中的函数，它可以生成一个视图,
/// 也就是通过 bottom 和 top 生成一个在此范围内的 range, 然后通过 range-for 便可以快速遍历它
/// </summary>
/// <param name="bottom">下界</param>
/// <param name="top">上界</param>
/// <returns>求和</returns>
export int calculate2(int bottom, int top)
{
	if (top > bottom)
	{
		int sum = 0;
		for (int number : std::views::iota(bottom, top + 1))
		{
			if (number % 2 == 0)
			{
				sum += number;
			}
		}
		return sum;
	}
	else
	{
		return 0;
	}
}

/// <summary>
/// 使用 std::views::filter 代替了 for 循环中的 if 判断,
/// 使用管道语法，从上一句 std::views::iota 生成的一个视图中，直接将结果传入，
/// 从而生成一个只有偶数的列表
/// </summary>
/// <param name="bottom">上界</param>
/// <param name="top">下界</param>
/// <returns>求和</returns>
export int calculate3(int bottom, int top)
{
	if (bottom < top)
	{
		int sum = 0;
		auto even = [](auto e) {return e % 2 == 0; };
		for (int number : std::views::iota(bottom, top + 1)
			| std::views::filter(even))
		{
			sum += number;
		}
		return sum;
	}
	else
	{
		return 0;
	}
}

/// <summary>
/// 在这里我使用了自 c++ 98 标准就引入的 accmulate 函数，它可以对一个容器进行求和操作，
/// 依次输入容器的迭代器和求和的初始值
/// </summary>
/// <param name="bottom">上界</param>
/// <param name="top">下界</param>
/// <returns>求和</returns>
export int calculate4(int bottom, int top)
{
	if (bottom < top)
	{
		auto even = [](auto e) {return e % 2 == 0; };
		auto evens = std::views::iota(bottom, top + 1)
			| std::views::filter(even);
		return std::accumulate(evens.begin(), evens.end(), 0);
	}
	else
	{
		return 0;
	}
}

/// 或许到了 c++23 标准，下面的代码就可以实现了，233。
//int calculate5(int bottom, int top)
//{
//	return top < bottom ? 0 :
//		ranges::accumulate(
//			std::views::iota(bottom, top + 1) |
//			std::views::filter([](auto e) {return e % 2 == 0; }),0);
//}