#include <vector>
#include <algorithm>
#include <stdint.h>

class Solution {
public:
	long long maxPoints(std::vector<std::vector<int>> &points)
	{
		const int rows = points.size();
		const int cols = points[0].size();

		void	*base = calloc(sizeof(long long),
					sizeof(long long) * cols + 64 / sizeof(long long));
		if (!base)
			return (-1);
		long long *dp = (long long *)base;
		while ((intptr_t)dp % 64)
			dp++;
		for(int row = 0; row < rows - 1; row++)
		{
			dp[0] += points[row][0];
			for (int col = 1; col < cols; col++)
			{
				dp[col] = (dp[col] + + points[row][col] > dp[col - 1] - 1) ?
					dp[col] + points[row][col] : dp[col - 1] - 1;
			}

			for(int col = cols - 2; col >= 0; col--)
			{
				dp[col] = (dp[col] > dp[col + 1] - 1) ?
					dp[col] : dp[col + 1] - 1;
			}
		}
		long long max = dp[0] + points[rows - 1][0];
		for (int col = 1; col < cols; col++)
		{
			max = (max > dp[col] + points[rows - 1][col]) ?
				max : dp[col] + points[rows - 1][col];
		}
		free(base);
		return max;
	}
};

// for 20% more speed
auto init = []()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 'c';
}();