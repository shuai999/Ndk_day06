#include<stdio.h>  // 导入头文件，头文件都是方法的声明。
// 常用后缀: 以.h、.hpp结尾的，这两个里边都是方法的声明； 以.c(c语言)、.cpp(c++)结尾的，都是方法的实现；
// printf()、getchar()都是c语言的，但是都可以在 cpp中写，说明 在cpp中是可以写 c语言的代码

/*void main(){  // 函数主入口

	// c语言中的打印输出语句
	printf("Hello World");
	getchar(); // 停止
}*/


// 基本数据类型
/*void main(){

	short s = 100;
	int i = 100;
	long l = 100;

	float f = 200;
	double d = 200;

	char c = 'N';
	

	// 输出打印，需要用占位符打印

	// short: %d
	// int: %d
	// long：%ld：长整型的int
	
	// float：%f
	// double：%lf，l是 long

	// char字符：%c
	// 字符串：需要用 char*表示 
	
	printf("s的值为：%d\n", s);  // 100
	printf("i的值为：%d\n" , i); // 100
	printf("l的值为：%ld\n", l); // 100
	printf("f的值为：%f\n", f);  // 200.000000
	printf("d的值为：%lf\n", d); // 200.000000
	printf("c的值为：%c\n", c);  // N
	
	getchar();
}*/

// 变量的地址：任何的数据或者任何的变量都会有地址，这个地址就相当于我们生活中的住址和门牌号，因为 在 c和c++中操作的基本都是指针
/*void main(){

	int i = 100;
	// &: 表示取变量的地址
	// 通过 debug的调试：我们可以根据地址去查询 该地址对应的数据。
	// int类型是4字节，sizeof()：获取数据类型所占字节数
	printf("i的地址是：%p" , &i);
	getchar();
}*/

/*
void main(){

	printf("short 数据类型所占字节数：%d\n", sizeof(short));// 2
	printf("int 数据类型所占字节数：%d\n" , sizeof(int));  // 4
	printf("long 数据类型所占字节数：%d\n", sizeof(long));// 4
	printf("float 数据类型所占字节数：%d\n", sizeof(float));// 4
	printf("double 数据类型所占字节数：%d\n", sizeof(double));// 8
	printf("char 数据类型所占字节数：%d\n", sizeof(char)); // 1
	getchar();
	}*/

// 指针变量和获取地址的值
// 指针变量：就是用来接收 &i，这个地址的返回值
/*
void main(){
	int i = 100;
	double d = 200;

	printf("i的值为：%d\n" , i); // 100

	// 通过 *获取地址的值
	printf("i的值为：%d\n" , *(&i)); // 100, 首先获取i的地址&i，然后获取该地址对应的值 *(&i)

	// 指针变量，相当于地址变量：指针指向的就是变量地址或者存放的就是变量的地址

	// int* ：表示int类型的指针，或者int类型的地址，用于接收int类型的指针
	// p：是指针的变量
	int* p = &i;
	// 获取到i的地址后，再打印i的值：
	printf("i的值为：%d\n", *p); // 100， *p：表示对地址i去取值


	// double*：表示double类型的指针，或者double类型的地址，用于接收 double 类型的指针
	// double* pl = &d;
	getchar();
}*/

// 通过指针修改值
/*void main(){

	// 定义变量i
	int i = 100;
	// 获取i的地址，用指针变量 int* p来接收
	int* p = &i;

	// 方式1：直接给 i重新赋值
	i = 200;
	// 方式2：获取指针变量p的值，来间接修改
	// *p：表示变量p的值，来修改i的值
	*p = 300;

	printf("i的值为：%d\n", i);  // 300
	getchar();
}*/

// 在c中，调用顺序是从上往下执行，所以调用方法需要写到上边
// 通过方法修改值：通过打印可知：i的地址和change中的地址不是同一个，所以无法修改，这里可以通过地址来修改
/*void change(int i){
	printf("change中i的地址是：%p\n", &i);   // i的地址是：0019F894
	i = 200;
}*/

// 通过地址修改值：这里就需要把地址传递进来，用int* p来接收传递过来的地址
/*void change(int* p){
	printf("change中i的地址是：%p\n", p);// 这里的p已经是地址，可以直接打印
	*p = 200; // 通过 *p就可以获取 p地址的值，然后给其赋值为200
}

void main(){
	int i = 100;
	printf("i的地址是：%p\n", &i);  // i的地址是：0019F968
	printf("i的值为：%d\n" , i);
	// change(i);
	change(&i);
	printf("i修改后的值为：%d\n", i);  // 200
	getchar();
}*/

// 这里用 int类型的指针 int* 接收传递过来的两个地址，此时的 a和b已经是两个地址了
/*void change(int* a , int* b){
	int temp = *a;
	*a = *b; // 对a的地址取值 = 对b的地址取值 
	*b = temp;
}
void main(){
	int a = 100;
	int b = 200;

	// 交换：这里直接传递ab的地址
	change(&a , &b);
	printf("交互后ab的值分别是：%d,%d",a,b);  // 200 100

	getchar();
}*/

/*void main(){
	int a = 100;
	int b = 100;

	// a = b: 表示把b的值赋值给a
	printf("a,b的地址分别是：%p,%p\n" , &a , &b);  // a,b的地址分别是：0043F9C8,0043F9BC


	// 把a的地址赋值给 变量p1，把b的地址赋值给 变量p2
	// p1 = p2有点类似于 a=b，p1和p2只是一个变量而已
	int* p1 = &a;  
	int* p2 = &b;

	p1 = p2; // 这里只是把 p1变量的值修改了，并没有修改a的地址
	printf("a,b的地址分别是：%p,%p\n", &a, &b);   // a,b的地址分别是：0043F9C8,0043F9BC
	getchar();
}*/

/*void main(){
	int a = 100;
	int b = 200;

	// 交换
	a = a + b; // a = 100 + 200 = 300
	b = a - b; // b = 300 - 200 = 100 
	a = a - b; // a = 300 - 100 = 200 
	printf("交互后ab的值分别是：%d,%d", a, b);  // 200 , 100
	getchar();
}*/

