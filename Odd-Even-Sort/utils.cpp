#include "utils.hpp"
#include <algorithm>
#include <mpi.h>

// 计算合作进程的编号
int ComputePartner(int phase, int myid, int numprocs) {
    int partner;
    if (phase % 2 == 0) {
        if (myid % 2 == 0) {
            partner = myid + 1;
		}
		else { 
			partner = myid - 1;
        }
    }
    else {
        if (myid % 2 == 0) {
            partner = myid - 1;
		}
		else {
			partner = myid + 1;
        }
    }
    // 越界处理 MPI_PROC_NULL表示不存在的进程
    if (partner == -1 || partner == numprocs) {
		partner = MPI_PROC_NULL;
	}
    return partner;
}
// 合并两个有序数组生成一个有序数组 序号小的保存前一半 序号大的保存后一半
void merge_and_keep(int* local_data, int* partner_data, int* buffer, int size, bool is_left) {
    int i = 0, j = 0, k = 0;
    while (i < size && j < size) { // 归并
        if (local_data[i] < partner_data[j]) buffer[k++] = local_data[i++];
        if (local_data[i] >= partner_data[j]) buffer[k++] = partner_data[j++];
    }
    while (i < size) buffer[k++] = local_data[i++];
    while (j < size) buffer[k++] = partner_data[j++];
    int bias = is_left ? 0 : size; // 保存前一半还是后一半
    for (int i = 0; i < size; i++)
        local_data[i] = buffer[i + bias];
}
// 串行奇偶排序
void serial_odd_even_sort(int *p,int num)
{
	bool sort = false;
	while (!sort)
	{
		sort = true;
		for (int i = 1; i < num; i+=2)
		{
			if (p[i] < p[i - 1]) {
                std::swap(p[i], p[i - 1]);
                sort = false;
			}
		}
		for (int i = 2; i < num; i += 2) {
			if (p[i] < p[i - 1]) {
                std::swap(p[i], p[i - 1]);
                sort = false;
            }
		}
	}
}
// 进程内部的排序
void internal_sort(int* local_data, int size) {
    serial_odd_even_sort(local_data, size);
}