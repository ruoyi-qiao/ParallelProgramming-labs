int ComputePartner(int phase, int myid, int numprocs);
void merge_and_keep(int* local_data, int* partner_data, int* buffer, int size, bool is_left);
void serial_odd_even_sort(int *p,int num);
void internal_sort(int* local_data, int size);