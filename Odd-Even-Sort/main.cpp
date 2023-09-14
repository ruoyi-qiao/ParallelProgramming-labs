#include <stdio.h>
#include <mpi.h>

void oddEvenSort(int* arr, int size, int rank, int numProcs) {
    int i, j;
    int temp;

    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            if (rank % 2 == 0) {
                if (rank < numProcs - 1) {
                    MPI_Send(&arr[size-1], 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
                    MPI_Recv(&temp, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    if (arr[size-1] > temp) {
                        arr[size] = temp;
                        arr[size-1] = arr[size];
                    }
                }
            }
            else {
                MPI_Recv(&temp, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                if (temp > arr[0]) {
                    arr[size] = temp;
                    arr[0] = arr[size];
                }
                MPI_Send(&arr[0], 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD);
            }
        }
        else {
            if (rank % 2 == 0) {
                MPI_Recv(&temp, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                if (temp > arr[0]) {
                    arr[size] = temp;
                    arr[0] = arr[size];
                }
                MPI_Send(&arr[0], 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD);
            }
            else {
                if (rank < numProcs - 1) {
                    MPI_Send(&arr[size-1], 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
                    MPI_Recv(&temp, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    if (arr[size-1] > temp) {
                        arr[size] = temp;
                        arr[size-1] = arr[size];
                    }
                }
            }
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }
}

int main(int argc, char** argv) {
    int rank, numProcs;
    int arr[] = {5, 2, 8, 3, 1, 9, 4, 7, 6}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcs);

    // Perform odd-even sort
    oddEvenSort(arr, size, rank, numProcs);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        MPI_Barrier(MPI_COMM_WORLD);
        if (rank == i % numProcs) {
            printf("Process %d: %d\n", rank, arr[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
