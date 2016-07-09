#include <iostream>
using namespace std;

float f(float x, float y, float z) {
	float a = x * x + y * y + 9.0f / 4.0f * z * z - 1;
	return a * a * a - x * x * y * y * y - 9.0f / 80.0f  * y * y * y* z * z;
}


float h(float x, float y) {
	for (float z = 1.0f; z >= 0.0f; z -= 0.001f)
	if (f(x, y, z) <= 0)
		return z;
	return 0;
}

//笛卡尔心形线不适合此种阴影算法
int main() {
	
	for (float y = 1.5f; y > -1.5f; y -= 0.05f) {
		for (float x = -1.5f; x < 1.5f; x += 0.025f) {
			float v = f(x, y, 0);
			//这里指出最后一个0对目标并不影响
			if (v <= 0) {
				//说明属于心形函数内部部分
				float z = h(x, y);
				//至此，找出在x，y取一定数值下的z同样不影响心形的数值
				//===================================================
				float nx = h(x+0.01, y) - z;
				float ny = h(x, y+0.01) - z;
				//===================================================
				float nd = 1 / sqrtf(nx * nx + ny * ny + 0.01 * 0.01);
				//===================================================
				float d = (nx - ny + 0.01) * nd * 0.5 + 0.5;

				putchar(".:-=+*#"[(int)(d * 5.0f)]);
			}
			else
				putchar(' ');
		}
		putchar('\n');
	}
	
	/*
	for (float y = 1.5f; y > -1.5f; y -= 0.05f){
		for (float x = -1.5f; x < 1.5f; x += 0.025f){
			if (f(x,y,0) <= 0.0f)
				putchar('*');
			else
				putchar(' ');
		}
		cout << "\n";
	}
	*/
}