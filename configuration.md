# Configuration Guide for Keil µVision 5

This guide provides step-by-step instructions for configuring the STM32F401CCU6 microcontroller in **Keil µVision 5** without using STM32Cube HAL libraries. Instead, the project utilizes direct register-level programming.

---

## 🛠 **Setting Up Keil µVision 5 for STM32F401CCU6**

### Prerequisites
- Install **Keil µVision 5** from the official website.
- Download and install the **STM32F4 Device Support Pack** from Keil.
- Familiarize yourself with the STM32F401CCU6 **reference manual** and **datasheet** for register-level programming.

---

### **Step 1: Create a New Project**
1. Open Keil µVision 5.
2. Go to **Project > New µVision Project** and name your project.
3. From the device list, select **STM32F401CCU6**.

---

### **Step 2: Configure the Target**
1. Go to **Project > Options for Target** and configure the following:
   - **Device Tab:** Ensure the selected device is **STM32F401CCU6**.
   - **Target Tab:**
     - Set the **Clock Frequency** to **84 MHz** (system clock frequency for STM32F401).
   - Enable `Use MicroLIB` for reduced memory usage (optional).
   
2. **Output Tab:**
   - Set the output filename for the generated binary or hex file.

---

### **Step 3: Add CMSIS Core Files**
1. Open the **Manage Run-Time Environment** (RTE) tool.
2. Select the following components:
   - **CMSIS > Core**: This provides the basic core initialization for the Cortex-M4 processor.
   - **Device > Startup**: This includes the startup code for STM32F401CCU6.

3. These files will be automatically added to your project:
   - `system_stm32f4xx.c`
   - `startup_stm32f401xx.s`

---

### **Step 4: Add Your Source Code**
1. Create and add the following files to your project:
   - `main.c`
   - `gpio.c` (for GPIO configuration)
   - `i2c.c` (for I2C configuration)
   - `rtc.c` (for RTC configuration)
   - `display.c` (for OLED driver)
2. Include their corresponding header files in the project (e.g., `gpio.h`, `i2c.h`, etc.).

---

### **Step 5: Define Configuration for the Code**
The code provided uses direct register-level access. Below are some key configurations to match the given code:

#### **GPIO Configuration**
- Configure GPIO pins for I2C and display functionality.
- Use the **GPIOx_MODER**, **GPIOx_AFRL**, and **GPIOx_ODR** registers.

#### **I2C Configuration**
- Enable the I2C peripheral by setting bits in the **RCC_APB1ENR** register.
- Configure the I2C timing and address registers directly.

#### **RTC Configuration**
- Enable the RTC clock by configuring the **RCC_BDCR** register.
- Initialize the RTC peripheral registers directly.

#### **Clock Setup**
- Set the system clock to 84 MHz using the **RCC_PLLCFGR** and **RCC_CFGR** registers.

---

### **Step 6: Build and Flash the Project**
1. Build the project:
   - Go to **Project > Build Target**.
   - Ensure no errors in compilation.
   
2. Flash the firmware to your STM32F401CCU6 board:
   - Connect the board to your PC via ST-Link.
   - Go to **Flash > Download**.
   - Verify that the firmware is successfully flashed.

---

## 📝 **Code Notes**

Below is an example snippet of bare-metal programming code. Ensure your configuration aligns with these key functionalities:

