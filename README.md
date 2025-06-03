<<<<<<< HEAD
# C Programming and Windows Executable Analysis – From Source Code to Assembly

This repository showcases hands-on C development and low-level analysis of Windows executables. Each project demonstrates direct compilation with `gcc`, followed by disassembly and inspection.

## 🛠 Toolchain

- **GCC (MinGW-w64, UCRT)** – Native Windows compilation
- **Visual Studio Code** – Code editing and Git integration
- **C (ISO/ANSI standard)** – Low-level systems programming
- **IDA Free** – Interactive disassembly and control flow analysis
- **PEStudio** – Static PE file analysis and behavioral indicators
- **FLARE VM** – Malware analysis environment with built-in RE tools
- **PowerShell / Git Bash** – Build, run, and disassemble from the command line
=======
## 🔍 IDA Pro Analysis

This function shows how the compiled `main()` sets up the stack, loads the "Hello, world!" string, and uses `puts` and `getchar`.

![IDA Disassembly of main](ida_main.png)
>>>>>>> b08ffcb (Added README and screenshot)
