
//итерационная функция

int func(int n) {
	int a = 1;
	int d = 3;
	int el = a + (n - 1) * d;
	return el;
}


// рекурсивная функция

int func(int n) {
	int a = 1;
	int d = 3;
	if (n == 1) {
		return a;
	}
	else {
		return func(n - 1) + d;
	}
}
