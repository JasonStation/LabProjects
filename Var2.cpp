#include <stdio.h>

//2440051574

int main()
{
	int T;

	scanf("%d", &T);

	int x1[T], v1[T], x2[T], v2[T], secs[T], cond[T];

	for (int i = 0; i < T; ++i) {
		scanf("%d %d %d %d", &x1[i], &v1[i], &x2[i], &v2[i]);
		int dist1 = x1[i], dist2 = x2[i];
		secs[i] = 0;
		while (dist1 != dist2)
		{
			dist1 += v1[i];
			dist2 += v2[i];
			secs[i]++;
			if (secs[i] > 1000)
				cond[i] = 0;
		}
	}
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		if (cond[i] != 0)
			printf("Meet in %d s\n", secs[i]);
		else
			printf("IMPOSSIBLE!\n");
	}
}
