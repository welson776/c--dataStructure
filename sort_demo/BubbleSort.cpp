#include<iostream>
#include<cmath>

using namespace std;
// ��ͨð������
void buddleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++) {
			//����Ԫ�أ��������򽻻�������Ϊ������ң�����֮��
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

// ˫��ð������
void BidBuddleSort(int *arr, int len) {
	int low = 0; int high = len - 1;
	bool flag = true;
	while (low < high && flag) {
		flag = false;
		// ������ѡ����ֵ
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
// ��������
void quickSort(int *arr, int low, int high) {
	// ��ʼĬ�ϻ�׼Ϊ low
	int i = low;
	int j = high;
	int key = arr[low];
	if (low < high)
	{
		while (i < j)
		{
			// ��ΪĬ�ϻ�׼�Ǵ���߿�ʼ�����Դ��ұ߿�ʼ�Ƚ�
			// ����β��Ԫ�ش��ڵ��ڻ�׼���� ʱ,��һֱ��ǰŲ�� j ָ��
			while (i < j && arr[j] >= key)
			{
				j--;
			}

			// ������Ԫ��С�ڵ��ڻ�׼���� ʱ,��һֱ���Ų�� i ָ��
			while (i < j && arr[i] <= key)
			{
				i++;
			}
			swap(arr[i], arr[j]);
		}
		swap(arr[low], arr[i]); //��ʱi=j
		// �ݹ��������
		// �������
		quickSort(arr,low, i-1 );
		// �ұ�����
		quickSort(arr, i + 1, high);
	}
}
// ֱ�Ӳ�������
void InsertSort(int *arr, int len) {
	int i, j;
	if (arr == nullptr || len <= 0)
		return;
	for (i = 1; i <len; i++) //Ĭ��arr[0]��һ���Ѿ��źõ�������,���ν�arr[1]��arr[n-1]����������
	{
		if (arr[i] < arr[i-1]) { //��arr[i]�Ĺؼ���С��ǰ��,��arr[i]���������
			int temp = arr[i]; //����Ϊ�ڱ�,temp�����Ԫ��
			for (j = i-1; temp < arr[j]; --j) //�Ӻ���ǰ���Ҵ�����λ��
			{
				arr[j + 1] = arr[j]; //���Ųλ

			}
			arr[j + 1] = temp; // ���Ƶ�����λ��
		}
	}
}
// �۰��������
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
			if (arr[mid] > temp) //����벿����
			{
				high = mid - 1;
			}
			else                       //���Ұ벿����
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
// ϣ������
void ShellSort(int *arr, int len) {
	int dk, i, temp, j;
	for (dk = len/2; dk >= 1; dk=dk/2) // �����仯,���������ʼ��Ϊdk=dk/3,�����Ϊdk=dk/3+1,��len<3ʱ��gapΪ0������Ϊ�˱�֤����ѭ����gap����Ϊ1
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

//ѡ������
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
	// ����HeadAdjust��Ԫ��kΪ�����������е���
	int temp;
	temp = arr[k]; //��ȡ����ǰԪ��k
	for (int i = 2 * k + 1; i < len; i = 2 * i + 1) //��k�������ӽ�㿪ʼ��Ҳ����2k+1����ʼ
	{
		if (i + 1 < len && arr[i] < arr[i + 1]) { //������ӽ��С�����ӽ�㣬iָ�����ӽ��
			i++;
		}
		if (arr[i] > temp) //����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
		{
			arr[k] = arr[i];
			k = i;
		}
		else
		{
			break;
		}
	}
	arr[k] = temp; //��tempֵ�ŵ����յ�λ��
}
// ���������
void BuildMaxHeap(int *arr, int len) {
	for (int j = len / 2 - 1; j >= 0; j--) {
		HeadAdjust(arr, j, len);
	}
}

// ������
void HeapSort(int *arr, int len) {
	BuildMaxHeap(arr, len);

	for (int i = len - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		//���¶Զѽ��е���
		HeadAdjust(arr, 0, i); // ִ�����arr[0]�ǶѶ�ֵ������ǰ���е����ֵ
	}
}

int main() {
	int buf[12] = {10,5,3,3,9,20,8,5,7,9,5,12};
	int len = sizeof(buf) / sizeof(buf[0]);
	int buf1[8] = { 53,17,78,9,45,65,87,32 };
	int len1 = sizeof(buf1) / sizeof(buf1[0]);
	//buddleSort(buf, len);
	//BidBuddleSort(buf, len);
	//quickSort(buf, 0, len - 1);
	//InsertSort(buf, len);
	//halfDirInsertSort(buf, len);
	//ShellSort(buf, len);
	SelectSort(buf, len);
	HeapSort(buf1, len1);
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
	return 0;
}