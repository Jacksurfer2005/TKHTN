# TKHTN

This project was done under the supervisor Nguyen Phan Hai Phu in coourse EE3003 - Embedded System Design.

# 🎮 BKONSOLE - Máy Chơi Game Cầm Tay Hệ Thống Nhúng

![Platform](https://img.shields.io/badge/Platform-ATmega328P-blue.svg)
![Language](https://img.shields.io/badge/Language-C-orange.svg)
![Hardware](https://img.shields.io/badge/Hardware-Altium_Designer-brightgreen.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

**BKONSOLE** là một thiết bị giải trí cầm tay tự thiết kế, xoay quanh nền tảng vi điều khiển ATmega328P. Dự án là sự kết hợp toàn diện giữa thiết kế phần cứng (Schematic & PCB), lập trình nhúng thời gian thực (Bare-metal C) và tối ưu hóa hệ thống năng lượng, mang lại trải nghiệm chơi game mượt mà trên ma trận LED.

<p align="center">
  <img src="Media/Bkonsole Prototype.jpg" alt="BKONSOLE Thực Tế" width="80%">
  <br>
</p>

## 📑 Mục lục
- [Tính năng nổi bật](#-tính-năng-nổi-bật)
- [Cấu trúc Repository](#-cấu-trúc-repository)
- [Kiến trúc Phần cứng](#-kiến-trúc-phần-cứng)
- [Kiến trúc Phần mềm](#-kiến-trúc-phần-mềm)
- [Hướng dẫn Build và Nạp Code](#-hướng-dẫn-build-và-nạp-code)
- [Nhóm phát triển](#-nhóm-phát-triển)

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
