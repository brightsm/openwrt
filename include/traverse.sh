#!/bin/bash

# 检查是否提供了足够的参数
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <directory_to_traverse> <output_file>"
    exit 1
fi

DIRECTORY=$1
OUTPUT_FILE=$2

# 清空或创建输出文件
> "$OUTPUT_FILE"

# 遍历目录并保存信息
traverse_directory() {
    local dir="$1"
    local output="$2"
    
    # 遍历当前目录及其子目录
    while IFS= read -r -d '' file; do
        if [ -d "$file" ]; then
            # 如果是目录，则记录目录信息
            echo "Directory: $file" >> "$output"
        elif [ -f "$file" ]; then
            # 如果是文件，则记录文件名和大小
            size=$(stat -c%s "$file")
            echo "File: $file, Size: ${size} bytes" >> "$output"
        fi
    done < <(find "$dir" -print0)
}

# 调用函数开始遍历
traverse_directory "$DIRECTORY" "$OUTPUT_FILE"

echo "Traversal completed. Results saved to $OUTPUT_FILE"
