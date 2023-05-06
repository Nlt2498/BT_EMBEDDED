1. PHÂN VÙNG NHỚ

Có 5 phân vùng nhớ gồm: text, data, bss, heap, stack
  
  Phân vùng nhớ Text: 
 + Chỉ có quyền truy cập là Read
 + Nó chứa lệch để thực thi (instruction) 
 + Chứa khai báo hằng số  
 
  Phân vùng nhớ Data: 
 + Quyền truy cập: Read-Write
 + Chứa biến toàn cục hoặc biến Static với giá trị khởi tạo khác không
 + Được giải phóng khi kết thúc chương trình 
 
  Phân vùng nhớ Bss:
 + Quyền truy cập: Read-Write 
 + Chứa biến toàn cục hoặc biến Static với giá trị khởi tạo bằng không hoặc không khởi tạo.
 + Được giải phóng khi kết thúc chương trình 
  
  Phân vùng nhớ Stack:
 + Quyền truy cập: Read-Write
 + Sử dụng cấp phát cho biến cục bộ,các input parameter của hàm...
 + Được giải phóng khi ra khỏi block code/hàm

  Phân vùng nhớ Heap:
 + Quyền truy cập: Read-Write
 + Sử dụng để cấp phát bộ nhớ động: Malloc, Calloc..
 + Được giải phóng khi gọi hàm Free.
=========================================================================================

----- So sánh giữa Stack và Heap--------

Giống nhau: cả hai đều là vùng nhớ được tạo ra và lưu trữ trên RAM, có quyền truy cập là Read-Write

Khác nhau:
 + Stack lưu trữ biến cục bộ trong hàm, tham số truyền vào. Truy cập vào vùng nhớ này rất nhanh, được thực thi khi chương trình được biên dịch.
 + Heap lưu trữ cho những biến con trỏ được cấp phát động bởi hàm (Calloc, malloc).
 
Về kích thước vùng nhớ
 + Stack: kích thước là cố định, kích thước này có thể khác nhau tùy vào kiến trúc hệ điều hành. Do kích thước cố định nếu chương trình sử dụng quá nhiều vượt khả năng lưu trữ sẽ xảy ra tình trạng tràn bộ nhớ. 
 + Heap: Kích thước không cố định, có thể tăng giảm.

Về đặc điểm 
 + Stack: được quản lý bởi hệ điều hành, dữ liệu lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc. 
 + Heap: được quản lý bởi lập trình viên. dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong. Phải tự tay hủy vùng nhớ này bằng câu lệch Free. Nếu liên tục cấp phát liên tục không giải phóng sẽ bị lỗi tràn (Heap overflow).       
=========================================================================================

----- So sánh giữa DATA và BSS----------

Giống nhau: 
 + Cả hai đều là vùng nhớ được tạo ra và lưu trữ trên RAM. 
 + Đều có quyền truy cập là Read-Write
 + Cả hai đều chứa biến toàn cục và biến Static
 + Đều giải phóng khi kết thúc chương trình

Khác nhau: 
 + Đối với Data: Chứa biến toàn cục hoặc biến Static với giá trị khởi tạo khác không
 + Đối với Bss: Chứa biến toàn cục hoặc biến Static với giá trị khởi tạo bằng không hoặc không khởi tạo.
 + Giá trị mặc định các biến trong vùng Data phụ thuộc vào giá trị khởi tạo ban đầu, còn Bss giá trị mặc định cho các biến = 0.
=========================================================================================

2. STATIC

Biến Static cục bộ: 
 + Khi 1 biến cục bộ được khai báo với từ khóa Static. Biến sẽ chỉ khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. 
 + Giá trị nó không bị mất đi ngay cả khi kết thúc hàm. 
 + Khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ được gọi trong nội bộ hàm khởi tạo ra nó.
 + Giá trị của biến bằng giá trị tại lần gần nhất hàm được gọi

Biến Static toàn cục:
 + Chỉ có thể truy cập và sử dụng trong File khai báo nó, các file khác không truy cập được.
=========================================================================================

3. MARCO, FUNCTION

MARCO
 + Định nghĩa marco bằng lệch #define
 + Là tên bất kì (do lập trình viên đặt tên) trỏ tới 1 khối lệch thực hiện 1 chức năng nào đó.
 + Được xử lý trong quá trình tiền xử lý (Pre processor), thay thế đoạn code được khai báo marco vào chỗ nào xuất hiện marco đó.

