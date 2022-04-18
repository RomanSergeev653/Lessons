bool lm(int* arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] < arr[i + 1])
			return 0;
		if (arr[i] > arr[i + 1])
			return 1;
	}
	return 1;
}

bool check(bool low_more, int x, int y)
{
	if (low_more)// 0 - невозрастающая 1 - неубывающая
	{
		if (x < y)	return 1;
		else		return 0;
	}
	else
	{
		if (x > y)	return 1;
		else		return 0;
	}
}