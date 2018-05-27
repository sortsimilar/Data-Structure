#include<iostream>
#include<vector>
using namespace std;

vector<int> sequence;


void max_heapify(int start, int end) 
{
	//建立父節點指標和子節點指標
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子節點指標在範圍內才做比較
		if (son + 1 <= end && sequence[son] < sequence[son + 1]) //先比較兩個子節點大小，選擇最大的
			son++;
		if (sequence[dad] > sequence[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
			return;
		else { //否則交換父子內容再繼續子節點和孫節點比較
			swap(sequence[dad], sequence[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int len) 
{
	//初始化，i從最後一個父節點開始調整
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(i, len - 1);
	//先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
	for (int i = len - 1; i > 0; i--) 
	{
		swap(sequence[0], sequence[i]);
		max_heapify(0, i - 1);
	}
}

int main() 
{

	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		sequence.push_back(temp);
	}


	heap_sort(N);
	for (int i = 0; i < N; i++)
	{
		cout << sequence[i] << " ";
	}
	cout << endl;
	return 0;
}

/*

10
3 1 2 8 7 5 9 4 6 0

*/

