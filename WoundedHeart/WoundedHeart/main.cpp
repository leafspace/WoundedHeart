#include <iostream>
using namespace std;
const float N = 1.5;
int main()
{
	for (float y = N / 3; y >= -N*2; y-=0.1){
		for (float x = -N * 3 / 2; x <= N * 3 / 2; x += 0.05){
			float r = sqrt(x*x + y*y);
			putchar(r <= N*(1 - y / r) ? "ILOVEYOU"[(int)rand()%8] : ' ');
		}
		cout << "\n";
	}
	return 0;
}































/*
const int N = 10;
int main()
{
int i, j;
for (i = -N; i <= N; i++){
for (j = 0; j < abs(i); j++){
cout << " ";
}
for (j = abs(i)-N; j <= N - abs(i); j++){
cout << "*";
}
cout << "\n";
}
return 0;
}
*/
/*笛卡尔心形线*/
/*
const int a = 10;
int main()
{
int y, x;
for (y = a / 4; y >= -2 * a; y--){
for (x = -(a * 5) / 2; x <= (a * 5) / 2; x++){
double r = sqrt(pow(x, 2) + pow(y, 2));
double t = y / r;
if (r <= a*(1 - t))
cout << "▇";
else
cout << " ";
}
cout << "\n";
}
return 0;
}
*/
/*曲率红心*/
/*
const float N = 1.5;
//其中N=[1.1，1.9]无明显变化,
int main() {
for (float y = N; y > -N; y -= 0.1) {
for (float x = -N; x < N; x += 0.05) {
float a = x * x + y * y - 1;
putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
}
putchar('\n');
}
return 0;
}
*/
/*笛卡尔心形线*/