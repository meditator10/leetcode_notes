#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

/*
*	不稳定的排序算法
平均时间复杂度为：O( nlogn )	空间复杂度O(logn)
最差时间复杂度为：O( n^2 )		空间复杂度O(n)
*/
void quickSort1(vector<int>& num, int begin, int end) {
	//递归的结束标志，是数组长度为1或0，长度为1默认就是有序的
	//说明已经有序，直接返回
	if (begin >= end)
		return;

	int pivot = num[begin];		//pivot称为基准,一开始把基准定为起始位置
	int i = begin, j = end;

	while (i < j) {
		// 右指针元素比基准值大，说明num[j]不需要移动，直接跳过元素移动指针
		while (i < j && num[j] >= pivot) {
			j--;
		}
		if (i < j)
		{
			num[i] = num[j];	//若num[j] < pivot，元素前移，且i++
			i++;
		}
		// 左指针元素比基准值小，说明num[i]不需要移动，直接跳过元素移动指针
		while (i < j && num[i] <= pivot) {
			i++;
		}
		if (i < j)
		{
			num[j] = num[i];	//若num[i] > pivot，元素后置，且j--
			j--;
		}
			
	}

	num[i] = pivot;	//因为前面遍历完之后，i = j = 元素中间位置，所以把基准位置放到中间

	quickSort1(num, begin, i - 1);		//递归基准的前半部分
	quickSort1(num, i + 1, end);		//递归基准的后半部分
	//递归的结束标志，是数组长度为1，长度为1默认就是有序的
}


void quickSort2(vector<int>& num, int begin, int end) {
	//递归的结束标志，是数组长度为1或0，长度为1默认就是有序的
	//说明已经有序，直接返回
	if (begin >= end)
		return;

	int i = begin - 1, j = end + 1;		//这样定义i，j是方便后面使用就j--，i++
	int pivot = num[begin + end >> 1];		//pivot取中间值，也可以定义成从元素中随机取
	while (i < j)
	{
		do j--;
		while (num[j] > pivot);		//说明num[j]的位置是合理的，j--
		do i++;
		while (num[i] < pivot);		//说明num[i]的位置是合理的，i++

		if (i < j)				//走if语句,说明i < j,如果i>=j，走递归函数，自动退出while循环
		{
			swap(num[i], num[j]);	//num[i]，num[j]位置不合理，交换位置
		}
		else                    //自动退出while循环
		{
			quickSort2(num, begin, j);
			quickSort2(num, j + 1, end);
		}
	}
}

int main()
{
	vector<int> num = { 8,7,9,6,8,5 };

	quickSort1(num, 0, num.size() - 1);
	//quickSort2(num, 0, num.size() - 1);

	for (auto i : num) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

