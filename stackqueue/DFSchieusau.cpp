/*        A
        /   \
       B     C
      / \     \
     D   E     F */
Bước,Hành động,Trạng thái Stack (Đáy -> Đỉnh),Đã thăm (Kết quả duyệt)
Khởi tạo,Đưa đỉnh gốc A vào Stack.,[ A ],[]
1,"Lấy A ra. Đẩy C, rồi đẩy B vào.","[ C, B ]",[ A ]
2,"Lấy B ra. Đẩy E, rồi đẩy D vào.","[ C, E, D ]","[ A, B ]"
3,Lấy D ra. D không có con.,"[ C, E ]","[ A, B, D ]"
4,Lấy E ra. E không có con.,[ C ],"[ A, B, D, E ]"
5,Lấy C ra. Đẩy F vào.,[ F ],"[ A, B, D, E, C ]"
6,Lấy F ra. F không có con.,[ ] (Rỗng),"[ A, B, D, E, C, F ]"

bước hdong              stack         datham
ktao themA              [A]               []
1    layA,thêm B,C     [C,B]             [A]
2    layB,themD,E       [C,E,D]         [A,B]
3.   layD                [C,E]           [A,B,D]
4.   layE                [C]             [A,B,D,E]
5.   layC,themF           [F]             [A,B,D,E,C]
6.   layF                []              [A,B,D,E,C,F]
=> A-->B-->D-->E-->C-->F
