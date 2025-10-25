#include <iostream>
#include <string>
#include <limits> // 用于 numeric_limits

int main() {
    std::cout << "程序开始运行。请输入两个整数（例如: 5 10），或输入 'q' 退出。\n";

    // 使用一个无限循环，直到用户输入 'q'
    while (true) {
        int num1, num2;
        
        // 尝试从标准输入流中读取两个整数
        if (std::cin >> num1 >> num2) {
            // 成功读取了两个整数
            long long sum = (long long)num1 + num2; // 使用 long long 避免可能的溢出
            std::cout << "两数之和为: " << sum << "\n";
            std::cout << "----------------------------------\n";
            std::cout << "请输入两个整数，或输入 'q' 退出：\n";
        } else {
            // 如果读取失败，说明用户可能输入了非数字字符（比如 'q' 或其他字母）
            
            // 1. 清除输入流的错误标志，例如 failbit
            std::cin.clear();
            
            // 2. 读取非数字输入。这里用一个 char 或 std::string 来接收
            std::string input_token;
            
            // 尝试读取一个“词”（token）
            if (std::cin >> input_token) {
                // 将读取到的内容转换为小写进行比较
                if (input_token == "q" || input_token == "Q") {
                    // 用户输入了 'q' 或 'Q'，退出循环
                    std::cout << "检测到 'q'，程序即将退出。\n";
                    break;
                } else {
                    // 用户输入的不是 'q'，也不是两个整数，可能是单个数字、多个非 'q' 字母等。
                    std::cout << "无效的输入！请输入 '两个整数' 或 'q'。\n";
                    std::cout << "----------------------------------\n";
                    std::cout << "请输入两个整数，或输入 'q' 退出：\n";
                    
                    // 由于输入错误，输入流中可能还残留了其他字符，
                    // 清理当前行的剩余部分，为下一次 cin >> 做准备。
                    // 忽略直到换行符（或文件结束符）的所有字符。
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } else {
                // 如果连一个 token 都无法读取（例如文件结束符EOF），则退出
                std::cout << "输入流结束，程序退出。\n";
                break;
            }
        }
    }

    std::cout << "程序已结束。\n";
    return 0;
}