Function
 + Là 1 khối lệch thực hiện một chức năng nào đó
 + Khi hàm được gọi, compiler sẽ lưu địa chỉ con trỏ chương trình PC hiện tại vào Stack pointer, chuyển con trỏ PC đến hàm được gọi, thực hiện hàm đó xong, lấy kết quả trả về. Sau đó quay lại Stack pointer lấy địa chỉ mà trước đó lưu, và thực hiện tiếp tục chương trình.

--------- So sánh giữa Marco với Function -------------

Marco  
 + Thay thế đoạn code marco vào chỗ được gọi trước khi biên dịch
 + Việc định nghĩa marco khó hơn định nghĩa hàm
 + Không thể debug tìm lỗi marco trong thời gian thực thi
 + Marco không quan tâm kiểu dữ liệu của tham số và kiểu trả về
 + Marco làm code trở nên dài hơn nhưng thời gian chạy nhanh

Function:
 + Hàm phải tạo một Function call, lưu địa chỉ trước khi gọi hàm vào stack pointer, trỏ con trỏ PC đến hàm được gọi, thực hiện hàm, quay về lấy địa chỉ trên Stack pointer đã lưu, thực hiện tiếp chương trình. 
 + Về định nghĩ đơn giản hơn
 + Debug đơn giản, dễ bắt lỗi
 + Phải chỉ rõ kiểu dữ liệu của tham số, giá trị trả về
 + Hàm sẽ phải gọi Function call nên tốn thời gian hơn, nhưng code ngắn gọn hơn.
=========================================================================================

4. STRUCT VÀ UNION
  
  Struct: là 1 kiểu dữ liệu người dùng tự định nghĩa cho phép lưu trữ các loại phần tử khác nhau
Vd: Quản lý sách trong thư viện gồm có thuộc tính sau (tiêu đề, tác giả, chủ đề, ID...)

  Union: là dữ liệu đặc biệt cho phép lưu trữ các kiểu dữ liệu khác nhau trong cùng 1 vùng nhớ. Có thể định nghĩa Union với rất nhiều tham số, nhưng chỉ 1 thành phần chứa giá trị tại một thời điểm. 

----------------So sánh Struct và Union --------------- 

 Giống nhau: Struct và Union là 2 cấu trúc dữ liệu do lập trình viên định nghĩa ra  
 
 Khác nhau:

Struct: 
 + Dữ liệu của các thành viên của struct được lưu ở vùng nhớ khác nhau 
 + Kích thước của 1 struct tối thiểu bằng kích thước các thành viên công lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)

Union: 
 + Dữ liệu các thành viên dùng chung 1 vùng nhớ 
 + Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union
 + Thay đổi nội dụng 1 thành viên sẽ dẫn đến thay đổi nội dụng các thành viên khác.
=========================================================================================

5. CON TRỎ 

 + Con trỏ cũng chỉ là biến, có thể khai báo, khởi tạo và lưu trữ giá trị và có địa chỉ của riêng nó. Nhưng biến con trỏ không lưu giá trị bình thường, nó là biến trỏ đến 1 địa chỉ khác, nên mang giá trị là 1 ĐỊA CHỈ.
 + Do lưu địa chỉ nên kích thước của các con trỏ như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính.
 
 --------- Con trỏ NULL ---------------
 + Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000, tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt cho biết không trỏ vào đâu cả
 + Khi khai báo con trỏ nên gán giá trị cho con trỏ, nếu chưa dùng đến ta gán cho con trỏ = NULL.
 + Trong các hàm nếu xử lý xong, không cần dùng con trỏ nữa thì gán về con trỏ NULL.

 -------- Con trỏ Void ---------------
+ Là một kiểu con trỏ đặc biệt, có thể trỏ đến các đối tượng của bất kỳ kiểu dữ liệu nào.
+ Chỉ có thể lưu địa chỉ, muốn lấy giá trị thì phải ép kiểu cho nó

-------- Pointer to Pointer (con trỏ cấp 2) -----------
+ Dùng để lưu địa chỉ của con trỏ khác

Vd: int a = 1; // Biến a có giá trị 5, giả sử có địa chỉ 0x01

int *ptr= &a; // con trỏ ptr lưu địa chỉ của biến a (Giá trị của ptr = 0x01, giả sử địa chỉ 0xc1)

int **p_ptr1= &ptr; //địa chỉ của con trỏ ptr lưu vào con trỏ p_ptr (Giá trị của p_ptr = 0xc1)
   
