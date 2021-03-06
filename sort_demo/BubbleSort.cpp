#include<iostream>
#include<cmath>
#include<malloc.h>

using namespace std;
// 普通冒泡排序
void buddleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++) {
			//相邻元素，若逆序则交换（升序为左大于右，降序反之）
			if (arr[j] > arr[j+1])
			{
				//temp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = temp;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// 双向冒泡排序
void BidBuddleSort(int *arr, int len) {
	int low = 0; int high = len - 1;
	bool flag = true;
	while (low < high && flag) {
		flag = false;
		// 从左到右选最大的值
		for (int i = low; i < high; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
			flag = true;
		}
		high--;
		for (int j = high; j > low; j--)
		{
			if (arr[j] < arr[j-1])
			{
				swap(arr[j], arr[j - 1]);
			}
			flag = true;
		}
		low++;
	}
}
// 快速排序
void quickSort(int *arr, int low, int high) {
	// 开始默认基准为 low
	int i = low;
	int j = high;
	int key = arr[low];
	if (low < high)
	{
		while (i < j)
		{
			// 因为默认基准是从左边开始，所以从右边开始比较
			// 当队尾的元素大于等于基准数据 时,就一直向前挪动 j 指针
			while (i < j && arr[j] >= key)
			{
				j--;
			}

			// 当队首元素小于等于基准数据 时,就一直向后挪动 i 指针
			while (i < j && arr[i] <= key)
			{
				i++;
			}
			swap(arr[i], arr[j]);
		}
		swap(arr[low], arr[i]); //此时i=j
		// 递归调用排序
		// 左边排序
		quickSort(arr,low, i-1 );
		// 右边排序
		quickSort(arr, i + 1, high);
	}
}
// 直接插入排序
void InsertSort(int *arr, int len) {
	int i, j;
	if (arr == nullptr || len <= 0)
		return;
	for (i = 1; i <len; i++) //默认arr[0]是一个已经排好的子序列,依次将arr[1]到arr[n-1]插入子序列
	{
		if (arr[i] < arr[i-1]) { //若arr[i]的关键码小于前驱,将arr[i]插入有序表
			int temp = arr[i]; //复制为哨兵,temp不存放元素
			for (j = i-1; temp < arr[j]; --j) //从后往前查找待插入位置
			{
				arr[j + 1] = arr[j]; //向后挪位

			}
			arr[j + 1] = temp; // 复制到插入位置
		}
	}
}
// 折半插入排序
void halfDirInsertSort(int *arr, int len) {
	int i, j, low, high, mid;
	if (arr == nullptr || len <= 0) return;
	for (i = 1; i < len; i++)
	{
		low = 0; 
		high = i - 1;
		int temp = arr[i];
		while (low<=high)
		{
			mid = (low + high) / 2;
			if (arr[mid] > temp) //在左半部分找
			{
				high = mid - 1;
			}
			else                       //在右半部分找
			{
				low = mid + 1;
			}
		}

		for (j = i - 1; j>= high + 1; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = temp;
	}
}
// 希尔排序
void ShellSort(int *arr, int len) {
	int dk, i, temp, j;
	for (dk = len/2; dk >= 1; dk=dk/2) // 步长变化,如果步进初始化为dk=dk/3,则必须为dk=dk/3+1,当len<3时，gap为0，所以为了保证进入循环，gap至少为1
	{
		for (i = dk; i < len; ++i)
		{
			temp = arr[i];
			for (j = i - dk; j >=0 && temp < arr[j]; j=j-dk)
			{
				arr[j + dk] = arr[j];
			}
			arr[j + dk] = temp;
		}
	}
}

//选择排序
void SelectSort(int *arr, int len) {
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j =  i + 1; j < len; j++)
		{
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i)
		{
			swap(arr[i], arr[min]);
		}
	}
}

void HeadAdjust(int* arr, int k, int len) {
	// 函数HeadAdjust将元素k为根的子树进行调整
	int temp;
	temp = arr[k]; //先取出当前元素k
	for (int i = 2 * k + 1; i < len; i = 2 * i + 1) //从k结点的左子结点开始，也就是2k+1处开始
	{
		if (i + 1 < len && arr[i] < arr[i + 1]) { //如果左子结点小于右子结点，i指向右子结点
			i++;
		}
		if (arr[i] > temp) //如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
		{
			arr[k] = arr[i];
			k = i;
		}
		else
		{
			break;
		}
	}
	arr[k] = temp; //将temp值放到最终的位置
}
// 构建大根堆
void BuildMaxHeap(int *arr, int len) {
	for (int j = len / 2 - 1; j >= 0; j--) {
		HeadAdjust(arr, j, len);
	}
}

// 堆排序
void HeapSort(int *arr, int len) {
	BuildMaxHeap(arr, len);

	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		//重新对堆进行调整
		HeadAdjust(arr, 0, i); // 执行完的arr[0]是堆顶值，即当前堆中的最大值
	}
}

