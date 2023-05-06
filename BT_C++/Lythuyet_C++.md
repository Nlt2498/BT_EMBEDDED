Tính đóng gói là một trong bốn tính chất cơ bản của lập trình hướng đối tượng. Tính đóng gói cho phép người lập trình ẩn các chi tiết bên trong của đối tượng, chỉ cho phép truy cập đến các thành phần của đối tượng thông qua các phương thức công khai được định nghĩa. Trong C++, đóng gói thường được thực hiện bằng cách khai báo các thuộc tính hoặc phương thức riêng tư (private) trong lớp. Những thành phần được khai báo riêng tư chỉ có thể truy cập bên trong lớp đó và không thể truy cập từ bên ngoài. Thay vào đó, người dùng chỉ có thể truy cập đến các phương thức công khai (public) để tương tác với đối tượng đó.

Ví dụ: trong lớp người, các thuộc tính như tên, địa chỉ và số điện thoại có thể được khai báo là riêng tư để tránh truy cập trực tiếp từ bên ngoài. Thay vào đó, các phương thức công khai như getTen(), getDiaChi() và getSoDienThoai() có thể được định nghĩa để cho phép người dùng truy cập các giá trị này thông qua chúng. Tính đóng gói trong C++ giúp tăng tính bảo mật và bảo vệ dữ liệu của đối tượng, cũng như giảm sự phụ thuộc và tăng tính module hóa trong mã nguồn.

Tính trừu tượng (abstraction) trong C++ là khả năng che giấu chi tiết bên trong của một đối tượng, chỉ hiển thị cho người dùng những phương thức và thuộc tính cần thiết để sử dụng đối tượng đó. Tính trừu tượng giúp tăng tính bảo mật, dễ bảo trì và dễ mở rộng của chương trình. C++ cung cấp nhiều cách để đạt được tính trừu tượng, bao gồm việc sử dụng lớp trừu tượng (abstract class) và các phương thức ảo (virtual methods), đồng thời cũng cung cấp cơ chế kế thừa đa hình để tăng tính linh hoạt trong việc sử dụng các đối tượng trừu tượng này.

Ví dụ: tính trừu tượng trong C++ có thể là một lớp trừu tượng (abstract class) đại diện cho một hình học đối tượng, nhưng không có triển khai cụ thể. Chẳng hạn, bạn có thể tạo một lớp hình học trừu tượng và khai báo các phương thức trừu tượng để đại diện cho các hoạt động hình học chung, chẳng hạn như tính diện tích, tính chu vi. Sau đó, bạn có thể tạo các lớp kế thừa từ lớp hình học trừu tượng này, chẳng hạn như hình vuông, hình tròn và hình chữ nhật, để triển khai các phương thức cụ thể của riêng từng loại hình học.

===================================================================================== ***************** SO SÁNH **************************

Tính đóng gói (encapsulation) và tính trừu tượng (abstraction) là hai khái niệm quan trọng trong lập trình hướng đối tượng

Đóng gói: Tính đóng gói là khả năng ẩn các chi tiết bên trong của đối tượng và chỉ cho phép truy cập đến chúng thông qua các phương thức công khai được định nghĩa. Mục đích của đóng gói là bảo vệ dữ liệu và giảm sự phụ thuộc giữa các thành phần của chương trình.

Trừu tượng: Tính trừu tượng là khả năng tách biệt các chi tiết cụ thể của đối tượng và chỉ quan tâm đến các tính chất trừu tượng của nó. Với tính trừu tượng, người lập trình chỉ cần quan tâm đến việc đối tượng thực hiện được gì, mà không cần biết cách nó được thực hiện.

Về mục đích: Mục đích của đóng gói là bảo vệ dữ liệu và giảm sự phụ thuộc giữa các thành phần của chương trình, trong khi mục đích của trừu tượng là giúp người lập trình tập trung vào các tính chất quan trọng của đối tượng mà không cần biết chi tiết cụ thể của nó.

Về cách thực hiện: Tính đóng gói được thực hiện bằng cách khai báo các thành phần riêng tư và công khai trong lớp, trong khi tính trừu tượng được thực hiện bằng cách sử dụng các lớp trừu tượng và các phương thức trừu tượng.

Liên quan đến kế thừa: Tính trừu tượng thường được sử dụng trong kế thừa để cho phép các lớp con triển khai các phương thức trừu tượng của lớp cha. Tuy nhiên, tính đóng gói không phải là một phần của kế thừa và có thể được sử dụng độc lập với kế thừa.
