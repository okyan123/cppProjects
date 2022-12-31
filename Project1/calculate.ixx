#include <ranges>
#include <algorithm>
#include <numeric>
export module calculate;

/// <summary>
/// ���һ��������͵ĺ�������������Ҫ����һ�¼��ֲ�ͬ��д��
/// </summary>
/// <param name="bottom">���ǵ�һ������������͵ķ�Χ�е��½�</param>
/// <param name="top">���ǵڶ�������������͵ķ�Χ�е��Ͻ�</param>
/// <returns>������͵Ľ��</returns>
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
/// �����д���У�ʹ�� c++ 20 ��׼���������� std::views �еĺ���������������һ����ͼ,
/// Ҳ����ͨ�� bottom �� top ����һ���ڴ˷�Χ�ڵ� range, Ȼ��ͨ�� range-for ����Կ��ٱ�����
/// </summary>
/// <param name="bottom">�½�</param>
/// <param name="top">�Ͻ�</param>
/// <returns>���</returns>
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
/// ʹ�� std::views::filter ������ for ѭ���е� if �ж�,
/// ʹ�ùܵ��﷨������һ�� std::views::iota ���ɵ�һ����ͼ�У�ֱ�ӽ�������룬
/// �Ӷ�����һ��ֻ��ż�����б�
/// </summary>
/// <param name="bottom">�Ͻ�</param>
/// <param name="top">�½�</param>
/// <returns>���</returns>
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
/// ��������ʹ������ c++ 98 ��׼������� accmulate �����������Զ�һ������������Ͳ�����
/// �������������ĵ���������͵ĳ�ʼֵ
/// </summary>
/// <param name="bottom">�Ͻ�</param>
/// <param name="top">�½�</param>
/// <returns>���</returns>
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

/// ������ c++23 ��׼������Ĵ���Ϳ���ʵ���ˣ�233��
//int calculate5(int bottom, int top)
//{
//	return top < bottom ? 0 :
//		ranges::accumulate(
//			std::views::iota(bottom, top + 1) |
//			std::views::filter([](auto e) {return e % 2 == 0; }),0);
//}