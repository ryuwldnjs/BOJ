#include <stdio.h>
#include <math.h>

int main() {
	const double pi = acos(-1.0);
	double radius, u_result, t_result;
	scanf("%lf", &radius);
	u_result = radius * radius * pi;
	t_result = 2 * radius * radius;
	printf("%.6lf\n", u_result);
	printf("%.6lf\n", t_result);
	return 0;
}