import random

def generate_data(file_path, num_elements):
    with open(file_path, 'w') as file:
        file.write(f"{num_elements}\n")
        for _ in range(num_elements):
            element = random.randint(0, 1e9)
            file.write(f"{element}\n")

def load_data(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        num_elements = int(lines[0])
        data = [int(line.strip()) for line in lines[1:]]
    return data

def sort_data(data):
    return sorted(data)

def write_sorted_data(sorted_data, file_path):
    with open(file_path, 'w') as file:
        for element in sorted_data:
            file.write(f"{element}\n")

# 文件路径和元素数量
file_path = 'result/in.txt'
sorted_file_path = 'result/stdout.txt'
num_elements = 100000

# 生成数据文件
generate_data(file_path, num_elements)
print(f"生成的数据已写入文件：{file_path}")

# 加载数据并进行排序
data = load_data(file_path)
sorted_data = sort_data(data)

# 将排序结果写入文件
write_sorted_data(sorted_data, sorted_file_path)
print(f"已排序的数据已写入文件：{sorted_file_path}")
