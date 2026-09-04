#include <iostream>
#include <ranges>
#include <vector>
void demo_transform(const std::vector<int>& nums)
{
	auto squared = nums | std::views::transform([](int x)
			{
				std::cout<<"Squaring "<< x; 
				return x*x;
			});

	for (int n : squared)
	{
		std::cout<< n<< std::endl;
	}	
}

int main()
{
	std::vector<int> v {1,2,3,4};
	demo_transform(v);
	return 0;
}
