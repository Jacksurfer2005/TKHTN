# TKHTN

This project was done under the supervisor Nguyen Phan Hai Phu in coourse EE3003 - Embedded System Design.

# 🎮 BKONSOLE - Máy Chơi Game Cầm Tay Hệ Thống Nhúng

![Platform](https://img.shields.io/badge/Platform-ATmega328P-blue.svg)
![Language](https://img.shields.io/badge/Language-C-orange.svg)
![Hardware](https://img.shields.io/badge/Hardware-Altium_Designer-brightgreen.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

**BKONSOLE** là một thiết bị giải trí cầm tay tự thiết kế, xoay quanh nền tảng vi điều khiển ATmega328P. Dự án là sự kết hợp toàn diện giữa thiết kế phần cứng (Schematic & PCB), lập trình nhúng thời gian thực (Bare-metal C) và tối ưu hóa hệ thống năng lượng, mang lại trải nghiệm chơi game mượt mà trên ma trận LED.

<p align="center">
  <img src="Media/BKonsole Prototype.jpg" alt="BKONSOLE Thực Tế" width="80%">
  <br>
</p>

## 📑 Mục lục
- [Tính năng nổi bật](#-tính-năng-nổi-bật)
- [Cấu trúc Repository](#-cấu-trúc-repository)
- [Kiến trúc Phần cứng](#-kiến-trúc-phần-cứng)
  - [Thiết kế Mạch in (PCB Layout)](#-thiết-kế-mạch-in-pcb-layout)
- [Kiến trúc Phần mềm](#-kiến-trúc-phần-mềm)
- [Hướng dẫn Build và Nạp Code](#-hướng-dẫn-build-và-nạp-code)
- [Nhóm phát triển](#-nhóm-phát-triển-lớp-l04---nhóm-9)
---

## 🌟 Tính năng nổi bật

* **Tựa game cổ điển:** Trải nghiệm "Snake" (Rắn săn mồi) và "Pickle ball" (Hứng bóng) với logic game được tối ưu hóa.
* **Hệ thống hiển thị kép:**
    * **Màn hình Game:** Ma trận LED 8x8 điều khiển qua IC MAX7219 giao tiếp SPI tốc độ cao, đảm bảo không có hiện tượng bóng mờ (ghosting).
    * **Màn hình Thông tin:** LCD 1602 giao tiếp chế độ 4-bit, hiển thị menu, điểm số và trạng thái trực quan.
* **Quản lý Năng lượng:** Pin Li-Ion 3.7V tích hợp mạch sạc TP4056 (có bảo vệ) và mạch boost MT3608 nâng áp ổn định lên 5V cho toàn hệ thống.
* **Hệ thống Phản hồi:** Nút nhấn có chống dội (debounce) bằng phần mềm và còi chip (buzzer) báo hiệu âm thanh khi có sự kiện trong game.

---

## 📂 Cấu trúc Repository

Dự án được phân chia thành các module rõ ràng để dễ dàng tham khảo và phát triển tiếp:

```text
📦 TKHTN
 ┣ 📂 Docs              # Báo cáo đề tài (PDF), datasheet và lưu đồ thuật toán
 ┣ 📂 Firmware          # Mã nguồn C (Drivers, Game Logic, Main)
 ┃ ┣ 📂 inc             # Header files (.h)
 ┃ ┗ 📂 src             # Source files (.c)
 ┣ 📂 Hardware          # File thiết kế Altium Designer (Schematic, PCB, 3D) và file Gerber
 ┣ 📂 Media             # Hình ảnh sản phẩm, sơ đồ khối, ảnh GIF demo
 ┣ 📂 Simulation        # File mô phỏng Proteus
 ┗ 📜 README.md         # Tài liệu tổng quan dự án
```

### 📐 Thiết kế Mạch in (PCB Layout)

Quá trình thiết kế PCB được thực hiện và tối ưu hóa trên **Altium Designer**. Mạch được thiết kế 2 lớp (2 Layers) với các tiêu chuẩn cụ thể về độ rộng đường mạch (track width) cho đường nguồn và tín hiệu, đồng thời tối ưu hóa vị trí đặt linh kiện để giảm thiểu nhiễu cho tín hiệu SPI tốc độ cao.

<p align="center">
  <img src="Media/pcb_2d_routing.jpg" alt="PCB 2D Routing" width="45%">
  <img src="Media/pcb_3d_render.jpg" alt="PCB 3D Render" width="45%">
</p>
<p align="center">
  <em>Bản vẽ Layout 2D (trái) và Render 3D (phải) từ Altium Designer</em>
</p>

<p align="center">
  <img src="Media/pcb_thuc_te.jpg" alt="Bo mạch thực tế" width="80%">
</p>
<p align="center">
  <em>Bo mạch thực tế sau khi gia công và hàn hoàn thiện linh kiện</em>
</p>


### 💻 Kiến trúc Phần mềm
Mã nguồn được viết hoàn toàn bằng C (Bare-metal), biên dịch bằng trình dịch AVR-GCC. Cấu trúc chương trình tuân theo nguyên tắc phân lớp (Layered Architecture):

Hardware Abstraction Layer (HAL): Chứa các driver giao tiếp phần cứng (SPI, GPIO, PWM).

Device Drivers: Thư viện điều khiển MAX7219 và LCD1602 được viết lại để tối ưu dung lượng.

Application / Game Logic: Xử lý khung hình (framebuffer), máy trạng thái (state machine) của game và thuật toán va chạm.

<p align="center">
<img src="Media/luu_do_thuat_toan.jpg" alt="Algorithm Flowchart" width="60%">


<em>Lưu đồ thuật toán tổng quát của phần mềm</em>
</p>













