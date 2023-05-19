# Compiler
Compiler giống như 1 phần mềm dùng để chuyển ngôn ngữ bậc cao sang ngôn ngữ máy(ngôn ngữ bậc thấp), đối với một ngôn ngữ lập trình (c/c++,python,java,...) thì có nhiều compiler.
![image](https://github.com/Kiet2024/Embedded_interview/assets/133784431/21423361-d502-41ca-9a00-9ac64500703c)


Để tạo file *.i từ file *.c thì gõ "gcc -E *.c -o *.i".

Quá trình tiền xử lý (Preprocessor) xảy ra nó sẽ thay thế những đoạn chương trình Macro định nghĩa vào những đoạn chương trình đang gọi Macro, những phần command sẽ được bỏ qua.

Để tạo file Assembly code thì gõ "gcc *.i -S -o *.s".

Quá trình linker sẽ sắp xếp các object files + libraries vào file *.exe .

Bản chất file *.exe giống như file zip hay rar.
# Các toán tử logic
 ## Toán tử AND
 <img width="173" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/131b91c7-7404-42a1-89d4-00713f196a51">

 ## Toán tử OR
 <img width="173" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/e2779fd1-8884-4ab2-b2e9-fdaa875e1139">
 
 ## Toán tử NOT
 <img width="85" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/0d2bc1fd-1d6e-4067-8745-37b6efbd4714">

 ## Toán tử XOR
 <img width="175" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/28c77307-f094-4afa-b52e-925be353be09">
 
# Thao tác Bit
<img width="355" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/02e222c1-e668-4939-a6ea-dd05e7eb746e">

Dịch trái (<<) 4 bit là bỏ đi 4 bit bên trái(ở đầu) và thêm 4 bit 0 vào bên phải(ở cuối)

<img width="357" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/085599a0-6a96-4d58-b47a-507eb1705ee4">

Dịch phải(>>) 1 bit là bỏ đi 1 bit bên phải(ở cuối) và thêm 1 bit 0 vào bên trái(ở đầu)
 
