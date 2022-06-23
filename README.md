# Game Dò mìn _ Minesweeper
Làm game với SDL2

Chạy trên CodeBlock::

Cài đặt và chạy:
  
  1. Tải CodeBlock bản mingw mới nhất.


  2. Mở CodeBlock và tạo một project mới.


  3. Thêm các file .h, .cpp vào project.
  

  4. Thêm các thư SDL2, SD2_image, SDL2_ttf vào project.
      SDL2: https://www.libsdl.org/release/SDL2-devel-2.0.22-mingw.tar.gz
      SDL2_image: https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-mingw.tar.gz
      SDL2_ttf: https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.18-mingw.tar.gz
  


  5. Built and Run.

Cách chơi
	
	1. Nhấn PLAY

	2. Chọn Số lượng ô của chiều dài, chiều rộng và số quả mìn ẩn sau những ô vuông

	3. Người chơi khởi đầu với một bảng ô vuông trống thể hiện "bãi mìn".

	4. Click chuột vào một ô vuông trong bảng. Nếu không may trúng phải ô có mìn (điều này thường xảy ra với người mới chơi) thì trò chơi kết thúc. Trường hợp khác là ô đó không có mìn và một vùng các ô sẽ được mở ra cùng với những con số. Số trên một ô là lượng mìn trong 8 ô nằm quanh với ô đó.
	Nếu chắc chắn một ô có mìn, người chơi đánh dấu vào ô đó bằng hình lá cờ (click chuột phải).
	Note: Khi 8 ô lân cận trong một số đã có đủ số mìn mà vẫn còn các ô khác thì những ô đó không có mìn
	
	Trò chơi kết thúc với phần thắng dành cho người chơi nếu mở được tất cả các ô không có mìn.
	5. Sau khi  chơi xong có thể nhấn Play Again để chơi tiếp ván mới
	