int *arr1 = (int*)malloc(13 * sizeof(int*));
//归并逻辑
void Merge(int* arr, int low, int mid, int high) {
	// 表arr的两段[low, mid] 和 [mid+1,high]各自有序,将它们合并为一个有序表
	int i, j, k;
	for ( k = low; k <= high; k++)
	{
		arr1[k] = arr[k]; // 将arr中的所有元素复制到arr1
	}
	for ( i = low,j=mid+1,k=i; i <=mid && j<=high; k++)
	{
		if (arr1[i] <= arr1[j]) { //比较arr1左右两段中的元素
			arr[k] = arr1[i++];
		}
		else
		{
			arr[k] = arr1[j++];
		}
	}
	while (i<=mid)
	{
		arr[k++] = arr1[i++]; // 若第一个表未检测完复制
	}
	while (j <= high)
	{
		arr[k++] = arr1[j++];
	}
}

// 2路归并排序
void MergeSort(int *arr, int low, int high) {
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}

/*********************************************************
Function:rxsort  csdn转载
Description:基数排序
Input:
	数组A[low,high]；
	数组中最大元素的位数d，例如最大数为999，则d为3；
	进制数k，如果是10进制数，k为10；
Output:排序好的数组；
Others：对数字1234来说，预定第0位为4，第1位为3，依次类推；
*********************************************************/
void rxsort(int *arr, int low, int high, int d, int k) {
	if (NULL==arr || low > high) // 
	{
		return;
	}

	int size = high - low + 1;
	int* counts = new int[k]; //用于基数排序的辅助数据，详见基数排序
	int* temp = new int[size];  //用于存储重新排序的数组
	int index, pval = 1;
	//依次处理不同的位
	for (int i = 0; i < d; i++)
	{
		//counts数组清零
		for (int j = 0; j < k; j++)
		{
			counts[j] = 0;
		}
		for (int j = low; j <= high; j++)
		{
			/*
            1.data[j]/pval：去掉数字data[j]的后i个数，例如：
            当data[j]=1234,i=2时，此时pval=100,data[j]/pval=12;
            2.(data[j]/pval)%k：取数字data[j]/pval的最后一位数
            3.(int)(data[j]/pval)%k:取数字data[j]的第i位数
            */
			index = (int)(arr[j] / pval) % k;
			/*
			统计数组A中每个数字的第i位数中各个数字的频数,用于计数排序；
			*/
			counts[index]++;
		}

		//计算累加频数，用户计数排序
		for (int j = 1; j < k; j++)
		{
			counts[j] = counts[j] + counts[j - 1];
		}


		//使用倒数第i+1位数对arr进行排序
		for (int j = high; j >= low; j--)
		{
			index = (int)(arr[j] / pval) % k;
			temp[counts[index] - 1] = arr[j];
			counts[index]--;
		}
		//将按第i为数排序后的结果保存回数组arr中
		for (int j = 0; j < size; j++)
		{
			arr[j + low] = temp[j];
		}
		//更新pval
		pval *= k;
	}
	delete[] counts;
	delete[] temp;
}


int main() {
	int buf[12] = {10,5,3,3,9,20,8,5,7,9,5,12};
	int len = sizeof(buf) / sizeof(buf[0]);
	int buf1[8] = { 53,17,78,9,45,65,87,32 };
	int len1 = sizeof(buf1) / sizeof(buf1[0]);
	int arr2[] = { 712,303,4,18,89,999,70,26 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	//buddleSort(buf, len);
	//BidBuddleSort(buf, len);
	//quickSort(buf, 0, len - 1);
	//InsertSort(buf, len);
	//halfDirInsertSort(buf, len);
	//ShellSort(buf, len);
	//SelectSort(buf, len);
	HeapSort(buf1, len1);
	MergeSort(buf, 0, len - 1);
	rxsort(arr2, 0, 7, 3, 10);
	for (int i = 0; i < sizeof(buf)/sizeof(buf[0]); i++)
	{
		cout << buf[i] << " ";
	}
	cout << endl;
	for (int j = 0; j < len1; j++)
	{
		cout << buf1[j] << " ";
	}
	cout << endl;

	for (int j = 0; j < len2; j++)
	{
		cout << arr2[j] << " ";
	}
	cout << endl;
	return 0;
}