#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

//这里以大根堆为例

//弹出元素的话，就是更新堆顶，进行push_down 操作
//插入元素的话，就是更新堆底，进行push_up   操作

//n表示完全二叉树的所有节点个数，i表示当前节点
void push_down(vector<int>& heap, int n, int i)
{
	//这里堆的根节点是从1开始的
	int max = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left < n && heap[left] > heap[max])
		max = left;
	if (right < n && heap[right] > heap[max])
		max = right;
	if (i != max)		//当前节点i不是最大值时交换
	{
		swap(heap[i], heap[max]);
		push_down(heap, n, max);
	}
}

//从树的倒数第二层第一个结点开始
void push_up(vector<int>& heap, int i)
{
	while (i / 2 && heap[i / 2] < heap[i])
	{
		swap(heap[i / 2], heap[i]);
		i /= 2;
	}
}

void heapSort(vector<int>& num, int n)
{
	int size = n;
	//1、建立大根堆
	for (int i = 1; i < n + 1; i++)
		push_up(num, i);

	//2、排序
	for (int i = 1; i < n + 1; i++)
	{
		swap(num[1], num[size]);		//交换最底部的到第一个位置
		size--;
		push_down(num, size, 1);
	}
}


int main()
{
	vector<int> num;
	int n;
	cin >> n;
	num.resize(n + 1);		//这里重新开辟一下空间

	for (int i = 1; i < n + 1; i++)
		cin >> num[i];

	heapSort(num, n);

	//这里堆的根节点是从1开始的
	for (int i = 1; i < n + 1; i++)
	{
		cout << num[i] << ' ';
	}
	cout << endl;

	return 0;
}