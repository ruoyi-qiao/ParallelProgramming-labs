import sys
# 比较两个文件的每一行，返回第一个不同的行。
def compare_files(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()

    diff_lines = []
    for line1, line2 in zip(lines1, lines2):
        if line1 != line2:
            diff_lines.append(f"Line {lines1.index(line1)+1}: {line1.strip()} != {line2.strip()}")
            break

    return diff_lines

def main():
    if len(sys.argv) != 3:
        print("Usage: python compare_files.py <file1> <file2>")
        return

    file1 = sys.argv[1]
    file2 = sys.argv[2]

    diff_lines = compare_files(file1, file2)

    if diff_lines:
        with open('result/diff.txt', 'w') as f:
            f.write('\n'.join(diff_lines))
        print("Files have differences. Differences saved in diff.txt.")
    else:
        print("Files are identical.")

if __name__ == '__main__':
    main()
