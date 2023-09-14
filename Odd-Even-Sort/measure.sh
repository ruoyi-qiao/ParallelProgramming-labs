mpiexec -np 1 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt &&
mpiexec -np 2 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt &&
mpiexec -np 3 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt &&
mpiexec -np 4 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt &&
mpiexec -np 5 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt &&
mpiexec -np 6 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt &&
mpiexec -np 7 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt &&
mpiexec -np 8 ./odd_even_sort && python3 diff.py result/out.txt result/stdout.txt